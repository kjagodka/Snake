//
// Created by cyryl on 28.11.19.
//

#ifndef SNAKE_BOARD_H
#define SNAKE_BOARD_H

#include "field.h"
#include "coords.h"
#include <vector>

#define GROW_LEN 2
#define ROWS 9
#define COLUMNS 19

class Board {

public:
    Board(const Board &board);

    Field& getField(int column, int row);
    Field& getField(Coords coords);
    bool isAlive() const;
    void move(direction moveDir);
    void init();
    static Board& getBoard();

private:
    Board();
    Field fields[COLUMNS][ROWS];
    bool alive;
    Coords head;
    Coords tail;
    Coords apple;
    int currentLength;
    int futureLength;
    void placeApple();
};

#endif //SNAKE_BOARD_H
