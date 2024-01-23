//
// Created by astraeven on 2022/4/2.
//

#ifndef SFML_TEMPLATE_INPUTBOX_H
#define SFML_TEMPLATE_INPUTBOX_H
#include <SFML/Graphics.hpp>
#include "Item.h"

class InputBox : public sf::Drawable{
private:
    Item topItem;
//    ItemList itemList;
public:
    InputBox();

    void setCharacterSize(const int& size);
    void setString(const std::string& string);
    void setPosition(const sf::Vector2f &position);
    void setBoxSize(const sf::Vector2f &size);

    Item getItem() const;

    //drawable
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();

};


#endif //SFML_TEMPLATE_INPUTBOX_H
