//
// Created by astraeven on 2022/5/2.
//

#ifndef SFML_TEMPLATE_COLORPICKER_H
#define SFML_TEMPLATE_COLORPICKER_H
#include <SFML/Graphics.hpp>
#include "DropdownMenu.h"

class ColorPicker : public sf::Drawable{
private:
    DropdownMenu colorMenu;
    sf::Color currentColor = {sf::Color::White};
    sf::Color hoverColor = {sf::Color::White};
    bool isDefault = false;
    sf::RectangleShape displayBox;
    sf::Vector2f position;
    void align();
public:
    ColorPicker();

    void setPosition(const sf::Vector2f &position);
    void setBoxSize(const sf::Vector2f &size);
    sf::Color getMainColor();
    sf::Color getHoverColor();
    void setDefault(sf::Color color);

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
};


#endif //SFML_TEMPLATE_COLORPICKER_H
