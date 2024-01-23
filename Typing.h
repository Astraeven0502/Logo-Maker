//
// Created by astraeven on 2022/2/20.
//

#ifndef SFML_TEMPLATE_TYPING_H
#define SFML_TEMPLATE_TYPING_H
#include <SFML/Graphics.hpp>
#include <cctype>
#include "Fonts.h"
#include <iostream>
#include "MultiText.h"
#include "KeyShortcuts.h"


class Typing : public sf::Drawable{
private:
    MultiText multiText;
    bool isTyping, isBackspace, isReturn;
    char typingChar;
    bool isOperator(const std::string& string);

    bool checkInt(MultiText& multiText);
    bool checkChar(MultiText& multiText);
    bool checkDouble(MultiText& multiText);
    bool checkFloat(MultiText& multiText);

public:
    Typing();

    void setCharacterSize(int size);
    void setPosition(float x, float y);
    void setPosition(const sf::Vector2f &position);
    void setDefault();
    void setString(std::string string);

    float getRightTop();
    MultiText getMultiText();
    void printString();
    std::string getString();


    void changeWordsColor();
    void changeOperatorColor();
    void changeNumberColor();

    bool isEmpty();
    bool isChanging();
    bool isDeleting() const;

    Typing& operator=(const Typing& typing);

    //Detect when a key is pressed on the keyboard
    void addEventHandler(sf::RenderWindow& window, sf::Event event);

    //Used for update
    void update();

    //draw the text
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

};


#endif //SFML_TEMPLATE_TYPING_H
