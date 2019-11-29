//
// Created by cyryl on 29.11.19.
//

#ifndef SNAKE_SNAKEHEAD_H
#define SNAKE_SNAKEHEAD_H


#include "snakeSegment.h"

class SnakeHead : SnakeSegment{
private:
    direction goingFrom;
public:
    SnakeHead(const Coords &c, direction goingFrom);
};


#endif //SNAKE_SNAKEHEAD_H
