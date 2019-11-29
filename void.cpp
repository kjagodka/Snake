//
// Created by cyryl on 29.11.19.
//

#include "void.h"

Void::Void(const Coords &c) : Entity(c) {
    type = VOID;
}

void Void::draw() const {}
