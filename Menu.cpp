//
// Created by astra on 2022/4/21.
//

#include "Menu.h"

Menu::Menu() {

}

void Menu::align() {
    if (!itemList.empty())
        itemList.begin()->underneath(topItem);
}

void Menu::setCharacterSize(const int &size) {
    topItem.setCharacterSize(size);
    itemList.setCharacterSize(size);
}

void Menu::setTopString(const std::string &string) {
    topItem.setString(string);
}

void Menu::setPosition(const sf::Vector2f &position) {
    topItem.setPosition(position);
}

void Menu::setTopBoxSize(const sf::Vector2f &size) {
    topItem.setBoxSize(size);
}

void Menu::setListBoxSize(const sf::Vector2f &size) {
    itemList.setBoxSize(size);
}

void Menu::addItemList(std::string string) {
    Item item;
    item.setBoxSize(topItem.getBoxSize());
    item.setCharacterSize(topItem.getCharacterSize());
    item.setString(string);
    itemList.pushItem(item);
}

void Menu::toTheRight(Menu &menu) {
    menu.topItem.toTheRight(topItem);
}

void Menu::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(topItem);
    if (topItem.checkState(States::ENABLE)){
        window.draw(itemList);
    }
}

void Menu::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if (topItem.checkState(States::ENABLE)) {
        isTopItemEnable = true;
    }
    if (isTopItemEnable){
        itemList.addEventHandler(window, event);
        isTopItemEnable = false;
    }
    if (topItem.checkState(States::DISABLED)){
        for (auto iter = itemList.begin(); iter != itemList.end() ; iter++) {
            iter->enableState(States::DISABLED);
            iter->disableState(States::ENABLE);
        }
    }
    topItem.addEventHandler(window, event);
}

void Menu::update() {
    topItem.update();
    itemList.update();
    align();
}

std::string Menu::getEnableItemString() {
    return itemList.getEnableItemString_menuBar();
}
