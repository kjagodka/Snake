#include <iostream>
#include "drawer.h"
#include "board.h"
#include <GL/glut.h>



enum{EXIT, RESET};
void Menu(int menuOption)
{
    switch(menuOption)
    {
        case EXIT:
            exit(0);
        case RESET:
            Board::getBoard().reset();
            break;
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

void drawerInit(int argc, char **argv) {
    glutInit(& argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(1650, 950);

    glutCreateWindow("Kwadrat 1");

    glutDisplayFunc(drawBoard);

    glutReshapeFunc(Reshape);

    glutTimerFunc(500, tick, 0);


    glutCreateMenu(Menu);

    glutAddMenuEntry("EXIT", EXIT);
    glutAddMenuEntry("RESET", RESET);

    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutMainLoop();
}

void tick(int time) {
    glutTimerFunc(500, tick, 0);
    drawBoard();
}



int main(int argc, char * argv[] )
{
    drawerInit(argc, argv);

}
