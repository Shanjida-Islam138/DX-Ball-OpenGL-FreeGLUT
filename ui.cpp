#include <GL/glut.h>
#include "ui.h"
#include "game.h"

void drawText(float x,float y,const char* text){

    glRasterPos2f(x,y);

    for(int i=0;text[i]!='\0';i++){
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,text[i]);
    }
}

void drawBackground(){

    glBegin(GL_QUADS);

    if(currentLevel==1){

        glColor3f(0.0,0.0,0.2);
        glVertex2f(0,0);

        glColor3f(0.0,0.0,0.4);
        glVertex2f(800,0);

        glColor3f(0.0,0.2,0.5);
        glVertex2f(800,600);

        glColor3f(0.0,0.0,0.1);
        glVertex2f(0,600);
    }

    else if(currentLevel==2){
        glColor3f(0.3,0.0,0.0);
        glVertex2f(0,0);

        glColor3f(0.5,0.1,0.0);
        glVertex2f(800,0);

        glColor3f(0.7,0.2,0.0);
        glVertex2f(800,600);

        glColor3f(0.2,0.0,0.0);
        glVertex2f(0,600);
    }

    else{

        glColor3f(0.1,0.0,0.2);
        glVertex2f(0,0);

        glColor3f(0.3,0.0,0.5);
        glVertex2f(800,0);

        glColor3f(0.1,0.0,0.3);
        glVertex2f(800,600);
            glColor3f(0.0,0.0,0.1);
        glVertex2f(0,600);
    }

    glEnd();
}