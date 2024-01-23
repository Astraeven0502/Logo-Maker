//
// Created by astraeven on 2022/4/2.
//

#include "InputBox.h"

InputBox::InputBox() {
    topItem.setString("top");
    topItem.setBoxSize({300, 60});
//    itemList.begin()->underneath(topItem);
}

void InputBox::setCharacterSize(const int& size) {
    topItem.setCharacterSize(size);
}

void InputBox::setString(const std::string& string) {
    topItem.setString(string);
}

void InputBox::setPosition(const sf::Vector2f &position) {
    topItem.setPosition(position);
}

void InputBox::setBoxSize(const sf::Vector2f &size) {
    topItem.setBoxSize(size);
}

Item InputBox::getItem() const {
    return topItem;
}

void InputBox::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(topItem);
//    window.draw(itemList);
}

void InputBox::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    topItem.addEventHandler(window, event);
//    itemList.addEventHandler(window, event);
}

void InputBox::update() {
    topItem.update();
//    itemList.update();
}
