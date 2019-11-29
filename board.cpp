#include "board.h"
#include "void.h"
#include "wall.h"
#include "snakeTail.h"
#include "snakeBody.h"
#include "snakeHead.h"
#include <iostream>
#include <GL/gl.h>


int Board::getColumns() const {
    return columns;
}

int Board::getRows() const {
    return rows;
}

Board &Board::getBoard(){
    static Board singleton = Board();
    return singleton;
}

void Board::draw() const {
    glClearColor(0.1, 0.1, 0.1, 1.0); //grey
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0, 0.0, 0.0); //black
    glBegin(GL_POLYGON);

    glVertex3f(-1.0, -1.0, 0.0);
    glVertex3f(-1.0, 1.0, 0.0);
    glVertex3f(1.0, 1.0, 0.0);
    glVertex3f(1.0, -1.0, 0.0);

    glEnd();

    for (int c = 0; c < columns; c++) {
        for (int r = 0; r < rows; r++) {
            entities[c][r]->draw();
        }
    }
}


void Board::resize(int columns, int rows) {
    std::cout<<"resize"<<std::endl;
    Board::columns = columns;
    Board::rows = rows;
    entities = std::vector < std::vector < std::shared_ptr < Entity > > >(columns);
    entities.resize(columns);
    for (int c = 0; c < columns; c++) {
        entities[c] = std::vector < std::shared_ptr < Entity > >(rows);
        for (int r = 0; r < rows; r++) {
            std::cout<<c<<" "<<r<<std::endl;
            entities[c][r] = std::make_shared<Entity>(Coords(c, r));
        }
    }
}

void Board::init() {
    for (int col = 0; col < columns; col++) {
        entities[col].resize(rows);
        for (int row = 0; row < rows; row++) {
            if (row > 0 && row < rows - 1 && col > 0 && col < columns - 1)
                entities[col][row] = std::make_shared<Void>(Coords(col, row));
            else
                entities[col][row] = std::make_shared<Wall>(Coords(col, row));
        }
    }
    int midCol = columns / 2;
    int midRow = rows / 2;

    entities[midCol - 2][midRow] = std::make_shared<SnakeTail>(Coords(midCol - 2, midRow), RIGHT);
    entities[midCol - 1][midRow] = std::make_shared<SnakeBody>(Coords(midCol - 1, midRow), RIGHT, LEFT);
    entities[midCol][midRow] = std::make_shared<SnakeBody>(Coords(midCol, midRow), RIGHT, LEFT);
    entities[midCol + 1][midRow] = std::make_shared<SnakeBody>(Coords(midCol + 1, midRow), RIGHT, LEFT);
    entities[midCol + 2][midRow] = std::make_shared<SnakeHead>(Coords(midCol + 2, midRow), LEFT);

}

Board::Board() : rows(ROWS), columns(COLUMNS){
    resize(columns, rows);
    init();
}
