//
// Created by astra on 2022/4/26.
//

#include "Slider.h"

Slider::Slider() {
    label.setFont(Fonts::getFont(OPENSANSBOLD));
    label.setCharacterSize(10);
    label.setString("TEST");
    text_displayKnobScale.setFont(Fonts::getFont(OPENSANSBOLD));
    text_displayKnobScale.setCharacterSize(10);
    line.setSize({500, 2});
//    line.setPosition({100,100});
    knob.setRadius(6);
    knob.setOrigin(knob.getRadius(),knob.getRadius());
    maxKnobScale = 100;
    knobPosition_x = 0;
}

void Slider::align() {
    knob.setPosition(knobPosition_x, line.getPosition().y);
    text_displayKnobScale.setPosition(line.getGlobalBounds().left + line.getGlobalBounds().width + 10
                                      , line.getPosition().y - 14);
    text_displayKnobScale.setCharacterSize(20);
    label.setCharacterSize(20);
    label.setPosition(line.getGlobalBounds().left - label.getGlobalBounds().width - 10, line.getPosition().y - 14);
}

void Slider::setPosition(sf::Vector2f position) {
    line.setPosition(position);
    knobPosition_x = line.getPosition().x;
}

int Slider::getKnobScale() {
    float temp = (line.getGlobalBounds().width)/maxKnobScale;
    return  std::round((knobPosition_x - (line.getGlobalBounds().left))/temp);
}

void Slider::setMaxKnobScale(int MaxKnobScale) {
    maxKnobScale = MaxKnobScale;
}

void Slider::setLineLength(float length) {
    line.setSize({length,line.getSize().y});
}

void Slider::setLabelString(std::string string) {
    label.setString(string);
}

void Slider::setInitialValue(float value) {
    float temp = (line.getGlobalBounds().width)/maxKnobScale;
    value = (value * temp) + (line.getGlobalBounds().left);
    knobPosition_x = value;
}

void Slider::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(line);
    window.draw(knob);
    window.draw(text_displayKnobScale);
    window.draw(label);
}

void Slider::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if (MouseEvents<sf::CircleShape>::hovered(knob, window)){
        if (MouseEvents<sf::CircleShape>::mouseClicked(knob, window)){
            enableState(ENABLE);
        }
    }
    if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
        disableState(ENABLE);


    if (checkState(ENABLE)){
        if (sf::Mouse::getPosition(window).x < line.getGlobalBounds().left){
            knobPosition_x = line.getGlobalBounds().left;
        } else if (sf::Mouse::getPosition(window).x > (line.getGlobalBounds().left + line.getGlobalBounds().width)){
            knobPosition_x = line.getGlobalBounds().left + line.getGlobalBounds().width;
        } else{
            knobPosition_x = sf::Mouse::getPosition(window).x;
        }
    }
}

void Slider::update() {
    text_displayKnobScale.setString(std::to_string(getKnobScale()));
//    std::cout << getKnobScale() << std::endl;
    align();
}
