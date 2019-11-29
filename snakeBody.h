//
// Created by cyryl on 29.11.19.
//

#ifndef SNAKE_SNAKEBODY_H
#define SNAKE_SNAKEBODY_H


#include "snakeSegment.h"

class Body : public SnakeSegment{
private:
    direction comingFrom, goingTo;
public:
    void draw() const override;

    direction getComingFrom() const;

    direction getGoingTo() const;

    Body(const Coords &c, direction comingFrom, direction goingTo);
};


#endif //SNAKE_SNAKEBODY_H
