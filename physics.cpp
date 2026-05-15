#include "physics.h"
#include "levels.h"
#include "game.h"
#include "sound.h"

extern float ballX, ballY;
extern float paddleX, paddleY;
extern float ballDX, ballDY; 
extern int score;

void checkBrickCollision(){

    for(int i=0;i<50;i++){

        if(bricks[i].active){

            if(ballX>=bricks[i].x &&
               ballX<=bricks[i].x+70 &&
               ballY>=bricks[i].y &&
               ballY<=bricks[i].y+20)
            {
                bricks[i].active=false;

                ballDY *= -1;

                score += 10;
                playHitSound();
            }
        }
    }
}


void checkPaddleCollision() {
    
    if (ballX >= paddleX && ballX <= paddleX + 100 && 
        ballY <= paddleY + 10 && ballY >= paddleY) 
    {
        if(ballDY < 0) { 
            ballDY *= -1;     
            playHitSound();
        }
    }
}


void updatePhysics() {
    
    ballX += ballDX;
    ballY += ballDY;

    
    checkBrickCollision();
    checkPaddleCollision(); 
    
    
}