//
// Created by cyryl on 29.11.19.
//

#include "snakeSegment.h"

void SnakeSegment::drawMiddle() const {
    drawRectangle((1.0 - SNAKE_WIDTH) / 2.0, (1.0 - SNAKE_WIDTH) / 2.0, SNAKE_WIDTH, SNAKE_WIDTH);
}

void SnakeSegment::drawEdge(direction side) const {
    switch (side) {
        case DOWN:
            drawRectangle((1.0 - SNAKE_WIDTH) / 2.0, 0.0, SNAKE_WIDTH, (1.0 - SNAKE_WIDTH) / 2.0);
            break;
        case UP:
            drawRectangle((1.0 - SNAKE_WIDTH) / 2.0, 1.0 - (1.0 - SNAKE_WIDTH) / 2.0, SNAKE_WIDTH, (1.0 - SNAKE_WIDTH) / 2.0);
            break;
        case LEFT:
            drawRectangle(0.0, (1.0 - SNAKE_WIDTH) / 2.0, (1.0 - SNAKE_WIDTH) / 2.0, SNAKE_WIDTH);
            break;
        case RIGHT:
            drawRectangle(1.0 - (1.0 - SNAKE_WIDTH) / 2.0, (1.0 - SNAKE_WIDTH) / 2.0, (1.0 - SNAKE_WIDTH) / 2.0, SNAKE_WIDTH);
            break;
        default:
            break;
    }
}

SnakeSegment::SnakeSegment(Coords c) : Entity(c) {}
