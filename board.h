//
// Created by cyryl on 28.11.19.
//

#ifndef SNAKE_BOARD_H
#define SNAKE_BOARD_H

#include "field.h"
#include "coords.h"
#include <vector>

#define GROW_LEN 2

class Board {

public:
    int getRows();
    int getColumns();
    Field& getField(int column, int row);
    Field& getField(Coords coords);
    bool isAlive() const;
    void move(direction moveDir);
    void init();

private:
    int rows, columns;
    std::vector < std::vector < Field > > fields;
    bool alive;
    Coords head;
    Coords tail;
    Coords apple;
    int currentLength;
    int futureLength;
    void placeApple();
};

#endif //SNAKE_BOARD_H
