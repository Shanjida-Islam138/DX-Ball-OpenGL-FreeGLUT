#include <GL/glut.h>
#include <math.h>

#include "ui.h"

float bgAnim = 0;

void drawText(float x,float y,const char* text){

    glRasterPos2f(x,y);

    for(int i=0;text[i]!='\0';i++){
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,text[i]);
    }
}

void drawBackground(){

    bgAnim += 0.001;

    // DARK CINEMATIC BACKGROUND
    glBegin(GL_QUADS);

    glColor3f(0.02,0.02,0.06);
    glVertex2f(0,0);

    glColor3f(0.04,0.04,0.12);
    glVertex2f(800,0);

    glColor3f(0.01,0.01,0.08);
    glVertex2f(800,600);

    glColor3f(0.0,0.0,0.03);
    glVertex2f(0,600);

    glEnd();

    // SMOOTH LIGHT LINES
    glLineWidth(2);

    for(int i=0;i<8;i++){

        float y = i*80;

        glBegin(GL_LINES);

        glColor4f(0,0.7,1,0.2);

        glVertex2f(0,y+sin(bgAnim+i)*20);

        glVertex2f(800,y+120+sin(bgAnim+i)*20);

        glEnd();
    }

    // CORNER GLOW
    glColor4f(0,0.8,1,0.08);

    for(int k=0;k<2;k++){

        float cx = (k==0)?0:800;
        float cy = 600;

        glBegin(GL_POLYGON);

        for(int i=0;i<360;i++){

            float t=i*3.1416/180;

            glVertex2f(cx+cos(t)*180,
                       cy+sin(t)*180);
        }

        glEnd();
    }
}