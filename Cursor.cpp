//
// Created by astra on 2022/3/22.
//

#include "Cursor.h"

Cursor::Cursor() {
    this->setScale(0,0);
}

void Cursor::startBlinking() {
    isBlinking = true;
}

void Cursor::stopBlinking() {
    isBlinking = false;
    this->setScale(0,0);
}

void Cursor::blinking() {
    sf::Time t = clock.getElapsedTime();
    sf::Int64 mileSec = t.asMilliseconds();
    //blink every 0.5second
    if ((mileSec/500) % 2 == 1){
        this->setScale(0,0);
    }
    else{
        this->setScale(1,1);
    }
}

void Cursor::update() {
    if (isBlinking){
     blinking();
    }
}

