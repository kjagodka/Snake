//
// Created by cyryl on 28.11.19.
//

#include "coords.h"
#include "settings.h"

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
            break;
        case DOWN:
            row--;
            break;
        case RIGHT:
            column++;
            break;
        case LEFT:
            column--;
            break;
        default:
            break;
    }

    if (Settings::getSettings().isWrapBoard()) {
        if (row < 0)
            row = Settings::getSettings().getRows() - 1;
        if (row == Settings::getSettings().getRows())
            row = 0;
        if (column < 0)
            column = Settings::getSettings().getColumns() - 1;
        if (column == Settings::getSettings().getColumns())
            column = 0;

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

Coords::Coords(int column, int row) : row(row), column(column) {}
