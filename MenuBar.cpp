//
// Created by astra on 2022/4/21.
//

#include "MenuBar.h"

void MenuBar::align() {
    auto temp = menuBar.end();
    temp--;
    for (auto iter = menuBar.begin(); iter != temp ; iter++) {
        auto iter2 = iter;
        iter2++;
        iter->toTheRight(*iter2);
    }

//    auto temp = itemList.end();
//    temp--;
//    for (std::_List_iterator<Item> iter = itemList.begin(); iter != temp; iter++) {
//        auto iter2 = iter;
//        iter2++;
//        iter2->underneath(*iter);
//    }
}

MenuBar::MenuBar() {

}

void MenuBar::addMenuBar(Menu menu) {
    menuBar.push_back(menu);
}

std::string MenuBar::getEnableItemString() {
    std::string temp = "None";
    for (int i = 0; i < menuBar.size(); ++i) {
        if (menuBar[i].getEnableItemString() != "777"){
            temp = menuBar[i].getEnableItemString();
        }
    }
    return temp;
}

void MenuBar::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    for (int i = 0; i < menuBar.size(); ++i) {
        window.draw(menuBar[i]);
    }
}

void MenuBar::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    for (int i = 0; i < menuBar.size(); ++i) {
        menuBar[i].addEventHandler(window, event);
    }
}

void MenuBar::update() {
    for (int i = 0; i < menuBar.size(); ++i) {
        menuBar[i].update();
    }
    align();
}
