//
// Created by cyryl on 29.11.19.
//

#include <GL/glut.h>
#include "wall.h"

void Wall::draw() const {
    glColor3f(0.5, 0.3, 0.1); //brown
    drawRectangle(0.0, 0.0, 1.0, 1.0);
}

Wall::Wall(Coords c) : Entity(c) {
    type = WALL;
}

