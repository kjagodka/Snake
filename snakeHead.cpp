//
// Created by cyryl on 29.11.19.
//

#include "snakeHead.h"
#include "board.h"
#include "snakeBody.h"

Head::Head(const Coords &c, direction goingFrom) : SnakeSegment(c), goingFrom(goingFrom) {
    type = HEAD;
}

void Head::draw() const {
    drawMiddle();
    drawEdge(goingFrom);
}

void Head::move(direction moveDir) {
    Coords newCoords = coords;
    newCoords.move(moveDir);
    Board::getBoard().setEntity(newCoords, Board::getBoard().getEntity(coords)); //place head in new spot;
    Board::getBoard().setEntity(coords, std::make_shared<Body>(coords, goingFrom, moveDir)); //spawn body in place of head
    coords = newCoords;
    goingFrom = oppositeDirection(moveDir);

}
