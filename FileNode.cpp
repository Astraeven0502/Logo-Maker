//
// Created by astraeven on 2022/4/28.
//

#include "FileNode.h"

void FileNode::toggleChildren() {

}

void FileNode::reposition() const {
    if (!children.empty())
        children[0]->getData().setPosition({data.getPosition().x + 30, data.getGlobalBounds().top + data.getGlobalBounds().height});
    for (int i = 1; i < children.size(); i++) {
        children[i]->getData().setPosition({children[i-1]->getData().getGlobalBounds().left, children[i-1]->getData().getGlobalBounds().top + children[i-1]->getData().getGlobalBounds().height});
    }

    for (int i = 0; i < children.size(); ++i) {
        if (children[i]->getData().checkState(ENABLE)){
            int j = i+1;
//                std::cout << j;
            if (!children[i]->getChildren().empty() && j < children.size()){
                children[j]->getData().setPosition({children[j]->getData().getPosition().x
                                                           , children[i]->getChildren()[children[i]->getChildren().size()-1]->getGlobalBounds().height + children[i]->getChildren()[children[i]->getChildren().size()-1]->getGlobalBounds().top});
//                    children[j]->getData().setPosition({children[i]->getData().getPosition().x
//                                   , children[i]->getChildren()[children[i]->getChildren().size()-1]->getGlobalBounds().top + children[i]->getChildren()[children[i]->getChildren().size()-1]->getGlobalBounds().height});
            }

        }
    }
}

FileNode::FileNode() : FileNode(FOLDERPNG, "TEST", {300, 60}, {100,100}){

}

FileNode::FileNode(ImageNames icon, std::string text, sf::Vector2f size, sf::Vector2f position) {
    data.setIcon(icon);
    data.setString(text);
    data.setBoxSize(size);
    data.setPosition(position);
}

void FileNode::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    reposition();
    window.draw(data);
    if (data.checkState(ENABLE)){
        for (auto & i : children) {
            i->draw(window, states);
        }
    }
}

//This is not currently used
void FileNode::applySnapshot(const Snapshot &snapshot) {

}

void FileNode::addEventHandler(sf::RenderWindow &window, sf::Event event) {
//    for (iterator iter = begin(); iter != end(); ++iter) {
//        int i = 0;
//        for (iterator iter = begin(); iter != end(); iter++) {
//            iter[i]->addEventHandler(window, event);
//            i++;
//        }
//    }
    data.addEventHandler(window, event);
    for (auto & i : children) {
        i->addEventHandler(window, event);
    }
    if (data.checkState(ENABLE)){
        toggleChildren();
    }
}

//does nothing
void FileNode::update() {
    reposition();
    data.update();
    for (auto & i : children) {
        i->update();
    }
    if (!data.checkState(ENABLE)){
        for (auto & i : children) {
            i->enableState(DISABLED);
            i->disableState(ENABLE);
        }
    }
}

void FileNode::setString(std::string text) {
    data.setString(text);
}

std::string FileNode::getString() {
    return data.getString();
}

//does nothing
Snapshot &FileNode::getSnapshot() {
    Snapshot temp;
    return temp;
}

//does nothing
sf::FloatRect FileNode::getGlobalBounds() {
    return data.getGlobalBounds();
}

bool FileNode::isLeaf() const {
    return children.empty();
}

FileItem &FileNode::getData() {
    return data;
}

void FileNode::setData(const FileItem &data) {
    this->data = data;
}

std::vector<FileNode*> &FileNode::getChildren() {
    return children;
}

FileNode::iterator FileNode::begin() {
    return children.begin();
}

FileNode::iterator FileNode::end() {
    return children.end();
}
