//
// Created by cyryl on 29.11.19.
//

#include <memory>
#include <cassert>
#include "snakeTail.h"
#include "board.h"
#include "snakeBody.h"
#include "void.h"

Tail::Tail(const Coords &c, direction goingFrom) : SnakeSegment(c), goingTo(goingFrom) {
    type = TAIL;
}

direction Tail::getGoingTo() const {
    return goingTo;
}

void Tail::draw() const {
    drawMiddle();
    drawEdge(goingTo);
}

void Tail::move() {
    Coords newCoords = coords;
    newCoords.move(goingTo);

    std::shared_ptr<Entity> body = Board::getBoard().getEntity(newCoords);
    assert(body->getType() == BODY);
    goingTo = dynamic_cast<Body*>(body.get())->getGoingTo(); //getting move direction of body segment in front of tail

    Board::getBoard().setEntity(newCoords, Board::getBoard().getEntity(coords)); //place tail in new spot;
    Board::getBoard().setEntity(coords, std::make_shared<Void>(coords)); //spawn void in place of olc tail position
    coords = newCoords;
}
