//
// Created by astra on 2022/3/22.
//

#ifndef SFML_PROJECT_STATES_H
#define SFML_PROJECT_STATES_H

#include <SFML/Graphics.hpp>

class States {
private:
    std::vector<bool> objectStates;
public:
    States();
    enum states{
        ENABLE,
        HIDDEN,
        HIGHLIGHTED,
        DISABLED,
        HOVERED,
        NORMAL,
        SELECTED,

        ///This should always be the last state
        LAST
    };
    bool checkState(states state) const;
    void enableState(states state);
    void disableState(states state);
};


#endif //SFML_PROJECT_STATES_H
