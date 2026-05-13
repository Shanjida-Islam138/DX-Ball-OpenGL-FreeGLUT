#include "physics.h"
#include "levels.h"
#include "game.h"

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
            }
        }
    }
}