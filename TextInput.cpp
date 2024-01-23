//
// Created by astra on 2022/3/22.
//

#include "TextInput.h"

TextInput::TextInput() : TextInput({0,100}){

}

TextInput::TextInput(sf::Vector2f position) : TextInput({400, 100}, 5, position){

}

TextInput::TextInput(sf::Vector2f boxSize, float outlineThickness, sf::Vector2f position) {
    typingBox.setFillColor(sf::Color::Black);
    typingBox.setOutlineColor(sf::Color::White);
    cursor.setFillColor(sf::Color::White);

    setBoxSize(boxSize);
    typingBox.setOutlineThickness(outlineThickness);
    typingBox.setPosition(position);

    label.setFont(Fonts::getFont(OPENSANSBOLD));
    label.setCharacterSize(30);
    label.setString("Test");
}

void TextInput::setBoxSize(sf::Vector2f size) {
    typingBox.setSize(size);
    typing.setCharacterSize(size.y-(size.y/5));
}

void TextInput::setLabel(std::string string) {
    label.setString(string);
}

void TextInput::setLabelSize(unsigned int size) {
    label.setCharacterSize(size);
}


void TextInput::setPosition(const sf::Vector2f &position) {
    label.setPosition(position);
}

void TextInput::setString(std::string string) {
    typing.setString(string);
}

std::string TextInput::getString() {
    return  typing.getString();
}

//private
void TextInput::initialize() {

    typing.setPosition({typingBox.getPosition().x+5, typingBox.getPosition().y});
    cursor.setSize({3,typingBox.getGlobalBounds().height-typingBox.getOutlineThickness()-15});

    typingBox.setPosition(label.getGlobalBounds().left + label.getGlobalBounds().width + typingBox.getOutlineThickness() + 5
                          , label.getGlobalBounds().top);

//    std::cout << typing.getRightTop() <<std::endl;

    //cursor position will always after the character that is typing.
    if (typing.isEmpty()){
    cursor.setPosition({typingBox.getPosition().x+5, typingBox.getPosition().y+5});
    } else{
        cursor.setPosition({typing.getRightTop(), typingBox.getPosition().y+5});
    }
}

void TextInput::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(label);
    window.draw(typingBox);
    window.draw(typing);
    window.draw(cursor);
}

void TextInput::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    //Start record the event if the text box is enable
    if (enableTextInput(window, event)){
        tempTyping = typing;
        typing.addEventHandler(window, event);

        //if Text is enable, and text is getting change
        if (typing.isChanging() && !KeyShortcuts::isUndo()){
            HistoryNode tempHisNode;

            tempTyping.printString();
            std::cout << std::endl;

            tempHisNode.snapshot = getSnapshot();
            tempHisNode.component = this;

            std::cout << "StackAmount: " << History::historyAmount() << std::endl;
            std::cout << "changing: " << typing.isChanging() << std::endl;
            std::cout << "Deleting: " << typing.isDeleting() << std::endl;
            History::pushHistory(tempHisNode);
        }

        //if Text is enable, and text is getting delete
        if (tempTyping.isDeleting() && !KeyShortcuts::isUndo()){
            tempTyping.setDefault();
            HistoryNode tempHisNode;

            tempTyping.printString();
            std::cout << std::endl;

            tempHisNode.snapshot = getSnapshot();
            tempHisNode.component = this;

            std::cout << "StackAmount: " << History::historyAmount() << std::endl;
            std::cout << "ch: " << typing.isChanging() << std::endl;
            std::cout << "de: " << typing.isDeleting() << std::endl;
            History::pushHistory(tempHisNode);
        }
    }

    if (KeyShortcuts::isUndo() && History::historyAmount() > 0 && event.type == sf::Event::KeyPressed){
        if (History::topHistory().component == this){
            applySnapshot(History::topHistory().snapshot);
            History::popHistory();
            std::cout << History::historyAmount() << std::endl;
        }
    }
}

void TextInput::update() {
    if (checkState(ENABLE)){
        typing.update();
        cursor.update();
    }
    initialize();

}

Snapshot &TextInput::getSnapshot() {
    snapshot1.storeSnapshot(tempTyping);
    return snapshot1;
}

void TextInput::applySnapshot(const Snapshot& snapshot) {
    typing = snapshot.getTyping();
}

//Private
bool TextInput::enableTextInput(sf::RenderWindow &window, sf::Event event) {
//    sf::FloatRect boxBounds = typingBox.getGlobalBounds();
//    sf::Vector2f mPos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
//
//    if (boxBounds.contains(mPos) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
//        enableState(ENABLE);
//        cursor.startBlinking();
//    } else if (!(boxBounds.contains(mPos)) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
//        disableState(ENABLE);
//        cursor.stopBlinking();
//    }

    if (MouseEvents<sf::RectangleShape>::mouseClicked(typingBox, window)){
        enableState(ENABLE);
        cursor.startBlinking();
    } else if (MouseEvents<sf::RectangleShape>::mouseClicked(window, event)){
        disableState(ENABLE);
        cursor.stopBlinking();
    }

    return checkState(ENABLE);
}

