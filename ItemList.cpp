//
// Created by astraeven on 2022/4/2.
//

#include "ItemList.h"
ItemList::ItemList() {
}

void ItemList::test() {
    Item item;
    pushItem(item);
}

bool ItemList::checkItemList() {
    for (auto & iter : itemList) {
        if (iter.checkState(States::ENABLE)){
            return true;
        }
    }
    return false;
}

void ItemList::align() {
    auto temp = itemList.end();
    temp--;
    for (std::_List_iterator<Item> iter = itemList.begin(); iter != temp; iter++) {
        auto iter2 = iter;
        iter2++;
        iter2->underneath(*iter);
    }
}


void ItemList::pushItem(Item &item) {
    itemList.push_back(item);
}

void ItemList::setPosition(const sf::Vector2f &position) {
    itemList.begin()->setPosition(position);
    align();
}

void ItemList::setCharacterSize(const int &size) {
    for (auto & iter : itemList) {
        iter.setCharacterSize(size);
    }
}

void ItemList::setString(const std::string &string) {
    for (auto & iter : itemList) {
        iter.setString(string);
    }
}

void ItemList::setBoxSize(const sf::Vector2f &size) {
    for (auto & iter : itemList) {
        iter.setBoxSize(size);
    }
}

void ItemList::setScale(const sf::Vector2f &scale) {
    for (auto & iter : itemList) {
        iter.setScale(scale);
    }
}

std::string ItemList::getEnableItemString() {
    for (auto & iter : itemList) {
        if (iter.checkState(States::ENABLE)){
            iter.enableState(States::DISABLED);
            iter.disableState(States::ENABLE);
            return iter.getString();
        }
    }
    return "777";
}

std::string ItemList::getEnableItemString_menuBar() {
    for (auto & iter : itemList) {
        if (iter.checkState(States::ENABLE)){
            return iter.getString();
        }
    }
    return "777";
}

std::string ItemList::getHoverItemString() {
    for (auto & iter : itemList) {
        if (iter.checkState(States::HOVERED)){
            return iter.getString();
        }
    }
    return "";
}

bool ItemList::isItemListHover() {
    for (auto & iter : itemList) {
        if (iter.checkState(States::HOVERED)){
            return true;
        }
    }
    return false;
}

bool ItemList::empty() {
    return itemList.empty();
}

std::list<Item>::iterator ItemList::begin() {
    return itemList.begin();
}

std::list<Item>::iterator ItemList::end() {
    return itemList.end();
}

void ItemList::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    if (!itemList.empty()){
        for (auto & iter : itemList) {
            window.draw(iter);
        }
    }

}

void ItemList::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if (!itemList.empty()){
        for (auto & iter : itemList) {
            iter.addEventHandler(window, event);
        }
    }
}

void ItemList::update() {
    if (!itemList.empty()){
        align();
        for (auto & iter : itemList) {
            iter.update();
        }
    }

}

