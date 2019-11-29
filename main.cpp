#include <iostream>
#include "board.h"
#include "settings.h"
#include <GL/glut.h>
#include <mutex>

struct arrowStrokeCounter {
private:
    int strokes = 0;
    std::mutex lock;
public:
    void incr() {
        lock.lock();
        strokes++;
        lock.unlock();
    }
    int getStrokes() {
        lock.lock();
        int result = strokes;
        lock.unlock();
        return result;
    }
} counter;

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

void SpecialKeys(int key, int x, int y)
{
    switch (key)
    {
        case GLUT_KEY_LEFT:
            Board::getBoard().setMoveDirection(LEFT);
            counter.incr();
            tick(counter.getStrokes());
            break;
        case GLUT_KEY_RIGHT:
            Board::getBoard().setMoveDirection(RIGHT);
            counter.incr();
            tick(counter.getStrokes());
            break;
        case GLUT_KEY_UP:
            Board::getBoard().setMoveDirection(UP);
            counter.incr();
            tick(counter.getStrokes());
            break;
        case GLUT_KEY_DOWN:
            Board::getBoard().setMoveDirection(DOWN);
            counter.incr();
            tick(counter.getStrokes());
            break;
        default:
            break;
    }
}

void draw() {
    Board::getBoard().draw();
    glFlush();
    glutSwapBuffers();
}

void Reshape(int width, int height)
{
    int rows = Settings::getSettings().getRows();
    int columns = Settings::getSettings().getColumns();
    if(width * rows > height * columns) { //window is too WIDE
        int properWidth = height * columns / rows;
        glViewport((width - properWidth) / 2, 0, properWidth, height);
    } else if (width * rows < height * columns) {
        int properHeight = width * rows / columns;
        glViewport(0, (height - properHeight) / 2, width, properHeight);
    } else {
        glViewport(0, 0, width, height);
    }
    draw();
}

void drawerInit(int argc, char **argv) {
    glutInit(& argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Game of Snake");
    glutDisplayFunc(draw);
    glutReshapeFunc(Reshape);
    glutTimerFunc(500, tick, counter.getStrokes());
    glutCreateMenu(Menu);
    glutSpecialFunc(SpecialKeys);

    glutAddMenuEntry("EXIT", EXIT);
    glutAddMenuEntry("RESET", RESET);

    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutMainLoop();
}

void tick(int keyStrokes) {
    if (keyStrokes != counter.getStrokes())
        return; //this was old call from before previous tick;

    Board::getBoard().makeMove();
    draw();
    std::cout<<"tick\n";
    glutTimerFunc(Settings::getSettings().getTickDelayMs(), tick, keyStrokes);
}



int main(int argc, char * argv[] )
{
    drawerInit(argc, argv);
    draw();
    //glutTimerFunc(500, tick, 0);
}
