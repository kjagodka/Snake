//
// Created by cyryl on 29.11.19.
//

#ifndef SNAKE_SNAKEHEAD_H
#define SNAKE_SNAKEHEAD_H


#include "snakeSegment.h"

class Head : public SnakeSegment{
private:
    direction goingFrom;
public:
    Head(const Coords &c, direction goingFrom);
    void draw() const;
    void move(direction moveDir);
};


#endif //SNAKE_SNAKEHEAD_H
