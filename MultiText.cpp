//
// Created by astraeven on 2022/3/5.
//


#include "MultiText.h"

MultiText::MultiText() {
    fontNames = OPENSANSBOLD;
    position = {0,0};
    size = 24;
}

bool MultiText::isEmpty() {
    return letter.empty();
}

void MultiText::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    for (auto & iter : letter) {
        window.draw(iter);
    }
}

std::list<Letter>::iterator MultiText::begin() {
    return letter.begin();
}

std::list<Letter>::iterator MultiText::end() {
    return letter.end();
}

void MultiText::pushLetter(char character) {
    Letter temp;
    temp.setString(character);
    temp.setFont(Fonts::getFont(fontNames));
    temp.setCharacterSize(size);
    letter.push_back(temp);
}

void MultiText::popLetter() {
    if (!letter.empty())
        letter.pop_back();
}

std::string MultiText::getString() {
    std::string temp;
    for (auto & iter : letter) {
        temp += iter.getString();
    }
    return temp;
}

int MultiText::getTextLength() {
    return letter.size();
}


sf::Vector2f MultiText::getPosition() {
    return position;
}

void MultiText::printString() {
    for (std::_List_iterator<Letter> iter = letter.begin(); iter != letter.end(); iter++){
        std::string s = iter->getString();
        std::cout << s;
    }
}

MultiText &MultiText::operator=(const MultiText &typing) {
    this->position = typing.position;
    this->size = typing.size;
    this->fontNames = typing.fontNames;
    this->letter = typing.letter;

    return *this;
}

void MultiText::setFont(FontNames fontNames) {
    this->fontNames = fontNames;
}

void MultiText::setCharacterSize(int size) {
    this->size = size;
}

void MultiText::setPosition(float x, float y) {
    position = {x, y};
}

void MultiText::setPosition(const sf::Vector2f &position) {
    this->position = position;
}

void MultiText::setFillColor(sf::Color color, std::_List_iterator<Letter> iter) {
    iter->setFillColor(color);
}

void MultiText::setString(std::string string) {
    while (!letter.empty()){
        popLetter();
    }
    for (auto iter = string.begin(); iter != string.end(); iter++) {
        pushLetter(*iter);
    }

}

void MultiText::update() {
    for (std::_List_iterator<Letter> iter = letter.begin(); iter != letter.end(); iter++) {
        if (iter == letter.begin()){
            letter.begin()->setPosition(position);
        }else {
            std::_List_iterator<Letter> temp = iter;
            temp--;
            iter->setPosition(temp->getGlobalBounds().left + temp->getGlobalBounds().width, position.y);\
        }
    }
}









