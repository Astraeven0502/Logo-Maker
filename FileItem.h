//
// Created by astraeven on 2022/4/28.
//

#ifndef SFML_TEMPLATE_FILEITEM_H
#define SFML_TEMPLATE_FILEITEM_H
#include "Item.h"
#include "Image.h"

class FileItem : public Item{
public:
    //Constructors
    FileItem();
    FileItem(ImageNames icon, std::string text, sf::Vector2f size, sf::Vector2f position);

    //GUIComponent pure virtual functions, refer to the TextInput Project for Info
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    //I use this function to highlight the item when clicked, and unhighlight when something
    //else is clicked
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);

    virtual void update();
    //Returns the bounds of the item
    sf::FloatRect getGlobalBounds() const;
    //returns the size of the item
    sf::Vector2f getSize() const;
    //returns the size of the item
    sf::Vector2f getPosition() const;

    std::string getSelectedString();

    //sets the position of the item
    void setPosition(sf::Vector2f pos);
    //uses an enum to change the icon to a folder or file
    void setIcon(ImageNames icon);

private:
    //this is the folder or file icon
    sf::Sprite icon;
    float padding = 5;
    void align();
};


#endif //SFML_TEMPLATE_FILEITEM_H
