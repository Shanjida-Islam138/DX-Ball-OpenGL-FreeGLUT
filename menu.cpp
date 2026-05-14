#include "menu.h"
#include "ui.h"

#include <GL/glut.h>
#include <math.h>

float menuAnim = 0;

void drawCircle3D(float cx,float cy,float r){

    // OUTER SHADOW
    glColor4f(0,0,0,0.4);

    glBegin(GL_POLYGON);

    for(int i=0;i<360;i++){

        float t=i*3.1416/180;

        glVertex2f(
            cx+cos(t)*(r+8),
            cy+sin(t)*(r+8)
        );
    }

    glEnd();

    // MAIN BALL
    glBegin(GL_POLYGON);

    for(int i=0;i<360;i++){

        float t=i*3.1416/180;

        // glossy red-white effect
        if(i%40<20)
            glColor3f(0.9,0.1,0.1);
        else
            glColor3f(0.95,0.95,0.95);

        glVertex2f(
            cx+cos(t)*r,
            cy+sin(t)*r
        );
    }

    glEnd();

    // LIGHT REFLECTION
    glColor4f(1,1,1,0.4);

    glBegin(GL_POLYGON);

    for(int i=0;i<360;i++){

        float t=i*3.1416/180;

        glVertex2f(
            cx-20+cos(t)*18,
            cy+20+sin(t)*18
        );
    }

    glEnd();
}

void drawPanel(){

    // OUTER METAL
    glColor3f(0.7,0.7,0.75);

    glRectf(180,430,620,540);

    // INNER DARK
    glColor3f(0.02,0.02,0.02);

    glRectf(195,445,605,525);

    // GLOW BORDER
    glLineWidth(4);

    glColor3f(0,0.8,1);

    glBegin(GL_LINE_LOOP);

    glVertex2f(195,445);
    glVertex2f(605,445);
    glVertex2f(605,525);
    glVertex2f(195,525);

    glEnd();
}

void drawButton(float x,float y,
                const char* txt,
                float r,float g,float b)
{
    // GLOW
    glColor4f(r,g,b,0.2);

    glRectf(x-5,y-5,x+260,y+55);

    // BUTTON BODY
    glColor3f(r,g,b);

    glRectf(x,y,x+250,y+50);

    // INNER
    glColor3f(0.03,0.03,0.03);

    glRectf(x+4,y+4,x+246,y+46);

    // TEXT
    glColor3f(1,1,1);

    drawText(x+55,y+18,txt);
}

void drawMenu(){

    menuAnim += 0.03;

    // MAIN PANEL
    drawPanel();

    // TITLE
    float pulse = fabs(sin(menuAnim));

    glColor3f(0.8+pulse*0.2,
              0.8+pulse*0.2,
              1);

    drawText(285,485,"CYBER DX-BALL");

    // SIDE LIGHTS
    glColor4f(1,1,1,0.25);

    for(int i=0;i<360;i++){

        float t=i*3.1416/180;

        glBegin(GL_POLYGON);

        glVertex2f(150+cos(t)*45,
                   485+sin(t)*45);

        glVertex2f(650+cos(t)*45,
                   485+sin(t)*45);

        glEnd();
    }

    // 3D BALL
    glPushMatrix();

    glTranslatef(610,230,0);

    glRotatef(menuAnim*40,0,0,1);

    drawCircle3D(0,0,75);

    glPopMatrix();

    // BUTTONS
    drawButton(220,320,
               "START GAME",
               0,0.6,1);

    drawButton(220,240,
               "LEVEL SELECT",
               0,0.9,0.5);

    drawButton(220,160,
               "EXIT GAME",
               1,0.2,0.2);

    // FOOTER
    glColor3f(0.8,0.8,0.8);

    drawText(240,90,
    "Mouse + Keyboard Supported");
}