//
// Created by cyryl on 29.11.19.
//

#include "snakeBody.h"

void Body::draw() const {
    drawMiddle();
    drawEdge(comingFrom);
    drawEdge(goingTo);
}

Body::Body(const Coords &c, direction comingFrom, direction goingTo) : SnakeSegment(c),
                                                                                 comingFrom(comingFrom),
                                                                                 goingTo(goingTo) {
    type = BODY;
}

direction Body::getComingFrom() const {
    return comingFrom;
}

direction Body::getGoingTo() const {
    return goingTo;
}

