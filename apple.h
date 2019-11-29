//
// Created by cyryl on 29.11.19.
//

#ifndef SNAKE_APPLE_H
#define SNAKE_APPLE_H


#include "entity.h"
#define APPLE_SIZE 0.7

class Apple : Entity {
public:
    void draw() const;
    Apple(const Coords &c);
};


#endif //SNAKE_APPLE_H
