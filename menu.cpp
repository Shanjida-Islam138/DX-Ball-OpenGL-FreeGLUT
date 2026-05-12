#include <GL/glut.h>
#include "menu.h"
#include "ui.h"

float glow=0;

void drawMenu(){

    glow += 0.01;

    glColor3f(1,1,0);
    drawText(300,520,"DX BALL ARCADE");

    glColor3f(0,1,1);
    drawText(300,420,"[1] START GAME");

    glColor3f(0,1,0);
    drawText(300,360,"[2] LEVEL SELECT");

    glColor3f(1,0,0);
    drawText(300,300,"[3] EXIT");

    glColor3f(1,1,1);
    drawText(220,180,"CREATED USING OPENGL + FREEGLUT");

    glColor3f(1,1,1);
    drawText(250,140,"PRESS KEY TO CONTINUE");
}