//
// Created by astraeven on 2022/3/26.
//

#ifndef SFML_TEMPLATE_HISTORY_H
#define SFML_TEMPLATE_HISTORY_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "HistoryNode.h"
#include "stack"

class History {

private:
    static std::stack<HistoryNode> stack;
public:
    static void pushHistory(const HistoryNode& snapshot);
    static HistoryNode& topHistory();
    static void popHistory();
    static void addEventHandler(sf::RenderWindow& window, sf::Event event);

    static int historyAmount();
};


#endif //SFML_TEMPLATE_HISTORY_H
