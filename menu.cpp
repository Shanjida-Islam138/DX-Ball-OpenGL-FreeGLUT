#include "menu.h"
#include "ui.h"

#include <GL/glut.h>
#include <math.h>

float anim=0;

void neonText(float x,float y,const char* txt,
               float r,float g,float b){

    // glow
    glColor4f(r,g,b,0.2);

    for(int i=-3;i<=3;i++){

        glRasterPos2f(x+i,y);

        for(int j=0;txt[j]!='\0';j++)
            glutBitmapCharacter(
                GLUT_BITMAP_TIMES_ROMAN_24,
                txt[j]
            );
    }

    // main text
    glColor3f(r,g,b);

    glRasterPos2f(x,y);

    for(int j=0;txt[j]!='\0';j++)
        glutBitmapCharacter(
            GLUT_BITMAP_TIMES_ROMAN_24,
            txt[j]
        );
}

void drawMenuButton(float x,float y,
                    const char* txt,
                    int active){

    if(active){

        glColor3f(1,0.5,0);

        glRectf(x,y,x+320,y+55);

        glColor3f(1,1,0);

        glBegin(GL_LINE_LOOP);

        glVertex2f(x,y);
        glVertex2f(x+320,y);
        glVertex2f(x+320,y+55);
        glVertex2f(x,y+55);

        glEnd();

        // selector arrow
        glColor3f(1,1,1);

        glBegin(GL_TRIANGLES);

        glVertex2f(x-40,y+27);
        glVertex2f(x-10,y+45);
        glVertex2f(x-10,y+10);

        glEnd();
    }

    neonText(
        x+35,
        y+18,
        txt,
        1,
        1,
        1
    );
}

void drawPreviewBox(){

    glColor3f(0.1,0.1,0.2);

    glRectf(520,240,700,420);

    glColor3f(0,1,1);

    glBegin(GL_LINE_LOOP);

    glVertex2f(520,240);
    glVertex2f(700,240);
    glVertex2f(700,420);
    glVertex2f(520,420);

    glEnd();

    // fake game bricks
    for(int i=0;i<4;i++){

        for(int j=0;j<5;j++){

            glColor3f(
                0.3+j*0.1,
                0.2,
                1
            );

            glRectf(
                530+j*32,
                380-i*28,
                555+j*32,
                398-i*28
            );
        }
    }

    // ball
    glColor3f(1,1,1);

    glBegin(GL_POLYGON);

    for(int i=0;i<360;i++){

        float t=i*3.1416/180;

        glVertex2f(
            610+cos(t)*12,
            290+sin(t)*12
        );
    }

    glEnd();

    // paddle
    glColor3f(1,0.5,0);

    glRectf(560,250,650,265);
}

void drawMenu(){

    anim += 0.03;

    // TITLE
    neonText(
        190,
        520,
        "DX BALL",
        0.7,
        0.2,
        1
    );

    // electric line
    glColor3f(0,1,1);

    glBegin(GL_LINE_STRIP);

    for(int i=0;i<20;i++){

        glVertex2f(
            220+i*20,
            480+sin(anim+i)*10
        );
    }

    glEnd();

    // smiley
    glColor3f(1,1,0);

    glBegin(GL_POLYGON);

    for(int i=0;i<360;i++){

        float t=i*3.1416/180;

        glVertex2f(
            400+cos(t)*28,
            440+sin(t)*28
        );
    }

    glEnd();

    // eyes
    glColor3f(0,0,0);

    glPointSize(5);

    glBegin(GL_POINTS);

    glVertex2f(390,448);
    glVertex2f(410,448);

    glEnd();

    // smile
    glBegin(GL_LINE_STRIP);

    for(int i=200;i<340;i++){

        float t=i*3.1416/180;

        glVertex2f(
            400+cos(t)*12,
            435+sin(t)*12
        );
    }

    glEnd();

    // MENU BUTTONS
    drawMenuButton(
        230,
        340,
        "NEW GAME",
        1
    );

    drawMenuButton(
        230,
        270,
        "LEVEL SELECT",
        0
    );

    drawMenuButton(
        230,
        200,
        "EXIT",
        0
    );

    // preview image
    drawPreviewBox();

    // bottom info
    neonText(
        260,
        80,
        "OPENGL DX BALL",
        1,
        1,
        1
    );
}