//
// Created by cyryl on 28.11.19.
//

#ifndef SNAKE_FIELD_H
#define SNAKE_FIELD_H

#include "coords.h"

enum fieldType{APPLE, HEAD, BODY, TAIL, EMPTY};

class Field {
public:
    fieldType getType();
    direction getFrom();
    direction getTo();

    Field();
    bool setApple();
    bool setHead(direction from);
    bool setBody(direction from, direction to);
    bool setBody(direction to);
    bool setTail(direction to);
    bool setTail();
    bool setEmpty();
private:
    direction from, to;
    fieldType type;
};

#endif //SNAKE_FIELD_H
