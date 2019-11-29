#include <utility>

#include <utility>

#include "board.h"
#include "void.h"
#include "wall.h"
#include "apple.h"
#include "snakeTail.h"
#include "snakeBody.h"
#include "snakeHead.h"
#include "settings.h"
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

void Board::setMoveDirection(direction moveDirection) {
    Board::moveDirection = moveDirection;
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


void Board::resize() {
    rows = Settings::getSettings().getRows();
    columns = Settings::getSettings().getColumns();

    entities = std::vector< std::vector < std::shared_ptr < Entity > > >(columns);
    for (int column = 0; column < columns; column++) {
        entities[column] = std::vector< std::shared_ptr < Entity > >(rows);
    }
}

void Board::clearBoard() {
    for (int column = 0; column < columns; column++) {
        for (int row = 0; row < rows; row++)
            entities[column][row] = std::make_shared<Void>(Coords(column, row));
    }
}

void Board::spawnWalls() {
    for (int column = 0; column < columns; column++) {
        entities[column][0] = std::make_shared<Wall>(Coords(column, 0)); //bottom wall
        entities[column][rows - 1] = std::make_shared<Wall>(Coords(column, rows - 1)); //top wall
    }

    for (int row = 1; row < rows - 1; row++) {
        entities[0][row] = std::make_shared<Wall>(Coords(0, row)); //left wall
        entities[columns - 1][row] = std::make_shared<Wall>(Coords(columns - 1, row)); //right wall
    }
}

void Board::spawnSnake() {
    snakeLen = Settings::getSettings().getStartLength();
    futureSnakeLen = snakeLen;
    Coords position(columns / 2, rows / 2);
    for (int i = 0; i < snakeLen / 2; i++) {
        position.move(RIGHT); //go to Head position
    }

    head = std::make_shared<Head>(position, LEFT);
    setEntity(position, head);

    for (int i = 0; i < snakeLen - 2; i++) {
        position.move(LEFT);
        setEntity(position, std::make_shared<Body>(position, LEFT, RIGHT));
    } //spawn snakeLen - 2 segments of body;

    position.move(LEFT); //move to tail position
    tail = std::make_shared<Tail>(position, RIGHT);
    setEntity(position, tail);
}


int mod(int a, int b) {
    return (a%b+b)%b;
}

void Board::spawnApple() {
    int boardSize;
    if (Settings::getSettings().getWallsExist()) {
        boardSize = (rows - 2) * (columns - 2);
    } else {
        boardSize = rows * columns;
    }

    if (futureSnakeLen >= boardSize)
        return; //snake would grow too much

    Coords applePosition;
    do {
        applePosition = Coords(mod(rand(), columns), mod(rand(), rows));

    } while (getEntity(applePosition)->getType() != VOID); //random position untill fouind empty space
    setEntity(applePosition, std::make_shared<Apple>(applePosition));
}


void Board::reset() {
    if (Settings::getSettings().getRows() != rows || Settings::getSettings().getColumns() != columns) {
        resize();
    }

    clearBoard(); //fills board with Void

    if (Settings::getSettings().getWallsExist()) {
        spawnWalls();
    }
    spawnSnake();
    spawnApple();

    moveDirection = RIGHT;

}

Board::Board() : columns(Settings::getSettings().getColumns()), rows(Settings::getSettings().getRows()){
    resize();
    reset();
}


void Board::setEntity(Coords c, std::shared_ptr<Entity> entity) {
    entities[c.getColumn()][c.getRow()] = std::move(entity);
}

std::shared_ptr<Entity> Board::getEntity(Coords &c) const{
    return entities[c.getColumn()][c.getRow()];
}

bool Board::makeMove() {
    Coords newHeadCoords = head->getCoords();
    newHeadCoords.move(moveDirection);

    if(!isMoveSafe(newHeadCoords))
        return false;


    if (getEntity(newHeadCoords)->getType() == APPLE) {
        futureSnakeLen += Settings::getSettings().getGrowthLen();
        spawnApple();
    }

    if (futureSnakeLen == snakeLen)
        tail->move();
    else
        snakeLen++;

    head->move(moveDirection);

}

bool Board::isMoveSafe(Coords newHeadPosition) const {
    if (newHeadPosition.getColumn() < 0 ||
        newHeadPosition.getColumn() >= columns ||
        newHeadPosition.getRow() < 0 ||
        newHeadPosition.getRow() >= rows)
        return false;
    if (getEntity(newHeadPosition)->getType() == WALL)
        return false;
    if (getEntity(newHeadPosition)->getType() == BODY)
        return false;
    if (getEntity(newHeadPosition)->getType() == TAIL && futureSnakeLen > snakeLen)
        return false;
    else
        return true;
}