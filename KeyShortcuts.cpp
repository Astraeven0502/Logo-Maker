//
// Created by astraeven on 2022/3/26.
//

#include "KeyShortcuts.h"

bool KeyShortcuts::isUndo() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
        return true;
    else
        return false;
}
