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
    bgAnim += 0.005;

    // --- DARK GRADIENT BACKGROUND ---
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.02); glVertex2f(0, 0);
    glColor3f(0.0, 0.0, 0.02); glVertex2f(800, 0);
    glColor3f(0.0, 0.02, 0.1); glVertex2f(800, 600);
    glColor3f(0.0, 0.02, 0.1); glVertex2f(0, 600);
    glEnd();

    // 2. STATIC STARS (For Detail)
    glPointSize(1);
    glBegin(GL_POINTS);
    for(int i=0; i<100; i++) {
        float pulse = 0.5 + sin(bgAnim * 10 + i) * 0.5;
        glColor4f(1, 1, 1, pulse);
        glVertex2f((i * 123) % 800, (i * 456) % 600);
    }
    glEnd();

    // 3. PRECISION CYBER GRID (Perspective)
    glLineWidth(1);
    for(int i=-15; i<=15; i++) {
        float alpha = 1.0 - (fabs(i)/15.0); // Side-e fade hobe
        glColor4f(0.0, 0.8, 1.0, alpha * 0.2);
        glBegin(GL_LINES);
        glVertex2f(400 + i*100, 0); // Bottom wide
        glVertex2f(400 + i*5, 600);  // Top vanishing point
        glEnd();
    }
}
   