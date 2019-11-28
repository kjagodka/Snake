//
// Created by cyryl on 28.11.19.
//
#include <GL/glut.h>
#include "drawer.h"
#include <iostream>

enum
{
    EXIT
};
void Menu(int value)
{
    switch(value)
    {
        case EXIT:
            exit(0);
    }
}

void Reshape(int width, int height)
{
    if(width * ROWS > height * COLUMNS) { //window is too WIDE
        int properWidth = height * COLUMNS / ROWS;
        glViewport((width - properWidth) / 2, 0, properWidth, height);
    } else if (width * ROWS < height * COLUMNS) {
        int properHeight = width * ROWS / COLUMNS;
        glViewport(0, (height - properHeight) / 2, width, properHeight);
    } else {
        glViewport(0, 0, width, height);
    }
    drawBoard();
}

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

void drawRectangleInField (int column, int row, float x, float y, float width, float height) {
    float fieldX = column * 2.0 / COLUMNS - 1.0;
    float fieldY = row * 2.0 / ROWS - 1.0;

    x = x * 2.0 / COLUMNS;
    y = y * 2.0 / ROWS;

    width = width * 2.0 / COLUMNS;
    height = height * 2.0 / ROWS;
    glRectf(fieldX + x, fieldY + y, fieldX + x + width, fieldY + y + height);
}

void drawApple(int column, int row) {
    std::cout<<"DRAWING APPLE\n";
    setAppleColor();
    drawRectangleInField(column, row, (1.0 - APPLE_SIZE) / 2.0, (1.0 - APPLE_SIZE) / 2.0, APPLE_SIZE, APPLE_SIZE);
}

void drawSnakeSegment (int column, int row, direction from, direction to) {
    setSnakeColor();

    //this draws middle portion of snake
    drawRectangleInField(column, row, (1.0 - SNAKE_WIDTH) / 2.0, (1.0 - SNAKE_WIDTH) / 2.0, SNAKE_WIDTH, SNAKE_WIDTH);

    if (from == DOWN || to == DOWN) {
        drawRectangleInField(column, row, (1.0 - SNAKE_WIDTH) / 2.0, 0.0, SNAKE_WIDTH, (1.0 - SNAKE_WIDTH) / 2.0);
    }
    if (from == LEFT || to == LEFT) {
        drawRectangleInField(column, row, 0.0, (1.0 - SNAKE_WIDTH) / 2.0, (1.0 - SNAKE_WIDTH) / 2.0, SNAKE_WIDTH);
    }
    if (from == UP || to == UP) {
        drawRectangleInField(column, row, (1.0 - SNAKE_WIDTH) / 2.0, 1.0 - (1.0 - SNAKE_WIDTH) / 2.0, SNAKE_WIDTH, (1.0 - SNAKE_WIDTH) / 2.0);
    }
    if (from == RIGHT || to == RIGHT) {
        drawRectangleInField(column, row, 1.0 - (1.0 - SNAKE_WIDTH) / 2.0, (1.0 - SNAKE_WIDTH) / 2.0, (1.0 - SNAKE_WIDTH) / 2.0, SNAKE_WIDTH);
    }

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

void drawerInit(int argc, char **argv) {
    glutInit(& argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(400, 800);

    glutCreateWindow("Kwadrat 1");

    glutDisplayFunc(drawBoard);

    glutReshapeFunc(Reshape);

    glutCreateMenu(Menu);


    glutAddMenuEntry("Wyjscie", EXIT);

    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutMainLoop();
}