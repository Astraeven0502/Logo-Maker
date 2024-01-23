//
// Created by astraeven on 2022/4/28.
//

#include "FileItem.h"

FileItem::FileItem() : FileItem(FOLDERPNG, "Test", {300, 60}, {0, 0}){

}

FileItem::FileItem(ImageNames icon, std::string text, sf::Vector2f size, sf::Vector2f position) {
    setPosition(position);
    setBoxSize(size);
    setString(text);
    setIcon(icon);
    setCharacterSize(30);
}

void FileItem::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    Item::draw(window, states);
    window.draw(icon);
}

void FileItem::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if(Item::hit(window, event)){
        Item::selected();
    }else if (!Item::hit(window, event) && event.type == sf::Event::MouseButtonPressed && checkState(SELECTED)){
        disableState(SELECTED);
    }
//    std::cout << checkState(ENABLE) << checkState(DISABLED) << std::endl;
}

void FileItem::update() {
    Item::update();
    align();
}

sf::FloatRect FileItem::getGlobalBounds() const {
//    sf::FloatRect temp;
//    temp.left = icon.getGlobalBounds().left;
//    temp.top = icon.getGlobalBounds().top;
//    temp.height = icon.getGlobalBounds().height;
//    temp.width = icon.getGlobalBounds().width;
    return Item::getGlobalBounds();
}

sf::Vector2f FileItem::getSize() const {
//    sf::Vector2f temp;
//    temp.x = Item::getBoxSize().x + icon.getGlobalBounds().width;
//    temp.y =Item::getBoxSize().y;
    return Item::getBoxSize();
}

sf::Vector2f FileItem::getPosition() const {
    return icon.getPosition();
}

void FileItem::setPosition(sf::Vector2f pos) {
    icon.setPosition(pos);
}

void FileItem::setIcon(ImageNames icon) {
    sf::Sprite temp;
    temp.setTexture(Image::getImage(icon));
    this->icon = temp;
//    std::cout << this->icon.getScale().x << " " << this->icon.getScale().y << std::endl;

//    this->icon.setTexture(Image::getImage(icon));
//    float tempScale = Item::getGlobalBounds().height / this->icon.getTexture()->getSize().x;
//    this->icon.setScale({tempScale, tempScale});

//    std::cout << this->icon.getScale().x << " " << this->icon.getScale().y << std::endl;

}

void FileItem::align() {
    //set the image scale to the size that align the box.
    float tempScale = Item::getGlobalBounds().height/icon.getTexture()->getSize().x;
    icon.setScale({tempScale*9/10, tempScale*9/10});
//    std::cout << icon.getScale().x << " " << icon.getScale().y << std::endl;

    //keep
//    Item::setPosition({icon.getGlobalBounds().left + icon.getGlobalBounds().width, icon.getGlobalBounds().top});
    Item::setPosition(icon.getPosition());
}

std::string FileItem::getSelectedString() {
    if (checkState(SELECTED))
        return getString();
    return "Nothing being selected";
}
