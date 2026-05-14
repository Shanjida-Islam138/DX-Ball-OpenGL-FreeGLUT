#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>

#include "ui.h"

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

void drawBackground(){

    bgAnim += 0.001;

    // =========================
    // MAIN DARK BACKGROUND
    // =========================

    glBegin(GL_QUADS);

    glColor3f(0.01,0.01,0.04);
    glVertex2f(0,0);

    glColor3f(0.03,0.03,0.10);
    glVertex2f(800,0);

    glColor3f(0.00,0.00,0.05);
    glVertex2f(800,600);

    glColor3f(0.05,0.00,0.10);
    glVertex2f(0,600);

    glEnd();

    // =========================
    // ANIMATED LIGHT LINES
    // =========================

    glLineWidth(2);

    for(int i=0;i<10;i++){

        float y = i * 70;

        glBegin(GL_LINES);

        glColor4f(0,0.8,1,0.25);

        glVertex2f(
            0,
            y + sin(bgAnim+i)*25
        );

        glVertex2f(
            800,
            y + 100 + sin(bgAnim+i)*25
        );

        glEnd();
    }

    // =========================
    // GLOWING STARS
    // =========================

    glPointSize(2);

    glBegin(GL_POINTS);

    for(int i=0;i<200;i++){

        float pulse =
        fabs(sin(bgAnim*20+i));

        glColor3f(
            0.5+pulse*0.5,
            0.5+pulse*0.5,
            1
        );

        glVertex2f(
            rand()%800,
            rand()%600
        );
    }

    glEnd();

    // =========================
    // CYBER GRID
    // =========================

    glLineWidth(1);

    glColor4f(0,0.4,1,0.08);

    for(int x=0;x<=800;x+=40){

        glBegin(GL_LINES);

        glVertex2f(x,0);
        glVertex2f(x,600);

        glEnd();
    }

    for(int y=0;y<=600;y+=40){

        glBegin(GL_LINES);

        glVertex2f(0,y);
        glVertex2f(800,y);

        glEnd();
    }

    // =========================
    // TOP GLOW PANEL
    // =========================

    glBegin(GL_QUADS);

    glColor4f(0,0.7,1,0.15);
    glVertex2f(0,560);

    glColor4f(0,0.2,0.5,0.05);
    glVertex2f(800,560);

    glColor4f(0,0,0,0);
    glVertex2f(800,600);

    glColor4f(0,0,0,0);
    glVertex2f(0,600);

    glEnd();

    // =========================
    // CORNER ENERGY GLOW
    // =========================

    for(int k=0;k<2;k++){

        float cx =
        (k==0)?0:800;

        float cy = 600;

        glBegin(GL_POLYGON);

        for(int i=0;i<360;i++){

            float t =
            i*3.1416/180;

            glColor4f(
                0,
                0.8,
                1,
                0.04
            );

            glVertex2f(
                cx + cos(t)*220,
                cy + sin(t)*220
            );
        }

        glEnd();
    }

    // =========================
    // BOTTOM FLOOR GLOW
    // =========================

    glBegin(GL_QUADS);

    glColor4f(0,0.6,1,0.10);
    glVertex2f(0,0);

    glColor4f(0,0.6,1,0.10);
    glVertex2f(800,0);

    glColor4f(0,0,0,0);
    glVertex2f(800,120);

    glColor4f(0,0,0,0);
    glVertex2f(0,120);

    glEnd();
}