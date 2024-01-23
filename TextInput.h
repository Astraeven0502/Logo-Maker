//
// Created by astra on 2022/3/22.
//

#ifndef SFML_PROJECT_TEXTINPUT_H
#define SFML_PROJECT_TEXTINPUT_H
#include "GUI_Components.h"
#include "Typing.h"
#include "Cursor.h"
#include "KeyShortcuts.h"
#include "MouseEvents.h"
#include "History.h"

class TextInput : public GUI_Components{
private:
    Snapshot snapshot1;

    //This four variable need to align
    sf::RectangleShape typingBox;
    Cursor cursor;
    Typing typing;
    sf::Text label;
    //This tempTyping is use to get snapshot
    Typing tempTyping;

    //Return true if the text box is enable.(Click the text box to enable)
    bool enableTextInput(sf::RenderWindow& window, sf::Event event);

    //Group every component
    void initialize();
public:
    TextInput();
    TextInput(sf::Vector2f position);
    TextInput(sf::Vector2f boxSize, float outlineThickness, sf::Vector2f position);

    void setBoxSize(sf::Vector2f size);
    void setLabel(std::string string);
    void setLabelSize(unsigned int size);
    void setPosition(const sf::Vector2f &position);
    void setString(std::string string);


    std::string getString();


//from the sf::Drawable class
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

// from EventHandler
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();

//from SnapshotInterface
    virtual Snapshot& getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);
};


#endif //SFML_PROJECT_TEXTINPUT_H
