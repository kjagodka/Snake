//
// Created by cyryl on 28.11.19.
//

#ifndef SNAKE_BOARD_H
#define SNAKE_BOARD_H

#include "coords.h"
#include "entity.h"
#include "snakeHead.h"
#include "snakeTail.h"
#include "apple.h"
#include <memory>
#include <vector>

void tick(int time);

class Board {
public:
    void reset();
    void resize();
    int getColumns() const;
    int getRows() const;
    static Board &getBoard();
    void draw() const;
    void setEntity(Coords c, std::shared_ptr < Entity > entity);
    std::shared_ptr < Entity > getEntity(Coords &c) const;
    bool makeMove();
    void setMoveDirection(direction moveDirection);

private:
    std::shared_ptr < Head > head;
    std::shared_ptr < Tail > tail;
    direction moveDirection;
    void clearBoard();
    void spawnWalls();
    void spawnSnake();
    void spawnApple();
    int columns;
    int rows;
    int snakeLen;
    int futureSnakeLen;
    bool isAlive;
    bool isMoveSafe(Coords newHeadPosition) const;
    std::vector < std::vector < std::shared_ptr < Entity > > > entities;
    Board();
};

#endif //SNAKE_BOARD_H