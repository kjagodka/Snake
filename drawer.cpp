//
// Created by cyryl on 28.11.19.
//
#include <GL/glut.h>
#include "drawer.h"
#include <iostream>

void setBoardColor() {
    glColor3f(0.0, 0.0, 0.0);
}

void setSnakeColor() {
    glColor3f(0.0, 1.0, 0.0);
}

void setAppleColor() {
    glColor3f(1.0, 0.0, 0.0);
}

void drawBackground() {
    glClearColor(0.1, 0.1, 0.1, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    setBoardColor();
    glBegin(GL_POLYGON);

    glVertex3f(-1.0, -1.0, 0.0);
    glVertex3f(-1.0, 1.0, 0.0);
    glVertex3f(1.0, 1.0, 0.0);
    glVertex3f(1.0, -1.0, 0.0);

    glEnd();
}



void drawApple(int column, int row) {
    std::cout<<"DRAWING APPLE\n";
    setAppleColor();
    drawRectangleInField(column, row, (1.0 - APPLE_SIZE) / 2.0, (1.0 - APPLE_SIZE) / 2.0, APPLE_SIZE, APPLE_SIZE);
}


void drawBoard()
{
    drawBackground();
    for (int column = 0; column < COLUMNS; column ++) {
        for (int row = 0; row < ROWS; row ++) {
            std::cout<<"C"<<column<<"R"<<row<<std::endl;
            Field field = Board::getBoard().getField(column, row);
            switch (field.getType()) {
                case EMPTY:
                    break;
                case APPLE:
                    drawApple(column, row);
                    break;
                case HEAD:
                    drawSnakeSegment(column, row, field.getFrom(), NONE);
                    break;
                case BODY:
                    drawSnakeSegment(column, row, field.getFrom(), field.getTo());
                    break;
                case TAIL:
                    drawSnakeSegment(column, row, NONE, field.getTo());
                    break;
                default:
                    break;
            }
        }
    }

    glFlush();
    glutSwapBuffers();
}