//
// Created by astra on 2022/3/22.
//

#ifndef SFML_PROJECT_CURSOR_H
#define SFML_PROJECT_CURSOR_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>

class Cursor : public sf::RectangleShape{
private:
    sf::Clock clock;
    bool isBlinking = false;
    sf::Vector2f position;
public:
    Cursor();
    void startBlinking();
    void stopBlinking();
    void blinking();
    void update();
};


#endif //SFML_PROJECT_CURSOR_H