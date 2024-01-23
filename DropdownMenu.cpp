//
// Created by astraeven on 2022/4/2.
//

#include "DropdownMenu.h"

DropdownMenu::DropdownMenu() {

}

void DropdownMenu::align() {
    if (!itemList.empty())
        itemList.begin()->underneath(inputBox.getItem());
}

void DropdownMenu::setCharacterSize(const int &size) {
    inputBox.setCharacterSize(size);
    itemList.setCharacterSize(size);
}

void DropdownMenu::setTopString(const std::string &string) {
    inputBox.setString(string);
}

void DropdownMenu::setPosition(const sf::Vector2f &position) {
    inputBox.setPosition(position);
}

void DropdownMenu::setBoxSize(const sf::Vector2f &size) {
    inputBox.setBoxSize(size);
    itemList.setBoxSize(size);
    this->size = size;
}

void DropdownMenu::setMainBoxColor(sf::Color color) {
    inputBox.getItem().setBoxColor(color);
}

void DropdownMenu::addItemList(std::string string) {
    Item item;
    item.setBoxSize(size);
    item.setString(string);
    itemList.pushItem(item);
}

void DropdownMenu::addItemColor(sf::Color color) {
    Item item;
    item.setBoxSize(size);
    item.setBoxColor(color);
    item.setString("");
    itemList.pushItem(item);
}

void DropdownMenu::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    if (inputBox.getItem().checkState(ENABLE))
        window.draw(itemList);

    window.draw(inputBox);
}

void DropdownMenu::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if (itemList.checkItemList()){
        HistoryNode tempHisNode;

        tempHisNode.snapshot = getSnapshot();
        tempHisNode.component = this;

        History::pushHistory(tempHisNode);


        inputBox.setString(itemList.getEnableItemString());
    }

    if (KeyShortcuts::isUndo() && History::historyAmount() > 0 && event.type == sf::Event::KeyPressed) {
        if (History::topHistory().component == this) {
            applySnapshot(History::topHistory().snapshot);
            History::popHistory();
            std::cout << History::historyAmount() << std::endl;
        }
    }

    if (inputBox.getItem().checkState(ENABLE)) {
        isInputBoxChange = true;
    }
    if (isInputBoxChange){
        itemList.addEventHandler(window, event);
        isInputBoxChange = false;
    }
    inputBox.addEventHandler(window, event);
}

void DropdownMenu::update() {
    inputBox.update();
    itemList.update();
    align();
}


Snapshot &DropdownMenu::getSnapshot() {
    snapshot1.storeSnapshot(inputBox.getItem().getString());
    std::cout << inputBox.getItem().getString()  << std::endl;
    return snapshot1;
}


void DropdownMenu::applySnapshot(const Snapshot &snapshot) {
    inputBox.setString(snapshot.getString());
}

std::string DropdownMenu::getCurrentSelection() {
    return inputBox.getItem().getString();
}

sf::Color DropdownMenu::getMainBoxColor() {
    return inputBox.getItem().getColor();
}

sf::Vector2f DropdownMenu::getBoxSize() {
    return size;
}

std::string DropdownMenu::getHoverString() {
    return itemList.getHoverItemString();
}

bool DropdownMenu::isItemListHover() {
    return itemList.isItemListHover();\
}

InputBox DropdownMenu::getInputBox() {
    return inputBox;
}
