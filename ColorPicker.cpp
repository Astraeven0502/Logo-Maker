//
// Created by astraeven on 2022/5/2.
//

#include "ColorPicker.h"

ColorPicker::ColorPicker() {
    colorMenu.setBoxSize({200,40});
    setPosition({0,0});
    colorMenu.setTopString("White");
    colorMenu.addItemList("Red");
    colorMenu.addItemList("Yellow");
    colorMenu.addItemList("Green");
    colorMenu.addItemList("Cyan");
    colorMenu.addItemList("Blue");
    colorMenu.addItemList("Magenta");
    colorMenu.addItemList("Black");
    colorMenu.addItemList("White");
    displayBox.setOutlineColor(sf::Color::White);
    displayBox.setOutlineThickness(2);
}

void ColorPicker::align() {
    displayBox.setSize({colorMenu.getBoxSize().y, colorMenu.getBoxSize().y});
    displayBox.setPosition(position.x - colorMenu.getBoxSize().y, position.y);
//    std::cout << currentColor.toInteger() << " " << hoverColor.toInteger() << std::endl;
//    std::cout << "Is hover" << colorMenu.isItemListHover() << std::endl;
//    std::cout << "Color:" << colorMenu.getCurrentSelection() << std::endl;
//    std::cout << "hover Color:" << colorMenu.getHoverString() << std::endl;
    displayBox.setFillColor(currentColor);

    if (colorMenu.getInputBox().getItem().checkState(States::ENABLE)){
        isDefault = false;
    }

    if (colorMenu.isItemListHover() && !isDefault) {
        displayBox.setFillColor(hoverColor);
    }


}

void ColorPicker::setPosition(const sf::Vector2f &position) {
    colorMenu.setPosition(position);
    this->position = position;
}

void ColorPicker::setBoxSize(const sf::Vector2f &size) {
    colorMenu.setBoxSize(size);
}

sf::Color ColorPicker::getMainColor() {
    if (colorMenu.getCurrentSelection() == "White"){
        currentColor = sf::Color::White;
    } else if (colorMenu.getCurrentSelection() == "Red"){
        currentColor = sf::Color::Red;
    } else if (colorMenu.getCurrentSelection() == "Yellow"){
        currentColor = sf::Color::Yellow;
    } else if (colorMenu.getCurrentSelection() == "Green"){
        currentColor = sf::Color::Green;
    } else if (colorMenu.getCurrentSelection() == "Cyan"){
        currentColor = sf::Color::Cyan;
    } else if (colorMenu.getCurrentSelection() == "Blue"){
        currentColor = sf::Color::Blue;
    } else if (colorMenu.getCurrentSelection() == "Magenta"){
        currentColor = sf::Color::Magenta;
    } else if (colorMenu.getCurrentSelection() == "Black"){
        currentColor = sf::Color::Black;
    }
    return currentColor;
}

sf::Color ColorPicker::getHoverColor() {
    if (colorMenu.getHoverString() == "White"){
        hoverColor = sf::Color::White;
    } else if (colorMenu.getHoverString() == "Red"){
        hoverColor = sf::Color::Red;
    } else if (colorMenu.getHoverString() == "Yellow"){
        hoverColor = sf::Color::Yellow;
    } else if (colorMenu.getHoverString() == "Green"){
        hoverColor = sf::Color::Green;
    } else if (colorMenu.getHoverString() == "Cyan"){
        hoverColor = sf::Color::Cyan;
    } else if (colorMenu.getHoverString() == "Blue"){
        hoverColor = sf::Color::Blue;
    } else if (colorMenu.getHoverString() == "Magenta"){
        hoverColor = sf::Color::Magenta;
    } else if (colorMenu.getHoverString() == "Black"){
        hoverColor = sf::Color::Black;
    }
    return hoverColor;
}

void ColorPicker::setDefault(sf::Color color) {
    isDefault = true;
    if (color == sf::Color::White) {
        colorMenu.setTopString("White");
    } else if (color == sf::Color::Red) {
        colorMenu.setTopString("Red");
    } else if (color == sf::Color::Yellow) {
        colorMenu.setTopString("Yellow");
    } else if (color == sf::Color::Green) {
        colorMenu.setTopString("Green");
    } else if (color == sf::Color::Cyan) {
        colorMenu.setTopString("Cyan");
    } else if (color == sf::Color::Blue) {
        colorMenu.setTopString("Blue");
    } else if (color == sf::Color::Magenta) {
        colorMenu.setTopString("Magenta");
    } else if (color == sf::Color::Black) {
        colorMenu.setTopString("Black");
    }
}

void ColorPicker::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(colorMenu);
    window.draw(displayBox);
}

void ColorPicker::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    colorMenu.addEventHandler(window, event);
}

void ColorPicker::update() {
    getMainColor();
    getHoverColor();
    align();
    colorMenu.update();
}
