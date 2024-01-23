//
// Created by astraeven on 2022/4/28.
//

#include "FileTree.h"

void FileTree::push(FileNode *&root, std::string parent, std::string item) {
    bool tempBool = false;
    if (this->root == nullptr){
        FileNode *temp = new FileNode({FOLDERPNG, "trash", {300,60}, {-1000,-1000}});
        this->root = temp;
        tempBool = true;
        std::cout << "here" << std::endl;
    }
    if (root->getData().getString() == parent || tempBool){
        if (item.find('.') != std::string::npos)
            root->getChildren().push_back(new FileNode({FILEPNG, item, {300,60}, {initPosition.x, initPosition.y}}));
        else
            root->getChildren().push_back(new FileNode({FOLDERPNG, item, {300,60}, {initPosition.x, initPosition.y}}));
        std::cout << "here1" << std::endl;
        initPosition.x = -1000;
        initPosition.y = -1000;
    }
//    if (root->getData().getString() == parent || tempBool){
//        if (item.substr(0,4) == "File")
//            root->getChildren().push_back(new FileNode({FILEPNG, item, {300,60}, {initPosition.x, initPosition.y}}));
//        else
//            root->getChildren().push_back(new FileNode({FOLDERPNG, item, {300,60}, {initPosition.x, initPosition.y}}));
//        std::cout << "here1" << std::endl;
//        initPosition.x = -1000;
//        initPosition.y = -1000;
//    }
    else {
        for (int i = 0; i < root->getChildren().size(); ++i) {
            std::cout << "here2 " << i << std::endl;
//                if (root->getChildren()[i]->getData().getString() == parent)
            push(root->getChildren()[i], parent, item);
//                else
//                    push(root->getChildren()[i], parent, item);
        }
    }
}

void FileTree::traverse_event(FileNode *&root, sf::RenderWindow &window, sf::Event event) {
    if (root == nullptr)
    {
        return;
    }
    FileNode *temp = nullptr;
//    std::cout << "  " << root->getData().getString();
    root->getData().addEventHandler(window, event);
    for (int i = 0; i < root->getChildren().size(); ++i) {
        temp = root->getChildren()[i];
        this->traverse_event(temp, window, event);
    }
}

void FileTree::traverse_update(FileNode *&root) {
    if (root == nullptr)
    {
        return;
    }
    FileNode *temp = nullptr;
//    std::cout << "  " << root->getData().getString();
    root->getData().update();
    for (int i = 0; i < root->getChildren().size(); ++i) {
        temp = root->getChildren()[i];
//        std::cout << root->getString() << ":: children string: " << root->getChildren()[i]->getString() << std::endl;
        this->traverse_update(temp);
    }
}

FileTree::FileTree() {

}

void FileTree::push(std::string parent, std::string item) {
    push(root, parent, item);
}

void FileTree::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    if (root != nullptr){
        root->getData().draw(window, states);
        for (int i = 0; i < root->getChildren().size(); ++i) {
            root->getChildren()[i]->draw(window, states);
        }
    }
}
//does nothing now
void FileTree::applySnapshot(const Snapshot &snapshot) {

}

void FileTree::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if (root != nullptr)
        traverse_event(root, window, event);
}
//does nothing now
void FileTree::update() {
    updateSelectedString(root);
    if (root != nullptr)
        traverse_update(root);
}
//does nothing now
Snapshot &FileTree::getSnapshot() {
    Snapshot temp;
    return temp;
}
//does nothing now
sf::FloatRect FileTree::getGlobalBounds() {
    sf::FloatRect temp;
    return temp;
}

void FileTree::printTree() {
    printTree(root);
}

void FileTree::printTree(FileNode *&root) {
    if (root == nullptr)
    {
        return;
    }
    FileNode *temp = nullptr;
    std::cout  << root->getData().getString()<< "  " ;
    for (int i = 0; i < root->getChildren().size(); ++i) {
        temp = root->getChildren()[i];
        printTree(temp);
    }
}

//std::string FileTree::getSelectedString() {
//    std::string string;
//    string = getSelectedString(root);
////    std::cout << "HEGRERER" << getSelectedString(root) << std::endl;
//    return string;
//}

//std::string FileTree::getSelectedString(FileNode *root) {
//    if (root == nullptr)
//    {
//        return "nothing";
//    }
//
//    if (root->getData().checkState(SELECTED)){
//        if (fileDirectory.size() > root->getString().size()){
//            if (fileDirectory.substr(fileDirectory.size() - root->getString().size()) != root->getString()){
//                fileDirectory = fileDirectory + "/" + root->getString();
//            }
//        } else{
//            fileDirectory = fileDirectory + "/" + root->getString();
//        }
//
////        std::cout << fileDirectory.substr(fileDirectory.size() - root->getString().size()) << std::endl;
//        std::cout << root->getString().size() << std::endl;
//        return root->getString();
//    }
//
//    FileNode *temp = nullptr;
//    for (int i = 0; i < root->getChildren().size(); ++i) {
//        temp = root->getChildren()[i];
//        getSelectedString(temp);
//    }
//    std::cout << fileDirectory << std::endl;
//    return fileDirectory;
//}

void FileTree::getSelectedPath(FileNode *&root) {

    if (root == nullptr)
    {
        return;
    }
    FileNode *temp = nullptr;

    fileDirectory.push_back(root->getData().getString());

    for (int i = 0; i < root->getChildren().size(); ++i) {
        temp = root->getChildren()[i];
        getSelectedPath(temp);
        if (!root->getData().checkState(SELECTED) && root->getChildren().empty()){
            fileDirectory.pop_back();
        }
    }

}

std::vector<std::string> FileTree::getSelectedPath() {
//    getSelectedPath(root);
//    for (int i = 0; i < fileDirectory.size(); ++i) {
//        std::cout << fileDirectory[i] << " ";
//    }
    std::cout << root->getChildren()[0]->getChildren()[0]->getString() << " ";
//    std::cout << selectedString << std::endl;
    return fileDirectory;
}

void FileTree::updateSelectedString(FileNode *&root) {
    if (root == nullptr)
    {
        return;
    }
    FileNode *temp = nullptr;

    if (root->getData().checkState(SELECTED))
        selectedString = root->getData().getString();

    for (int i = 0; i < root->getChildren().size(); ++i) {
        temp = root->getChildren()[i];
        updateSelectedString(temp);
    }
}
