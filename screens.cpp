#include <GL/glut.h>
#include <math.h>
#include "screens.h"
#include "ui.h"

void drawGameScreen(){

    // Score + Level
    glColor3f(1,1,1);
    drawText(20,570,"Score: 0");
    drawText(650,570,"Level: 1");

    // Paddle
    glColor3f(0,1,0);
    glRectf(350,20,450,40);

    // Ball
    glColor3f(1,0,0);
    glBegin(GL_POLYGON);
    for(int i=0;i<360;i++){
        float t=i*3.14/180;
        glVertex2f(400+cos(t)*10,300+sin(t)*10);
    }
    glEnd();

    // Fake bricks (UI only)
    for(int i=0;i<5;i++){
        for(int j=0;j<10;j++){
            glColor3f(1,1,0);
            glRectf(j*80,500-i*30,j*80+70,500-i*30+20);
        }
    }
}

void drawLevelScreen(){

    glColor3f(1,1,1);
    drawText(300,500,"SELECT LEVEL");

    glColor3f(0,1,1);
    drawText(300,400,"Press 1 - Level 1");

    glColor3f(0,1,0);
    drawText(300,350,"Press 2 - Level 2");

    glColor3f(1,0,0);
    drawText(300,300,"Press 3 - Level 3");
}