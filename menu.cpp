#include "menu.h"
#include "ui.h"
#include <GL/glut.h>
#include <math.h>

float anim = 0;


void drawHugeTitle(float x, float y, const char* txt) {
    
    for (float i = -4; i <= 4; i += 1.0) {
        for (float j = -4; j <= 4; j += 1.0) {
            glColor4f(0.5, 0.0, 1.0, 0.1); 
            glRasterPos2f(x + i, y + j);
            for (int k = 0; txt[k] != '\0'; k++)
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, txt[k]);
        }
    }

   
    for (float i = -1.5; i <= 1.5; i += 0.5) {
        glColor3f(0.0, 0.8, 1.0); 
        glRasterPos2f(x + i, y + i);
        for (int k = 0; txt[k] != '\0'; k++)
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, txt[k]);
    }

    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2f(x, y);
    for (int k = 0; txt[k] != '\0'; k++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, txt[k]);
}

void fireText(float x, float y, const char* txt, bool isHeadline = false) {
    if (isHeadline) {
        drawHugeTitle(x, y, txt);
    } else {
      
        glColor3f(0.0, 0.0, 0.0);
        glRasterPos2f(x + 1, y - 1);
        for (int j = 0; txt[j] != '\0'; j++)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, txt[j]);

        glColor3f(1.0, 1.0, 1.0);
        glRasterPos2f(x, y);
        for (int j = 0; txt[j] != '\0'; j++)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, txt[j]);
    }
}

void drawMenuButton(float x, float y, const char* txt, int active) {
    if (active) {
      
        glColor3f(1.0, 0.5, 0.0);
        glRectf(x, y, x + 300, y + 55); 

      
        glColor3f(1, 1, 0);
        glLineWidth(2);
        glBegin(GL_LINE_LOOP);
            glVertex2f(x, y); glVertex2f(x + 300, y);
            glVertex2f(x + 300, y + 55); glVertex2f(x, y + 55);
        glEnd();

       
        glColor3f(1, 1, 1);
        glBegin(GL_TRIANGLES);
            glVertex2f(x - 35, y + 27);
            glVertex2f(x - 10, y + 42);
            glVertex2f(x - 10, y + 12);
        glEnd();
    }
    fireText(x + 35, y + 18, txt, false);
}

void drawPreviewBox() {
    float startX = 580; 
    float startY = 220;


    glColor3f(0.05, 0.05, 0.1);
    glRectf(startX, startY, startX + 220, startY + 200);

  
    glColor3f(0, 1, 1);
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
        glVertex2f(startX, startY); glVertex2f(startX + 220, startY);
        glVertex2f(startX + 220, startY + 200); glVertex2f(startX, startY + 200);
    glEnd();

   
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            glColor3f(0.2, 0.4, 0.8);
            glRectf(startX + 15 + j * 50, startY + 150 - i * 30, startX + 55 + j * 50, startY + 170 - i * 30);
        }
    }
  
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i += 20) {
        float t = i * 3.1416 / 180;
        glVertex2f(startX + 110 + cos(t) * 9, startY + 65 + sin(t) * 9);
    }
    glEnd();
    glColor3f(1, 0.5, 0);
    glRectf(startX + 70, startY + 25, startX + 150, startY + 35);
}

void drawMenu() {
    anim += 0.03;

   
 
    fireText(320, 500, "DX BALL", true);


    

    
    drawMenuButton(230, 340, "NEW GAME", 1);
    drawMenuButton(230, 260, "LEVEL SELECT", 0);
    drawMenuButton(230, 180, "EXIT", 0);

    
    drawPreviewBox();

   
    fireText(300, 70, "OPENGL DX BALL PROJECT", false);
}