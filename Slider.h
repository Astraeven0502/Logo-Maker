//
// Created by astra on 2022/4/26.
//

#ifndef SFML_PROJECT_SLIDER_H
#define SFML_PROJECT_SLIDER_H
#include <iostream>
#include "MouseEvents.h"
#include "States.h"
#include <SFML/Graphics.hpp>
#include <cmath>
#include "Fonts.h"

class Slider : public sf::Drawable, public sf::Transformable, public States{
private:
    sf::RectangleShape line;
    sf::CircleShape knob;
    void align();
    float knobPosition_x;
    int maxKnobScale;
    sf::Text text_displayKnobScale;
    sf::Text label;
public:
    Slider();

    void setPosition(sf::Vector2f position);

    //get current Knob Scale (0~Max)
    int getKnobScale();
    void setMaxKnobScale(int MaxKnobScale);
    void setLineLength(float length);
    void setLabelString(std::string string);
    void setInitialValue(float value);

    //from the sf::Drawable class
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    // from EventHandler
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
};


#endif //SFML_PROJECT_SLIDER_H
