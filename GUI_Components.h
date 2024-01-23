//
// Created by astra on 2022/3/22.
//

#ifndef SFML_PROJECT_GUI_COMPONENTS_H
#define SFML_PROJECT_GUI_COMPONENTS_H
#include "EventHandler.h"
#include "States.h"
#include "SnapshotInterface.h"
#include <SFML/Graphics.hpp>


class GUI_Components : public EventHandler, public States, public SnapshotInterface, public sf::Drawable, public  sf::Transformable{
public:
//from the sf::Drawable class
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const = 0;

// from EventHandler
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event) = 0;
    virtual void update() = 0;

//from SnapshotInterface
    virtual Snapshot& getSnapshot() = 0;
    virtual void applySnapshot(const Snapshot& snapshot) = 0;
};


#endif //SFML_PROJECT_GUI_COMPONENTS_H
