//
// Created by astraeven on 2022/2/20.
//

#include "Typing.h"

Typing::Typing() {
    multiText.setFont(OPENSANSBOLD);
    multiText.setCharacterSize(30);
    multiText.setPosition({0, 0});
//    text.setFont(Fonts::getFont(OPENSANSBOLD));
//    text.setCharacterSize(24);
//    text.setPosition(0 ,0);
    isTyping = false;
    isBackspace = false;
    isReturn = false;
    typingChar = 'a';
}

bool Typing::isOperator(const std::string& string) {
    if (string == "+")
        return true;
    if (string == "-")
        return true;
    if (string == "*")
        return true;
    if (string == "/")
        return true;
    if (string == "%")
        return true;
    if (string == "=")
        return true;
    if (string == ">")
        return true;
    if (string == "<")
        return true;
    return false;
}

bool Typing::checkInt(MultiText& multiText) {
    if (multiText.getTextLength() >= 3){
        std::_List_iterator<Letter> stopPoint = multiText.end();
        stopPoint--;
        stopPoint--;

        for (std::_List_iterator<Letter> iter = multiText.begin(); iter != stopPoint; iter++){
            std::_List_iterator<Letter> temp1 = iter;
            temp1++;
            std::_List_iterator<Letter> temp2 = iter;
            temp2++;
            temp2++;

            if (iter->getString() == "i" && temp1->getString() == "n" && temp2->getString() == "t"){
                iter->setFillColor(sf::Color::Blue);
                temp1->setFillColor(sf::Color::Blue);
                temp2->setFillColor(sf::Color::Blue);
                return true;
            }
        }
    }
    return false;
}

bool Typing::checkChar(MultiText& multiText) {
    if (multiText.getTextLength() >= 4){
        std::_List_iterator<Letter> stopPoint = multiText.end();
        stopPoint--;
        stopPoint--;
        stopPoint--;

        for (std::_List_iterator<Letter> iter = multiText.begin(); iter != stopPoint; iter++){
            std::_List_iterator<Letter> temp1 = iter;
            temp1++;
            std::_List_iterator<Letter> temp2 = iter;
            temp2++;
            temp2++;
            std::_List_iterator<Letter> temp3 = iter;
            temp3++;
            temp3++;
            temp3++;

            if (iter->getString() == "c" && temp1->getString() == "h" && temp2->getString() == "a" && temp3->getString() == "r"){
                iter->setFillColor(sf::Color::Blue);
                temp1->setFillColor(sf::Color::Blue);
                temp2->setFillColor(sf::Color::Blue);
                temp3->setFillColor(sf::Color::Blue);
                return true;
            }
        }
    }
    return false;
}

bool Typing::checkDouble(MultiText& multiText) {
    if (multiText.getTextLength() >= 6){
        std::_List_iterator<Letter> stopPoint = multiText.end();
        stopPoint--;
        stopPoint--;
        stopPoint--;
        stopPoint--;
        stopPoint--;

        for (std::_List_iterator<Letter> iter = multiText.begin(); iter != stopPoint; iter++){
            std::_List_iterator<Letter> temp1 = iter;
            temp1++;
            std::_List_iterator<Letter> temp2 = iter;
            temp2++;
            temp2++;
            std::_List_iterator<Letter> temp3 = iter;
            temp3++;
            temp3++;
            temp3++;
            std::_List_iterator<Letter> temp4 = iter;
            temp4++;
            temp4++;
            temp4++;
            temp4++;
            std::_List_iterator<Letter> temp5 = iter;
            temp5++;
            temp5++;
            temp5++;
            temp5++;
            temp5++;

            if (iter->getString() == "d" && temp1->getString() == "o" && temp2->getString() == "u" && temp3->getString() == "b"
            && temp4->getString() == "l" && temp5->getString() == "e"){
                iter->setFillColor(sf::Color::Blue);
                temp1->setFillColor(sf::Color::Blue);
                temp2->setFillColor(sf::Color::Blue);
                temp3->setFillColor(sf::Color::Blue);
                temp4->setFillColor(sf::Color::Blue);
                temp5->setFillColor(sf::Color::Blue);
                return true;
            }
        }
    }
    return false;
}

bool Typing::checkFloat(MultiText& multiText) {
    if (multiText.getTextLength() >= 5){
        std::_List_iterator<Letter> stopPoint = multiText.end();
        stopPoint--;
        stopPoint--;
        stopPoint--;
        stopPoint--;

        for (std::_List_iterator<Letter> iter = multiText.begin(); iter != stopPoint; iter++){
            std::_List_iterator<Letter> temp1 = iter;
            temp1++;
            std::_List_iterator<Letter> temp2 = iter;
            temp2++;
            temp2++;
            std::_List_iterator<Letter> temp3 = iter;
            temp3++;
            temp3++;
            temp3++;
            std::_List_iterator<Letter> temp4 = iter;
            temp4++;
            temp4++;
            temp4++;
            temp4++;

            if (iter->getString() == "f" && temp1->getString() == "l" && temp2->getString() == "o" && temp3->getString() == "a"
                && temp4->getString() == "t"){
                iter->setFillColor(sf::Color::Blue);
                temp1->setFillColor(sf::Color::Blue);
                temp2->setFillColor(sf::Color::Blue);
                temp3->setFillColor(sf::Color::Blue);
                temp4->setFillColor(sf::Color::Blue);
                return true;
            }
        }
    }
    return false;
}


void Typing::setCharacterSize(int size) {
    multiText.setCharacterSize(size);
}

void Typing::setPosition(float x, float y) {
    multiText.setPosition(x,y);
}

void Typing::setPosition(const sf::Vector2f &position) {
    multiText.setPosition(position);
}

void Typing::setDefault() {
    isTyping = false;
    isBackspace = false;
    isReturn = false;
}

void Typing::setString(std::string string) {
    multiText.setString(string);
}

float Typing::getRightTop() {
    std::_List_iterator<Letter> temp = multiText.begin();
    for (int i = 0; i < multiText.getTextLength()-1; ++i) {
        temp++;
    }
    return temp->getGlobalBounds().left+temp->getGlobalBounds().width+5;
}

MultiText Typing::getMultiText() {
    return multiText;
}

void Typing::printString() {
    multiText.printString();
}

std::string Typing::getString() {
    return multiText.getString();
}

bool Typing::isEmpty() {
    return multiText.isEmpty();
}

bool Typing::isChanging() {
    if (isTyping){
        return true;
    }
    return false;
}

bool Typing::isDeleting() const {
    if (isBackspace){
        return true;
    }
    return false;
}

Typing &Typing::operator=(const Typing &typing) {
    this->multiText = typing.multiText;
    isTyping = typing.isTyping;
    isBackspace = typing.isBackspace;
    isReturn = typing.isReturn;
    return *this;
}

void Typing::addEventHandler(sf::RenderWindow &window, sf::Event event) {

    if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Backspace)){
        isBackspace = true;
        std::cout << "11";
    }
    else if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Return)){
        isReturn = true;
    }
    else if (event.type == sf::Event::TextEntered && !KeyShortcuts::isUndo() && !isBackspace){
//        std::cout << "111";
//        text.setString(text.getString() + event.text.unicode);
        typingChar = event.text.unicode;
        isTyping = true;
    }
}

void Typing::update() {
    if (isTyping){
        multiText.pushLetter(typingChar);
//        text.setString(text.getString() + typingChar);
        isTyping = false;
    }
    if (isReturn){
//        text.setString(text.getString() + "\n");
        isReturn = false;
    }
    if (isBackspace){
        multiText.popLetter();
//        text.setString(text.getString().substring(0, text.getString().getSize()-2));
        isBackspace = false;
    }

    if (!multiText.isEmpty()){
        //this for loop is to reset color
        for (auto & iter : multiText){
            iter.setFillColor(sf::Color::White);
        }
        changeNumberColor();
        changeOperatorColor();
        changeWordsColor();
    }
    multiText.update();
}

void Typing::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(multiText);
//    window.draw(text);
}

void Typing::changeWordsColor() {
    checkInt(multiText);
    checkChar(multiText);
    checkDouble(multiText);
    checkFloat(multiText);
}

void Typing::changeOperatorColor() {
    for (auto & iter : multiText){
        std::string temp = iter.getString();
        if (isOperator(temp)){
            iter.setFillColor(sf::Color::Green);
        }
    }
}

void Typing::changeNumberColor() {
    for (auto & iter : multiText){
        std::string temp = iter.getString();
        if (std::isdigit(temp[0])){
            iter.setFillColor(sf::Color::Red);
        }
    }

//    for (std::_List_iterator<Letter> iter = multiText.begin(); iter != multiText.end(); iter++){
//        std::string temp = iter->getString();
//        if (std::isdigit(temp[0])){
//            iter->setFillColor(sf::Color::Red);
//        }
//    }
}







