//
// Created by cyryl on 28.11.19.
//

#include "coords.h"

direction oppositeDirection(direction dir) {
    switch(dir) {
        case UP:
            return DOWN;
        case DOWN:
            return UP;
        case LEFT:
            return RIGHT;
        case RIGHT:
            return LEFT;
        default:
            return NONE;
    }
}

int Coords::getColumn() const {
    return column;
}

int Coords::getRow() const {
    return row;
}

void Coords::move(direction dir) {
    switch(dir) {
        case UP:
            row++;
            return;
        case DOWN:
            row--;
            return;
        case RIGHT:
            column++;
            return;
        case LEFT:
            column--;
            return;
        default:
            return;
    }
}

void Coords::setRow(int row) {
    Coords::row = row;
}

void Coords::setColumn(int column) {
    Coords::column = column;
}

bool Coords::operator==(const Coords &other) {
    return this->column == other.column && this->row == other.row;

}
