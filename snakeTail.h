//
// Created by cyryl on 29.11.19.
//

#ifndef SNAKE_SNAKETAIL_H
#define SNAKE_SNAKETAIL_H


#include "snakeSegment.h"

class SnakeTail : SnakeSegment{
private:
    direction goingTo;
public:
    SnakeTail(const Coords &c, direction goingTo);
    direction getGoingTo() const;
    void draw() const;
};


#endif //SNAKE_SNAKETAIL_H
