//
// Created by cyryl on 29.11.19.
//

#ifndef SNAKE_ENTITY_H
#define SNAKE_ENTITY_H


#include "coords.h"

enum entityType {HEAD, BODY, TAIL, APPLE, VOID, WALL};

class Entity {
protected:
    Coords coords;
    entityType type;
    void drawRectangle(float x, float y, float width, float height) const;
public:
    const Coords &getCoords() const;
    Entity(Coords c);
    entityType getType() const;
    virtual void draw() const;
    void setCoords(const Coords &coords);
};


#endif //SNAKE_ENTITY_H
