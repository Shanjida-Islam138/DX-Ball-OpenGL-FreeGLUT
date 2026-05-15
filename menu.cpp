#include "menu.h"
#include "ui.h"
#include <GL/glut.h>
#include <math.h>
extern int mouse_x;
extern int mouse_y;
extern float anim;


void drawHugeTitle(float y, const char* txt) {
    glPushMatrix();
    
   
    glTranslatef(315, y, 0); 
    glScalef(3.5, 3.5, 1); 
    
    
    glColor3f(0.2, 0.1, 0.0); 
    glRasterPos2f(0.05, -0.05);
    for (int k = 0; txt[k] != '\0'; k++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, txt[k]);

    
    glColor3f(1.0, 0.5, 0.0);
    glRasterPos2f(0, 0); 
    for (int k = 0; txt[k] != '\0'; k++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, txt[k]);
        
    glPopMatrix();
}

void drawMenuButton(float x, float y, const char* txt, int active) {
    
    bool hovered = (mouse_x >= x && mouse_x <= x+300 && (600-mouse_y) >= y && (600-mouse_y) <= y+55);

    if (active || hovered) {
        if(hovered) glColor3f(1.0, 0.7, 0.0); 
        else glColor3f(1.0, 0.5, 0.0); 
        
        glRectf(x, y, x + 300, y + 55);
        
       
        glColor3f(1, 1, 1);
        glLineWidth(3);
        glBegin(GL_LINE_LOOP);
            glVertex2f(x, y); glVertex2f(x + 300, y);
            glVertex2f(x + 300, y + 55); glVertex2f(x, y + 55);
        glEnd();

       
        if(active){
            glBegin(GL_TRIANGLES);
                glVertex2f(x - 40, y + 27);
                glVertex2f(x - 15, y + 45);
                glVertex2f(x - 15, y + 10);
            glEnd();
        }
    } else {
       
        glColor3f(0.2, 0.2, 0.4);
        glBegin(GL_LINE_LOOP);
            glVertex2f(x, y); glVertex2f(x + 300, y);
            glVertex2f(x + 300, y + 55); glVertex2f(x, y + 55);
        glEnd();
    }
    
    glColor3f(1, 1, 1);
    glRasterPos2f(x + 60, y + 20);
    for (int j = 0; txt[j] != '\0'; j++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, txt[j]);
}

void drawPreviewBox() {
    
    float startX = 590; 
    float startY = 230;
    float width = 160; 
    float height = 150;

   
    glColor3f(0, 1, 1);
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
        glVertex2f(startX, startY); glVertex2f(startX + width, startY);
        glVertex2f(startX + width, startY + height); glVertex2f(startX, startY + height);
    glEnd();

   
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            glColor3f(0.2, 0.4, 0.8);
            glRectf(startX + 15 + j * 35, startY + 110 - i * 20, startX + 40 + j * 35, startY + 125 - i * 20);
        }
    }
 
    
    float ballX = startX + 80 + sin(anim) * 30;
    float ballY = startY + 60 + cos(anim * 1.5) * 15;
    
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i += 20) {
        float t = i * 3.1416 / 180;
        glVertex2f(ballX + cos(t) * 6, ballY + sin(t) * 6);
    }
    glEnd();

    glColor3f(1, 0.5, 0);
    glRectf(startX + 50, startY + 15, startX + 110, startY + 25);
}

void drawMenu() {
    anim += 0.04;
    drawStars(); 


   drawHugeTitle(440, "DX BALL");

    
    drawMenuButton(250, 330, "NEW GAME", 0);
    drawMenuButton(250, 255, "LEVEL SELECT", 0);
    drawMenuButton(250, 180, "EXIT", 0);

    drawPreviewBox();
}