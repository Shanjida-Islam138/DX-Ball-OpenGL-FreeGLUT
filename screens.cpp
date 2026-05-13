#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include "screens.h"
#include "ui.h"
#include "game.h"
#include "levels.h"

void drawGameScreen(){

    char txt[100];

    glColor3f(1,1,1);

    sprintf(txt,"Score : %d",score);
    drawText(20,570,txt);

    sprintf(txt,"Lives : %d",lives);
    drawText(650,570,txt);

    sprintf(txt,"Level : %d",currentLevel);
    drawText(350,570,txt);

    glColor3f(0,1,0);
    glRectf(paddleX,20,paddleX+100,40);

    glColor3f(1,0,0);

    glBegin(GL_POLYGON);

    for(int i=0;i<360;i++){

        float t=i*3.1416/180;
                glVertex2f(ballX+cos(t)*10,
                   ballY+sin(t)*10);
    }

    glEnd();

    drawBricks();
}

void drawLevelScreen(){

    glColor3f(1,1,1);
    drawText(300,500,"SELECT LEVEL");

    glColor3f(0,1,1);
    drawText(300,400,"PRESS 1 : LEVEL 1");

    glColor3f(1,0.4,0);
    drawText(300,340,"PRESS 2 : LEVEL 2");

    glColor3f(1,0,1);
    drawText(300,280,"PRESS 3 : LEVEL 3");
}

void drawGameOver(){

    glColor3f(1,0,0);
    drawText(320,350,"GAME OVER");

    glColor3f(1,1,1);
    drawText(250,280,"PRESS M TO RETURN MENU");
}
