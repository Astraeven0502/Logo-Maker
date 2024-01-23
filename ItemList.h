//
// Created by astraeven on 2022/4/2.
//

#ifndef SFML_TEMPLATE_ITEMLIST_H
#define SFML_TEMPLATE_ITEMLIST_H
#include <SFML/Graphics.hpp>
#include <list>
#include "Item.h"

class ItemList : public sf::Drawable{
private:
    std::list<Item> itemList;
    void align();

    //Only use for testing
    void test();

public:
    ItemList();

    void pushItem(Item& item);
    void setPosition(const sf::Vector2f &position);
    void setCharacterSize(const int& size);
    void setString(const std::string& string);
    void setBoxSize(const sf::Vector2f &size);
    void setScale(const sf::Vector2f &scale);

    std::string getEnableItemString();
    std::string getEnableItemString_menuBar();
    std::string getHoverItemString();
    bool isItemListHover();

    //check if any of Item List is being enable
    bool checkItemList();

    bool empty();
    //iterator
    std::list<Item>::iterator begin();
    std::list<Item>::iterator end();

    //drawable
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
};


#endif //SFML_TEMPLATE_ITEMLIST_H
