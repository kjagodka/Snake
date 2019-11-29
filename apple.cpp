//
// Created by cyryl on 29.11.19.
//

#include <GL/gl.h>
#include "apple.h"

Apple::Apple(const Coords &c) : Entity(c) {
    type = APPLE;
}

void Apple::draw() const {
    glColor3f(1.0, 0.0, 0.0); //red
    drawRectangle((1.0 - APPLE_SIZE) / 2.0, (1.0 - APPLE_SIZE) / 2.0, APPLE_SIZE, APPLE_SIZE);
}
