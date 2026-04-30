#include <GL/glut.h>
#include "ui.h"

void drawBackground(){

    glBegin(GL_QUADS);

    glColor3f(0.05,0.05,0.2);
    glVertex2f(0,0);

    glColor3f(0.1,0.1,0.4);
    glVertex2f(800,0);

    glColor3f(0.0,0.0,0.2);
    glVertex2f(800,600);

    glColor3f(0.2,0.2,0.5);
    glVertex2f(0,600);

    glEnd();
}

void drawText(float x,float y,const char* text){
    glRasterPos2f(x,y);
    for(int i=0;text[i]!='\0';i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,text[i]);
}