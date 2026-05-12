#include "game.h"
#include "physics.h"
#include <GL/glut.h>

float ballX=400;
float ballY=300;

float ballDX=4;
float ballDY=4;

float paddleX=350;

int score=0;
int lives=3;
int currentLevel=1;

void resetBall(){

    ballX=400;
    ballY=300;

    ballDX=4;
    ballDY=4;
}

void updateGame(){

    ballX += ballDX;
    ballY += ballDY;

    if(ballX<=0 || ballX>=800)
    ballDX *= -1;

    if(ballY>=600)
        ballDY *= -1;

    if(ballY<=40 && ballX>=paddleX && ballX<=paddleX+100){
        ballDY *= -1;
    }

    if(ballY<0){
        lives--;
        resetBall();
    }

    checkBrickCollision();

    glutPostRedisplay();
}