//
// Created by cyryl on 28.11.19.
//

#include "board.h"
#include <cstdlib>

int mod(int a, int b)
{ return (a%b+b)%b; }

int Board::getRows() {
    return rows;
}

int Board::getColumns() {
    return columns;
}

Field& Board::getField(int column, int row) {
    return fields[column][row];
}

Field &Board::getField(Coords coords) {
    int column = coords.getColumn();
    int row = coords.getRow();
    return getField(column, row);
}


bool Board::isAlive() const {
    return alive;
}

void Board::placeApple() {
    int column, row;
    do {
        column = mod(rand(), columns);
        row = mod(rand(), rows);
    } while(!getField(column, row).setApple());

    apple.setColumn(column);
    apple.setRow(row);
}

void Board::init() {
    for (int column = 0; column < columns; column ++) {
        for (int row = 0; row < rows; row++) {
            getField(column, row).setEmpty();
        }
    }
    int midcol = columns / 2;
    int midrow = rows / 2;
    getField(midcol - 2, midrow).setTail(RIGHT);
    getField(midcol - 1, midrow).setBody(LEFT, RIGHT);
    getField(midcol, midrow).setBody(LEFT, RIGHT);
    getField(midcol + 1, midrow).setBody(LEFT, RIGHT);
    getField(midcol + 2, midrow).setHead(LEFT);
    currentLength = 5;
    futureLength = 5;
    placeApple();
}

void Board::move(direction moveDir) {
    Coords newHead = head;
    newHead.move(moveDir);
    if (newHead.getColumn() >= columns ||
        newHead.getColumn() < 0 ||
        newHead.getRow() >= rows ||
        newHead.getRow() < 0 ||
        getField(newHead).getType() == BODY ||
        (getField(newHead).getType() == TAIL && futureLength > currentLength))
    {
        alive = false; //[*]
        return;
    }

    getField(head).setBody(moveDir);
    getField(newHead).setHead(oppositeDirection(moveDir));
    head = newHead;

    if (newHead == apple) {
        futureLength += GROW_LEN;
        placeApple();
    }

    if (futureLength > currentLength) {
        currentLength++;
    }
    else
    {
        Coords newTail = tail;
        newTail.move(getField(tail).getTo());
        getField(tail).setEmpty();
        getField(newTail).setTail();
        tail = newTail;
    }
}