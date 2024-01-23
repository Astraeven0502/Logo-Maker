//
// Created by astraeven on 2022/3/5.
//

#ifndef CS008_SFML_MULTITEXT_MULTITEXT_H
#define CS008_SFML_MULTITEXT_MULTITEXT_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Letter.h"
#include <list>
#include "Fonts.h"

class MultiText : public sf::Drawable{
private:
    std::list<Letter> letter;
    sf::Vector2f position;
    int size;
    FontNames fontNames;
public:
    MultiText();

    bool isEmpty();

    //iterator
    std::list<Letter>::iterator begin();
    std::list<Letter>::iterator end();

    //used when type in a character
    void pushLetter(char character);
    //used when delete a character
    void popLetter();

    //getter
    std::string getString();
    int getTextLength();
    sf::Vector2f getPosition();
    void printString();

    MultiText& operator=(const MultiText& typing);

    //setter
    void setCharacterSize(int size);
    void setPosition(float x, float y);
    void setPosition(const sf::Vector2f &position);
    void setFont(FontNames fontNames);
    void setFillColor(sf::Color color, std::_List_iterator<Letter> iter);
    void setString(std::string string);

    //Used for update
    void update();

    //polymorphism, pure virtual function defined
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
};


#endif //CS008_SFML_MULTITEXT_MULTITEXT_H
