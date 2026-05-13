#include <GL/glut.h>
#include <math.h>

#include "menu.h"
#include "ui.h"

float anim = 0;

void drawButton(float x,float y,
                const char* text,
                float r,float g,float b){

    // SHADOW
    glColor4f(0,0,0,0.4);

    glBegin(GL_QUADS);

    glVertex2f(x+5,y-5);
    glVertex2f(x+255,y-5);
    glVertex2f(x+255,y+55);
    glVertex2f(x+5,y+55);

    glEnd();

    // MAIN BUTTON
    glColor3f(r,g,b);

    glBegin(GL_QUADS);

    glVertex2f(x,y);
    glVertex2f(x+250,y);
    glVertex2f(x+250,y+50);
    glVertex2f(x,y+50);

    glEnd();

    // BORDER
    glColor3f(1,1,1);

    glBegin(GL_LINE_LOOP);

    glVertex2f(x,y);
    glVertex2f(x+250,y);
    glVertex2f(x+250,y+50);
    glVertex2f(x,y+50);

    glEnd();

    // TEXT
    glColor3f(1,1,1);

    drawText(x+60,y+18,text);
}

void drawMenu(){

    anim += 0.02;

    // TITLE GLOW
    float glow = 0.7 + fabs(sin(anim))*0.3;

    glColor3f(glow,glow,1);

    drawText(250,520,"DX BALL");

    glColor3f(0,1,1);

    drawText(220,480,"CYBER EDITION");

    // ROTATING BALL
    float bx = 650 + sin(anim)*20;
    float by = 430 + cos(anim)*10;

    glColor3f(1,0.2,0.2);

    glBegin(GL_POLYGON);

    for(int i=0;i<360;i++){

        float t=i*3.1416/180;

        glVertex2f(bx+cos(t)*35,
                   by+sin(t)*35);
    }

    glEnd();

    // INNER BALL LIGHT
    glColor3f(1,1,1);

    glBegin(GL_POLYGON);

    for(int i=0;i<360;i++){

        float t=i*3.1416/180;

        glVertex2f(bx+10+cos(t)*10,
                   by+10+sin(t)*10);
    }

    glEnd();

    // BUTTONS
    drawButton(270,340,
               "START GAME",
               0.0,0.4,1.0);

    drawButton(270,260,
               "LEVEL SELECT",
               0.0,0.7,0.4);

    drawButton(270,180,
               "EXIT GAME",
               0.8,0.1,0.1);

    // FOOTER
    glColor3f(0.8,0.8,0.8);

    drawText(170,70,
    "OPENGL DX BALL - ULTIMATE ARCADE");

    drawText(250,40,
    "PRESS 1 / 2 / 3");
}