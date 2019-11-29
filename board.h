//
// Created by cyryl on 28.11.19.
//

#ifndef SNAKE_BOARD_H
#define SNAKE_BOARD_H

#include "coords.h"
#include "entity.h"
#include <memory>
#include <vector>

#define ROWS 5
#define COLUMNS 9

void tick(int time);

class Board {
public:
    void init();
    void resize(int columns, int rows);
    int getColumns() const;
    int getRows() const;
    static Board &getBoard();
    void draw() const;
private:
    int columns;
    int rows;
    std::vector < std::vector < std::shared_ptr < Entity > > > entities;
    Board();
};

#endif //SNAKE_BOARD_H
