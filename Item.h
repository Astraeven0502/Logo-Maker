//
// Created by astraeven on 2022/4/2.
//

#ifndef SFML_TEMPLATE_ITEM_H
#define SFML_TEMPLATE_ITEM_H
#include <SFML/Graphics.hpp>
#include "Fonts.h"
#include "string"
#include "States.h"
#include "MouseEvents.h"

class Item : public sf::Drawable, public States{
private:
    sf::RectangleShape box;
    sf::Text text;

    void center();
    bool hover(sf::RenderWindow& window, sf::Event event);
public:
    Item();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void setCharacterSize(const int& size);
    void setString(const std::string& string);
    void setPosition(const sf::Vector2f &position);
    void setBoxSize(const sf::Vector2f &size);
    void setScale(const sf::Vector2f &scale);
    void setBoxColor(const sf::Color color);

    void disable(sf::RenderWindow& window, sf::Event event);
    bool hit(sf::RenderWindow& window, sf::Event event);
    void selected();

    bool isItemClicked(sf::RenderWindow &window, sf::Event event);
    const unsigned int getCharacterSize() const;
    sf::Vector2f getBoxSize() const;
    sf::Vector2f getPosition() const;
    std::string getString();
    sf::FloatRect getGlobalBounds() const;
    sf::Color getColor();
    void underneath(Item item);
    void onTheTop(Item& item);
    void toTheRight(Item& item);

    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
};

#endif //SFML_TEMPLATE_ITEM_H
