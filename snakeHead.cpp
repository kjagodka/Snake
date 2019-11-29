//
// Created by cyryl on 29.11.19.
//

#include "snakeHead.h"

SnakeHead::SnakeHead(const Coords &c, direction goingFrom) : SnakeSegment(c), goingFrom(goingFrom) {
    type = HEAD;
}

void SnakeHead::draw() const {
    drawMiddle();
    drawEdge(goingFrom);
}