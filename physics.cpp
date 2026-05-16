#include "physics.h"
#include "levels.h"
#include "game.h"
#include "sound.h"

extern int currentLevel;
extern int gameState;
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


 void checkLevelComplete() {
    int activeBricksCount = 0;
    
    
    for(int i = 0; i < 50; i++) {
        if(bricks[i].active) {
            activeBricksCount++; 
            
        }
    }

   
    if(activeBricksCount == 0) {
        if(currentLevel == 1) {
            currentLevel = 2;
            initLevel(2); 
            
           
            ballX = paddleX + 50; 
            ballY = 45; 
            
            
            if(ballDY < 0) ballDY *= -1; 
        }

        else if(currentLevel == 2) {
            currentLevel = 3;
            initLevel(3); 
            
            
            ballX = paddleX + 50; 
            ballY = 45;

            if(ballDY < 0) ballDY *= -1;
        }
        else if(currentLevel == 3) {
            
            gameState = 0; 
        }
    }
}


void updatePhysics() {
    
    ballX += ballDX;
    ballY += ballDY;

    
    checkBrickCollision();
    checkPaddleCollision(); 
    checkLevelComplete();
    
}