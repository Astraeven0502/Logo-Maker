//
// Created by astra on 2022/3/22.
//

#ifndef SFML_PROJECT_SNAPSHOT_H
#define SFML_PROJECT_SNAPSHOT_H
#include <string>
#include "Typing.h"

class Snapshot {
private:
    std::string string;
    Typing typing;
public:
    void storeSnapshot(std::string string);
    void storeSnapshot(Typing& typing);
    Typing getTyping() const;
    std::string getString() const;
};


#endif //SFML_PROJECT_SNAPSHOT_H
