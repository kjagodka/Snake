//
// Created by cyryl on 28.11.19.
//

#ifndef SNAKE_BOARD_H
#define SNAKE_BOARD_H

#include "coords.h"
#include "entity.h"
#include <vector>

#define GROW_LEN 2
#define ROWS 19
#define COLUMNS 33

void tick(int time);

class Board {
public:
    void init();
    void resize(int rows, int columns);

    int getColumns() const;
    int getRows() const;
    static Board &getBoard();
    void draw() const;
private:
    int columns;
    int rows;
    std::vector < std::vector < Entity > > entities;
};

#endif //SNAKE_BOARD_H
