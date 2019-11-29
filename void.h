//
// Created by cyryl on 29.11.19.
//

#ifndef SNAKE_VOID_H
#define SNAKE_VOID_H


#include "entity.h"

class Void : public Entity
{
public:
    Void(const Coords &c);

    void draw() const;
};


#endif //SNAKE_VOID_H
