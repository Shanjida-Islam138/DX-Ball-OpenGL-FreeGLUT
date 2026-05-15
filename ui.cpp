#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>

#include "ui.h"
float anim = 0; 

float bgAnim = 0;

void drawText(float x,float y,const char* text){

    glRasterPos2f(x,y);

    for(int i=0;text[i]!='\0';i++){

        glutBitmapCharacter(
            GLUT_BITMAP_HELVETICA_18,
            text[i]
        );
    }
}

float starY[25] = {600, 550, 500, 450, 400, 350, 300, 250, 200, 150, 580, 480, 380, 280, 180, 520, 420, 320, 220, 120, 590, 490, 390, 290, 190};
float starX[25] = {100, 200, 300, 400, 500, 600, 700, 50, 150, 250, 350, 450, 550, 650, 750, 120, 220, 420, 620, 720, 30, 130, 230, 330, 430};

void drawStars() {
    glColor3f(0.8, 0.8, 1.0); 
    glPointSize(1.5); 
    glBegin(GL_POINTS);
    for(int i = 0; i < 25; i++) {
        glVertex2f(starX[i], starY[i]);
        starY[i] -= 0.5; 
        if(starY[i] < 0) starY[i] = 600; 
    }
    glEnd();
}

void drawBackground(){

    // DARK WALL BACKGROUND
    glBegin(GL_QUADS);

    glColor3f(0.04,0.02,0.08);
    glVertex2f(0,0);

    glColor3f(0.08,0.03,0.12);
    glVertex2f(800,0);

    glColor3f(0.02,0.02,0.05);
    glVertex2f(800,600);

    glColor3f(0.05,0.02,0.08);
    glVertex2f(0,600);

    glEnd();

    // BRICK WALL
    for(int y=0;y<600;y+=40){

        for(int x=0;x<800;x+=90){

            float offset = (y/40)%2 ? 40 : 0;

            glColor3f(0.15,0.08,0.22);

            glRectf(
                x+offset,
                y,
                x+80+offset,
                y+35
            );

            // brick border glow
            glColor3f(0.3,0.1,0.5);

            glBegin(GL_LINE_LOOP);

            glVertex2f(x+offset,y);
            glVertex2f(x+80+offset,y);
            glVertex2f(x+80+offset,y+35);
            glVertex2f(x+offset,y+35);

            glEnd();
        }
    }

    // CYBER CORNERS

    glLineWidth(3);

    glColor3f(0,1,1);

    // top left
    glBegin(GL_LINES);

    glVertex2f(20,580);
    glVertex2f(120,580);

    glVertex2f(20,580);
    glVertex2f(20,500);

    glEnd();

    // top right
    glBegin(GL_LINES);

    glVertex2f(780,580);
    glVertex2f(680,580);

    glVertex2f(780,580);
    glVertex2f(780,500);

    glEnd();

    // bottom left
    glBegin(GL_LINES);

    glVertex2f(20,20);
    glVertex2f(120,20);

    glVertex2f(20,20);
    glVertex2f(20,100);

    glEnd();

    // bottom right
    glBegin(GL_LINES);

    glVertex2f(780,20);
    glVertex2f(680,20);

    glVertex2f(780,20);
    glVertex2f(780,100);

    glEnd();
}