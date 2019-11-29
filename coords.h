//
// Created by cyryl on 28.11.19.
//

#ifndef SNAKE_COORDS_H
#define SNAKE_COORDS_H


enum direction{UP, DOWN, LEFT, RIGHT, NONE};

direction oppositeDirection(direction dir);

class Coords {
public:
    int getRow() const;
    int getColumn() const;
    void move(direction dir);
    void setRow(int row);
    void setColumn(int column);
    bool operator ==(const Coords &other);
private:
    int row;
    int column;
public:
};


#endif //SNAKE_COORDS_H
