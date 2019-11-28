//
// Created by cyryl on 28.11.19.
//
#include <GL/glut.h>
#include "drawer.h"

enum
{
    EXIT
};

void Display()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);

    glClear(GL_COLOR_BUFFER_BIT);


    glColor3f(1.0, 0.0, 0.0);


    glBegin(GL_POLYGON);

    glVertex3f(-1.0, -1.0, 0.0);
    glVertex3f(-1.0, 1.0, 0.0);
    glVertex3f(1.0, 1.0, 0.0);
    glVertex3f(1.0, -1.0, 0.0);

    glEnd();

    glFlush();

    glutSwapBuffers();
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

    Display();
}


void Menu(int value)
{
    switch(value)
    {
        case EXIT:
            exit(0);
    }
}

void drawerInit(int argc, char **argv) {
    glutInit(& argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(400, 800);

    glutCreateWindow("Kwadrat 1");

    glutDisplayFunc(Display);

    glutReshapeFunc(Reshape);

    glutCreateMenu(Menu);


    glutAddMenuEntry("Wyjscie", EXIT);

    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutMainLoop();
}