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

void drawBackground() {
    bgAnim += 0.002;

    // SIMPLE DARK GRADIENT (no line artifacts)
    glBegin(GL_QUADS);

    glColor3f(0.02f, 0.02f, 0.05f);
    glVertex2f(0, 0);

    glColor3f(0.02f, 0.02f, 0.05f);
    glVertex2f(800, 0);

    glColor3f(0.05f, 0.06f, 0.10f);
    glVertex2f(800, 600);

    glColor3f(0.05f, 0.06f, 0.10f);
    glVertex2f(0, 600);

    glEnd();

    // VERY SUBTLE SOFT STARS (optional, no flicker)
    glPointSize(1);
    glBegin(GL_POINTS);

    for(int i = 0; i < 60; i++) {
        float x = (i * 137) % 800;
        float y = (i * 211) % 600;

        float alpha = 0.2f + 0.1f * sin(bgAnim + i);

        glColor4f(1.0f, 1.0f, 1.0f, alpha);
        glVertex2f(x, y);
    }

    glEnd();
}