//
// Created by astra on 2022/4/21.
//

#ifndef SFML_PROJECT_MENUBAR_H
#define SFML_PROJECT_MENUBAR_H
#include "Menu.h"
#include <vector>

class MenuBar : public sf::Drawable{
private:
    std::vector<Menu> menuBar;
    void align();
public:
    MenuBar();

    void addMenuBar(Menu menu);
    std::string getEnableItemString();

    //from the sf::Drawable class
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    // from EventHandler
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();
};


#endif //SFML_PROJECT_MENUBAR_H
