//
// Created by astraeven on 2022/4/2.
//

#ifndef SFML_TEMPLATE_DROPDOWNMENU_H
#define SFML_TEMPLATE_DROPDOWNMENU_H
#include "GUI_Components.h"
#include "ItemList.h"
#include "InputBox.h"
#include "History.h"

class DropdownMenu : public GUI_Components{
private:
    Snapshot snapshot1;

    InputBox inputBox;
    sf::Vector2f size;
    bool isInputBoxChange = false;
protected:
    void align();
    ItemList itemList;
public:
    DropdownMenu();

    void setCharacterSize(const int& size);
    void setTopString(const std::string& string);
    void setPosition(const sf::Vector2f &position);
    void setBoxSize(const sf::Vector2f &size);
    void setMainBoxColor(sf::Color color);

    void addItemList(std::string string);
    void addItemColor(sf::Color color);

    std::string getCurrentSelection();
    sf::Color getMainBoxColor();
    sf::Vector2f getBoxSize();
    std::string getHoverString();
    bool isItemListHover();
    InputBox getInputBox();

    //from the sf::Drawable class
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

// from EventHandler
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();

//from SnapshotInterface
    virtual Snapshot& getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);
};

#endif //SFML_TEMPLATE_DROPDOWNMENU_H
