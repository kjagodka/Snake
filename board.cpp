#include "board.h"


int Board::getColumns() const {
    return columns;
}

int Board::getRows() const {
    return rows;
}

Board &Board::getBoard(){
    static Board singleton;
    return singleton;
}

void Board::draw() const {
    for (int c = 0; c < columns; c++) {
        for (int r = 0; r < rows; r++) {
            entities[c][r].draw();
        }
    }
}


