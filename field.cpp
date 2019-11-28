//
// Created by cyryl on 28.11.19.
//

#include "field.h"
#include <cassert>

fieldType Field::getType() {
    return type;
}

direction Field::getFrom() {
    return from;
}

direction Field::getTo() {
    return to;
}

Field::Field() {
    type = EMPTY;
    from = NONE;
    to = NONE;
}

bool Field::setApple() {
    if (type != EMPTY)
        return false;
    type = APPLE;
    return true;
}

bool Field::setHead(direction from) {
    if (type != EMPTY && type != APPLE)
        return false;
    type = HEAD;
    Field::from = from;
    return true;
}

bool Field::setBody(direction to) {
    if (type != HEAD)
        return false;
    type = BODY;
    Field::to = to;
    return true;
}

bool Field::setBody(direction from, direction to) {
    if (type != EMPTY)
        return false;
    type = BODY;
    Field::from = from;
    Field::to = to;
    return true;
}

bool Field::setTail() {
    if (type != BODY) {
        return false;
    }
    type = TAIL;
    from = NONE;
    return true;
}

bool Field::setTail(direction to) {
    if (type != EMPTY) {
        return false;
    }
    type = TAIL;
    Field::to = to;
    return true;
}

bool Field::setEmpty() {
    type = EMPTY;
    to = NONE;
    from = NONE;
    return true;
}