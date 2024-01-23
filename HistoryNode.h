//
// Created by astraeven on 2022/3/26.
//

#ifndef SFML_TEMPLATE_HISTORYNODE_H
#define SFML_TEMPLATE_HISTORYNODE_H
#include "GUI_Components.h"
#include "Snapshot.h"
#include "TextInput.h"

struct HistoryNode{
    Snapshot snapshot;
    GUI_Components* component;
};

#endif //SFML_TEMPLATE_HISTORYNODE_H
