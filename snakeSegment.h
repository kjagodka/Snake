//
// Created by cyryl on 29.11.19.
//

#ifndef SNAKE_SNAKESEGMENT_H
#define SNAKE_SNAKESEGMENT_H


#include "entity.h"

#define SNAKE_WIDTH 0.9

class SnakeSegment : Entity {
protected:
    void drawMiddle() const;
    void drawEdge(direction side) const;
    SnakeSegment(Coords c);
};


#endif //SNAKE_SNAKESEGMENT_H
