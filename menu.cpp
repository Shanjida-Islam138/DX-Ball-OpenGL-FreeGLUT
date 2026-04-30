#include "menu.h"
#include "ui.h"
#include <GL/glut.h>

void drawMenu(){

    // Title
    glColor3f(1,1,0);
    drawText(320,500,"DX BALL");

    // Buttons
    glColor3f(0,1,1);
    drawText(300,400,"[1] Start Game");

    glColor3f(0,1,0);
    drawText(300,350,"[2] Level Select");

    glColor3f(1,0,0);
    drawText(300,300,"[3] Exit");

    glColor3f(1,1,1);
    drawText(250,200,"Press key to continue...");
}