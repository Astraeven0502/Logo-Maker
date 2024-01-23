//
// Created by astra on 2022/3/22.
//

#include "Snapshot.h"

void Snapshot::storeSnapshot(Typing& typing) {
    this->typing = typing;
}

Typing Snapshot::getTyping() const{
    return typing;
}

void Snapshot::storeSnapshot(std::string string) {
    this->string = string;
}

std::string Snapshot::getString() const {
    return string;
}
