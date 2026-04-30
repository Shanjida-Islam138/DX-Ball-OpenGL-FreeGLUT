#include <GL/glut.h>
#include "ui.h"
#include "menu.h"
#include "screens.h"
#include "input.h"

int gameState = 0;

void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    drawBackground();

    if(gameState == 0) drawMenu();
    else if(gameState == 1) drawGameScreen();
    else if(gameState == 2) drawLevelScreen();

    glFlush();
}

void init(){
    glClearColor(0,0,0,1);
    gluOrtho2D(0,800,0,600);
}

int main(int argc,char** argv){

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800,600);
    glutCreateWindow("DX BALL UI DEMO");

    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(handleInput);

    glutMainLoop();
}