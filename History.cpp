//
// Created by astraeven on 2022/3/26.
//

#include "History.h"
std::stack<HistoryNode> History::stack;

void History::pushHistory(const HistoryNode &snapshot) {
    stack.push(snapshot);
}

HistoryNode &History::topHistory() {
    return stack.top();
}

void History::popHistory() {
    std::cout << "pop" << std::endl;
    stack.pop();
}

void History::addEventHandler(sf::RenderWindow &window, sf::Event event) {

}

int History::historyAmount() {
    return stack.size();
}
