//
// Created by astraeven on 2022/4/2.
//

#include "Item.h"

Item::Item() {
    enableState(DISABLED);
    disableState(ENABLE);
    text.setFont(Fonts::getFont(OPENSANSBOLD));

    box.setSize({300, 60});
    box.setFillColor(sf::Color::Black);
    box.setOutlineThickness(1);
    box.setOutlineColor(sf::Color::White);
    box.setPosition({0,0});

    text.setCharacterSize(40);
    text.setString("Test");
    center();
}

void Item::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(box);
    window.draw(text);
}

void Item::center() {
//    sf::Text temp;
//    temp.setFont(Fonts::getFont(OPENSANSBOLD));
//    temp.setCharacterSize(text.getCharacterSize());
//    temp.setPosition(text.getPosition());
//    temp.setString(text.getString());
//    text.setOrigin(temp.getOrigin());

//    sf::FloatRect bBounds = box.getGlobalBounds();
//    sf::FloatRect tBounds = text.getGlobalBounds();
//
//    text.setOrigin(tBounds.left + tBounds.width/2, tBounds.top + tBounds.height/2);
//    text.setPosition(bBounds.left + bBounds.width/2, bBounds.top + bBounds.height/2);

    sf::FloatRect bBounds = box.getGlobalBounds();
    text.setPosition(bBounds.left, bBounds.top);
    sf::FloatRect tBounds = text.getGlobalBounds();

    text.setPosition(bBounds.left + (bBounds.width-tBounds.width)/2
                     , bBounds.top + (bBounds.height-tBounds.height)/2-13);
//    text.setPosition(bBounds.left + ((bBounds.left+bBounds.width) - (tBounds.left+tBounds.width))
//                     , bBounds.top + ((bBounds.top+bBounds.height) - (tBounds.top+tBounds.height)));
}

bool Item::hover(sf::RenderWindow &window, sf::Event event) {


    if(MouseEvents<sf::RectangleShape>::hovered(box, window))
    {
        enableState(HOVERED);
        disableState(NORMAL);
        return true;
    }
    else
    {
        enableState(NORMAL);
        disableState(HOVERED);
        return false;
    }
}

void Item::disable(sf::RenderWindow& window, sf::Event event) {
    if (!MouseEvents<sf::RectangleShape>::mouseClicked(box, window) && event.type == sf::Event::MouseButtonPressed
    && checkState(ENABLE)){
        enableState(DISABLED);
        disableState(ENABLE);
        std::string temp = text.getString();
        std::cout << "Disable: " << temp << std::endl;
    }
}

bool Item::hit(sf::RenderWindow &window, sf::Event event) {
    sf::FloatRect bBounds = box.getGlobalBounds();
    sf::Vector2f mPos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));

    if(hover(window, event) && MouseEvents<sf::RectangleShape>::mouseClicked(box, window)
    && event.type == sf::Event::MouseButtonPressed)
    {
        if (checkState(ENABLE) && !checkState(DISABLED)){
            enableState(DISABLED);
            disableState(ENABLE);
            std::string temp = text.getString();
            std::cout << "Disable: " << temp << std::endl;
        } else{
            enableState(ENABLE);
            disableState(DISABLED);
            std::string temp = text.getString();
            std::cout << "Enable: "<< temp << std::endl;
        }
        return true;
    }
    else
    {
        return false;
    }
}

void Item::selected() {
    enableState(SELECTED);
}

bool Item::isItemClicked(sf::RenderWindow &window, sf::Event event) {
    if(hover(window, event) && MouseEvents<sf::RectangleShape>::mouseClicked(box, window)
       && event.type == sf::Event::MouseButtonPressed) {
        return true;
    }
    return false;
}

void Item::setCharacterSize(const int& size) {
    text.setCharacterSize(size);
//    sf::FloatRect bBounds = box.getGlobalBounds();
//    text.setPosition(bBounds.left + bBounds.width/2, bBounds.top + bBounds.height/2);
    center();
}

void Item::setString(const std::string& string) {
    text.setString(string);
    center();
}

void Item::setPosition(const sf::Vector2f &position) {
    box.setPosition(position);
//    sf::FloatRect bBounds = box.getGlobalBounds();
//    text.setPosition(bBounds.left + bBounds.width/2, bBounds.top + bBounds.height/2);
    center();
}

void Item::setBoxSize(const sf::Vector2f &size) {
    box.setSize(size);
//    sf::FloatRect bBounds = box.getGlobalBounds();
//    text.setPosition(bBounds.left + bBounds.width/2, bBounds.top + bBounds.height/2);
    center();
}

void Item::setScale(const sf::Vector2f &scale) {
    box.setScale(scale);
    text.setScale(scale);
}

void Item::setBoxColor(const sf::Color color) {
    box.setFillColor(color);
}

sf::Vector2f Item::getPosition() const{
    return box.getPosition();
}

std::string Item::getString() {
    return text.getString();
}

const unsigned int Item::getCharacterSize() const{
    return text.getCharacterSize();
}

sf::Vector2f Item::getBoxSize() const{
    return box.getSize();
}

sf::FloatRect Item::getGlobalBounds() const {
    return box.getGlobalBounds();
}

sf::Color Item::getColor() {
    return box.getFillColor();
}

void Item::underneath(Item item) {
    setPosition({item.getPosition().x, item.getPosition().y + box.getGlobalBounds().height});
}

void Item::onTheTop(Item &item) {
    setPosition({item.getPosition().x, item.getPosition().y - box.getGlobalBounds().height});
}

void Item::toTheRight(Item &item) {
    setPosition({item.getPosition().x + box.getGlobalBounds().width, item.getPosition().y});
}

void Item::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    hover(window, event);
    hit(window, event);
    disable(window, event);
}

void Item::update() {
    if(checkState(HOVERED)){
//        text.setFillColor(sf::Color(250, 180, 0));
        box.setFillColor(sf::Color::Blue);
        text.setScale({1.1,1.1});
    }
    if(checkState(NORMAL)) {
        box.setFillColor(sf::Color::Black);
        text.setFillColor(sf::Color::White);
        text.setScale({1,1});
    }
    if (checkState(SELECTED)){
        box.setFillColor(sf::Color::Blue);
        text.setScale({1.1,1.1});
//        std::cout << "selected: " << getString();
    }
//    if (checkState(ENABLE)){
//        std::cout << "123";
//    }
//    if (checkState(DISABLED)){
//        std::cout << "456";
//    }
}
