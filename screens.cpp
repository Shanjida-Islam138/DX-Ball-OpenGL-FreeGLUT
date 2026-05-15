#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include "screens.h"
#include "ui.h"
#include "game.h"
#include "levels.h"

extern int mouse_x, mouse_y;

void drawGameScreen(){

    char txt[100];

    glColor3f(1,1,1);

    sprintf(txt,"Score : %d",score);
    drawText(20,570,txt);

    sprintf(txt,"Lives : %d",lives);
    drawText(650,570,txt);

    sprintf(txt,"Level : %d",currentLevel);
    drawText(350,570,txt);

    glColor3f(0,1,0);
    glRectf(paddleX,20,paddleX+100,40);

    glColor3f(1,0,0);

    glBegin(GL_POLYGON);

    for(int i=0;i<360;i++){

        float t=i*3.1416/180;
                glVertex2f(ballX+cos(t)*10,
                   ballY+sin(t)*10);
    }

    glEnd();

    drawBricks();
}

void drawLevelScreen() {
    drawStars(); // আপনার চাওয়া অনুযায়ী স্টার অ্যানিমেশন

    glColor3f(1, 1, 1);
    drawText(340, 500, "SELECT LEVEL");

    // মাউসের Y কোঅর্ডিনেট OpenGL এর সাথে মিলানোর জন্য কনভার্ট করা (600 - mouse_y)
    int my = 600 - mouse_y;

    // --- LEVEL 1 BUTTON ---
    // চেক করা হচ্ছে মাউস লেভেল ১ এর বক্সের ভেতরে আছে কি না
    if (mouse_x >= 250 && mouse_x <= 550 && my >= 380 && my <= 430)
        glColor3f(0.0, 0.7, 1.0); // হোভার কালার (হালকা নীল)
    else
        glColor3f(0.0, 0.5, 1.0); // সাধারণ কালার

    glRectf(250, 380, 550, 430);
    glColor3f(1, 1, 1);
    drawText(365, 400, "LEVEL 1");

    // --- LEVEL 2 BUTTON ---
    if (mouse_x >= 250 && mouse_x <= 550 && my >= 300 && my <= 350)
        glColor3f(0.0, 1.0, 0.5); // হোভার কালার (হালকা সবুজ)
    else
        glColor3f(0.0, 0.8, 0.3); // সাধারণ কালার

    glRectf(250, 300, 550, 350);
    glColor3f(1, 1, 1);
    drawText(365, 320, "LEVEL 2");

    // --- LEVEL 3 BUTTON ---
    if (mouse_x >= 250 && mouse_x <= 550 && my >= 220 && my <= 270)
        glColor3f(1.0, 0.3, 0.7); // হোভার কালার (হালকা গোলাপী)
    else
        glColor3f(1.0, 0.0, 0.5); // সাধারণ কালার

    glRectf(250, 220, 550, 270);
    glColor3f(1, 1, 1);
    drawText(365, 240, "LEVEL 3");
}

void drawGameOver(){

    glColor3f(1,0,0);
    drawText(350,350,"GAME OVER");

    glColor3f(1,1,1);
    drawText(275,280,"PRESS M TO RETURN MENU");
}
