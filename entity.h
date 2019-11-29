//
// Created by cyryl on 29.11.19.
//

#ifndef SNAKE_ENTITY_H
#define SNAKE_ENTITY_H


#include "coords.h"

class Entity {
protected:
    Coords coords;
    enum entityType{HEAD, BODY, TAIL, APPLE, VOID, WALL} type;
    void drawRectangle(float x, float y, float width, float height) const;
    Entity(Coords c);

public:
    const Coords &getCoords() const;
    entityType getType() const;
    virtual void draw() const = 0;
};


#endif //SNAKE_ENTITY_H
