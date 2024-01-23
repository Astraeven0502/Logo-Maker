//
// Created by astraeven on 2022/3/26.
//
#ifndef SFML_TEMPLATE_MOUSEEVENTS_CPP
#define SFML_TEMPLATE_MOUSEEVENTS_CPP

#include "MouseEvents.h"

template <class T>
sf::Clock MouseEvents<T>::clock;
template <class T>
int MouseEvents<T>::clicks;

template<class T>
void MouseEvents<T>::countClicks(sf::Event event) {

}

template<class T>
bool MouseEvents<T>::mouseClicked(T &object, sf::RenderWindow &window) {

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && hovered(object, window))
        return true;
    else
        return false;
}

template<class T>
bool MouseEvents<T>::mouseClicked(sf::RenderWindow &window, sf::Event event) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        return true;
    else
        return false;
}

template<class T>
bool MouseEvents<T>::mouseDoubleClicked() {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        sf::Time t = clock.getElapsedTime();
        sf::Int64 mileSec = t.asMilliseconds();
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && mileSec < 500){
            return true;
        } else{
            clock.restart();
            return false;
        }
    }
}

template<class T>
bool MouseEvents<T>::mouseTripleClicked() {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        sf::Time t = clock.getElapsedTime();
        sf::Int64 mileSec = t.asMilliseconds();
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && mileSec < 500){
            clock.restart();
            t = clock.getElapsedTime();
            mileSec = t.asMilliseconds();
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && mileSec < 500){
                return true;
            }
        } else{
            clock.restart();
            return false;
        }
    }
}

template<class T>
bool MouseEvents<T>::draggedOver(T &object, sf::RenderWindow &window, sf::Event event) {
    sf::FloatRect bBounds = object.getGlobalBounds();
    sf::Vector2f mPos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));

    if (bBounds.contains(mPos) && event.mouseButton.button == sf::Mouse::Left){
        if (mPos != static_cast<sf::Vector2f>(sf::Mouse::getPosition(window))){
            return true;
        }
    } else
        return false;
}

template<class T>
bool MouseEvents<T>::hovered(T &object, sf::RenderWindow &window) {
    sf::FloatRect bBounds = object.getGlobalBounds();
    sf::Vector2f mPos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));

    if(bBounds.contains(mPos))
        return true;
    else
        return false;
}

#endif //SFML_TEMPLATE_MOUSEEVENTS_CPP
