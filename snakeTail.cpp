//
// Created by cyryl on 29.11.19.
//

#include "snakeTail.h"

SnakeTail::SnakeTail(const Coords &c, direction goingFrom) : SnakeSegment(c), goingTo(goingFrom) {
    type = TAIL;
}

direction SnakeTail::getGoingTo() const {
    return goingTo;
}

void SnakeTail::draw() const {
    drawMiddle();
    drawEdge(goingTo);
}
