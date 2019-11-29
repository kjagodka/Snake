#include <utility>

#include <utility>

#include "board.h"
#include "void.h"
#include "wall.h"
#include "apple.h"
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
    Board::columns = columns;
    Board::rows = rows;
    entities = std::vector < std::vector < std::shared_ptr < Entity > > >(columns);
    entities.resize(columns);
    for (int c = 0; c < columns; c++) {
        entities[c] = std::vector < std::shared_ptr < Entity > >(rows);
        for (int r = 0; r < rows; r++) {
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
    Coords c(columns / 2 - 2, rows / 2);

    tail = std::make_shared<Tail>(c, RIGHT);
    setEntity(c, tail);

    c.move(RIGHT);
    setEntity(c, std::make_shared<Body>(c, LEFT, RIGHT));
    c.move(RIGHT);
    setEntity(c, std::make_shared<Body>(c, LEFT, RIGHT));
    c.move(RIGHT);
    setEntity(c, std::make_shared<Body>(c, LEFT, RIGHT));
    c.move(RIGHT);

    head = std::make_shared<Head>(c, LEFT);
    setEntity(c, head);
    snakeLen = 5;
    futureSnakeLen = 5;

    placeApple();
}

Board::Board() : rows(ROWS), columns(COLUMNS){
    resize(columns, rows);
    init();
}


void Board::setEntity(Coords c, std::shared_ptr<Entity> entity) {
    entities[c.getColumn()][c.getRow()] = std::move(entity);
}

std::shared_ptr<Entity> Board::getEntity(Coords &c) const{
    return entities[c.getColumn()][c.getRow()];
}

bool Board::makeMove(direction moveDir) {
    Coords newHeadCoords = head->getCoords();
    newHeadCoords.move(moveDir);

    if(!isMoveSafe(newHeadCoords))
        return false;


    if (getEntity(newHeadCoords)->getType() == APPLE) {
        futureSnakeLen += APPLE_GROWTH_LEN;
        placeApple();
    }

    if (futureSnakeLen == snakeLen) //snake doesn't grow
        tail->move();
    else
        snakeLen++;

    head->move(moveDir);

}

bool Board::isMoveSafe(Coords newHeadPosition) const {
    if (getEntity(newHeadPosition)->getType() == WALL)
        return false;
    if (getEntity(newHeadPosition)->getType() == BODY)
        return false;
    if (getEntity(newHeadPosition)->getType() == TAIL && futureSnakeLen > snakeLen)
        return false;
    else
        return true;
}

int mod(int a, int b) {
    return (a%b+b)%b;
}

void Board::placeApple() {
    if (futureSnakeLen >= (columns - 1) * (rows - 1))
        return;
    Coords c;
    do {
        c = Coords(mod(rand(), columns), mod(rand(), rows));

    } while (getEntity(c)->getType() != VOID);
    setEntity(c, std::make_shared<Apple>(c));
}
