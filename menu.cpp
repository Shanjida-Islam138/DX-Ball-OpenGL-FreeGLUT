#include "menu.h"
#include "ui.h"

#include <GL/glut.h>
#include <math.h>

float menuAnim = 0;

void drawCircle3D(float cx,float cy,float r){

    // OUTER SHADOW
    glColor4f(0,0,0,0.4);

    glBegin(GL_POLYGON);

    for(int i=0;i<360;i++){

        float t=i*3.1416/180;

        glVertex2f(
            cx+cos(t)*(r+8),
            cy+sin(t)*(r+8)
        );
    }

    glEnd();

    // MAIN BALL
    glBegin(GL_POLYGON);

    for(int i=0;i<360;i++){

        float t=i*3.1416/180;

        // glossy red-white effect
        if(i%40<20)
            glColor3f(0.0,0.8,1.0);
        else
            glColor3f(0.0,0.4,0.7);

        glVertex2f(
            cx+cos(t)*r,
            cy+sin(t)*r
        );
    }

    glEnd();

    // LIGHT REFLECTION
    glColor4f(1,1,1,0.4);

    glBegin(GL_POLYGON);

    for(int i=0;i<360;i++){

        float t=i*3.1416/180;

        glVertex2f(
            cx-20+cos(t)*18,
            cy+20+sin(t)*18
        );
    }

    glEnd();
}

void drawPanel() {
    // Glass Effect Header
    glColor4f(0, 0.4, 0.6, 0.1);
    glRectf(200, 450, 600, 550);

    // Modern Corner Brackets (Box bad)
    glLineWidth(3);
    glColor3f(0, 1, 1);
    glBegin(GL_LINE_STRIP); // Left Bracket
    glVertex2f(230, 450); glVertex2f(200, 450); glVertex2f(200, 550); glVertex2f(230, 550);
    glEnd();
    glBegin(GL_LINE_STRIP); // Right Bracket
    glVertex2f(570, 450); glVertex2f(600, 450); glVertex2f(600, 550); glVertex2f(570, 550);
    glEnd();
}

void drawButton(float x, float y, const char* txt, float r, float g, float b) {
    // Underline Glow
    glLineWidth(2);
    glColor4f(r, g, b, 0.8);
    glBegin(GL_LINES);
    glVertex2f(x, y-5); glVertex2f(x+250, y-5); 
    glEnd();

    // Side Accents
    glBegin(GL_LINES);
    glVertex2f(x, y-5); glVertex2f(x, y+10);
    glVertex2f(x+250, y-5); glVertex2f(x+250, y+10);
    glEnd();

    // Text (Bright & Clean)
    glColor3f(1, 1, 1);
    drawText(x+65, y+15, txt);
}

// Side-er colorful bricks drawing logic
void drawBricksDecor() {
    float colors[6][3] = {
        {1.0, 0.0, 0.5}, // Pink
        {1.0, 0.0, 0.0}, // Red
        {1.0, 0.5, 0.0}, // Orange
        {1.0, 1.0, 0.0}, // Yellow
        {0.0, 1.0, 0.0}, // Green
        {0.0, 1.0, 1.0}  // Cyan
    };

    for(int i = 0; i < 6; i++) {
        glColor3fv(colors[i]);
        
        // Left Side Stacked Bricks
        glRectf(0, 500 - i * 45, 60, 540 - i * 45);
        
        // Right Side Stacked Bricks
        glRectf(740, 500 - i * 45, 800, 540 - i * 45);
    }
}

void drawMenu() {
    menuAnim += 0.03;
    drawBricksDecor(); // Side-er colorful bricks
    drawPanel();

    // Text Setup
    glColor3f(1, 1, 1);
    drawText(350, 510, "DX BALL");
    glColor3f(0, 1, 1);
    drawText(315, 475, "CYBER EDITION");

    // HUD Buttons (Position update)
    drawButton(275, 330, "START GAME", 0, 0.8, 1);
    drawButton(275, 250, "LEVEL SELECT", 0, 1, 0.4);
    drawButton(275, 170, "EXIT GAME", 1, 0.2, 0.3);

    // High-Detail Footer
    glColor4f(1, 1, 1, 0.4);
    drawText(270, 70, "OPENGL DX BALL - ULTIMATE ARCADE");
    drawText(360, 40, "PRESS 1 / 2 / 3");
}