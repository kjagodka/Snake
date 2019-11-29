//
// Created by cyryl on 29.11.19.
//

#ifndef SNAKE_WALL_H
#define SNAKE_WALL_H

#include "entity.h"

class Wall : public Entity {
public:
    void draw() const;
    Wall(Coords c);
};


#endif //SNAKE_WALL_H
