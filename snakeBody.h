//
// Created by cyryl on 29.11.19.
//

#ifndef SNAKE_SNAKEBODY_H
#define SNAKE_SNAKEBODY_H


#include "snakeSegment.h"

class SnakeBody : SnakeSegment{
private:
    direction comingFrom, goingTo;
public:
    void draw() const override;

    direction getComingFrom() const;

    direction getGoingTo() const;

    SnakeBody(const Coords &c, direction comingFrom, direction goingTo);
};


#endif //SNAKE_SNAKEBODY_H
