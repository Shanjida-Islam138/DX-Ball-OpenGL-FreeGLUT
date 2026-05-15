#include <GL/glut.h>
#include <math.h>

#include "game.h"
#include "levels.h"
#include "physics.h"
#include "ui.h"

float ballX = 400;
float ballY = 300;

float ballDX = 5;
float ballDY = 5;

float paddleX = 350;
float paddleY = 40;

int score = 0;
int lives = 3;

void updateGame(){

    // Move Ball
    ballX += ballDX;
    ballY += ballDY;

    // WALL COLLISION
    if(ballX < 10 || ballX > 790)
        ballDX = -ballDX;

    if(ballY > 590)
        ballDY = -ballDY;

    // BOTTOM COLLISION
    if(ballY < 0){

        lives--;

        ballX = 400;
        ballY = 300;
    }

    // PADDLE COLLISION
    if(ballY >= 40 && ballY <= 60 &&
       ballX >= paddleX &&
       ballX <= paddleX + 100)
    {
        ballDY = -ballDY;
    }

    // BRICK COLLISION
    checkBrickCollision();
}

void drawBall(){

    glColor3f(1,0.2,0.2);

    glBegin(GL_POLYGON);

    for(int i=0;i<360;i++){

        float t=i*3.1416/180;

        glVertex2f(ballX+cos(t)*10,
                   ballY+sin(t)*10);
    }

    glEnd();
}

void drawPaddle(){

    glColor3f(0,1,1);

    glRectf(paddleX,20,
            paddleX+100,40);
}