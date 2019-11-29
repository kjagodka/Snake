//
// Created by cyryl on 29.11.19.
//

#ifndef SNAKE_SNAKETAIL_H
#define SNAKE_SNAKETAIL_H


#include "snakeSegment.h"

class Tail : public SnakeSegment{
private:
    direction goingTo;
public:
    Tail(const Coords &c, direction goingFrom);
    direction getGoingTo() const;
    void draw() const;
    void move();
};


#endif //SNAKE_SNAKETAIL_H
