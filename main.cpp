#include <GL/glut.h>
#include "ui.h"
#include "menu.h"
#include "screens.h"
#include "input.h"
#include "game.h"

int gameState=0;
void display(){

    glClear(GL_COLOR_BUFFER_BIT);

    drawBackground();

    if(gameState==0)
        drawMenu();

    else if(gameState==1){

        if(lives<=0)
            drawGameOver();

        else
            drawGameScreen();
    }

    else if(gameState==2)
        drawLevelScreen();

    drawStars();
    glutSwapBuffers();
}

void timer(int v){

    if(gameState==1 && lives>0){
        updateGame();
    }

    glutPostRedisplay();
    glutTimerFunc(16,timer,0);
}

void init(){

    glClearColor(0,0,0,1);

    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,800,0,600);
}

int main(int argc,char** argv){

    glutInit(&argc,argv);
  
    glutPassiveMotionFunc(mouseMove);

   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(800,600);

    glutCreateWindow("DX BALL FULL PROJECT");

    init();

    glutDisplayFunc(display);

    glutKeyboardFunc(handleInput);

    glutSpecialFunc(handleSpecial);
    glutMouseFunc(mouseClick);
    glutPassiveMotionFunc(mouseMove);


    glutTimerFunc(0,timer,0);

    glutMainLoop();
}