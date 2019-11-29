//
// Created by cyryl on 29.11.19.
//

#include "snakeTail.h"

SnakeTail::SnakeTail(const Coords &c, direction goingTo) : SnakeSegment(c), goingTo(goingTo) {}

direction SnakeTail::getGoingTo() const {
    return goingTo;
}

void SnakeTail::draw() const {
    drawMiddle();
    drawEdge(goingTo);
}
