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

#define ROWS 15
#define COLUMNS 7
#define APPLE_GROWTH_LEN 1

void tick(int time);

class Board {
public:
    void init();
    void resize(int columns, int rows);
    int getColumns() const;
    int getRows() const;
    static Board &getBoard();
    void draw() const;
    void setEntity(Coords c, std::shared_ptr < Entity > entity);
    std::shared_ptr < Entity > getEntity(Coords &c) const;
    bool makeMove(direction moveDir);
private:
    std::shared_ptr < Head > head;
    std::shared_ptr < Tail > tail;
    int columns;
    int rows;
    int snakeLen;
    int futureSnakeLen;
    void placeApple();
    bool isMoveSafe(Coords newHeadPosition) const;
    std::vector < std::vector < std::shared_ptr < Entity > > > entities;
    Board();
};

#endif //SNAKE_BOARD_H
