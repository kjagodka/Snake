//
// Created by cyryl on 29.11.19.
//

#include "snakeBody.h"

void SnakeBody::draw() const {
    drawMiddle();
    drawEdge(comingFrom);
    drawEdge(goingTo);
}

SnakeBody::SnakeBody(const Coords &c, direction comingFrom, direction goingTo) : SnakeSegment(c),
                                                                                 comingFrom(comingFrom),
                                                                                 goingTo(goingTo) {
    type = BODY;
}

direction SnakeBody::getComingFrom() const {
    return comingFrom;
}

direction SnakeBody::getGoingTo() const {
    return goingTo;
}
