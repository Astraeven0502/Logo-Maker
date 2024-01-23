//
// Created by astra on 2022/4/21.
//
#ifndef SFML_PROJECT_MENU_H
#define SFML_PROJECT_MENU_H
#include "ItemList.h"
#include "GUI_Components.h"

class Menu : public sf::Drawable{
private:
    ItemList itemList;
    Item topItem;
    void align();
    bool isTopItemEnable = false;
public:
    Menu();

    void setCharacterSize(const int& size);
    void setTopString(const std::string& string);
    void setPosition(const sf::Vector2f &position);
    void setTopBoxSize(const sf::Vector2f &size);
    void setListBoxSize(const sf::Vector2f &size);

    std::string getEnableItemString();

    void addItemList(std::string string);

    void toTheRight(Menu& menu);
//from the sf::Drawable class
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

// from EventHandler
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();

};


#endif //SFML_PROJECT_MENU_H
