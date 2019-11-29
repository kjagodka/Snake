//
// Created by cyryl on 29.11.19.
//

#include <GL/gl.h>
#include "entity.h"
#include "board.h"

const Coords &Entity::getCoords() const {
    return coords;
}

entityType Entity::getType() const {
    return type;
}

void Entity::drawRectangle(float x, float y, float width, float height) const {
    int column = coords.getColumn();
    int row = coords.getRow();

    int columns = Board::getBoard().getColumns();
    int rows = Board::getBoard().getRows();

    float fieldX = column * 2.0 / columns - 1.0;
    float fieldY = row * 2.0 / rows - 1.0;

    x = x * 2.0 / columns;
    y = y * 2.0 / rows;

    width = width * 2.0 / columns;
    height = height * 2.0 / rows;
    glRectf(fieldX + x, fieldY + y, fieldX + x + width, fieldY + y + height);
}



Entity::Entity(Coords c) : coords(c), type(VOID){}

void Entity::setCoords(const Coords &coords) {
    Entity::coords = coords;
}

void Entity::draw() const {}
