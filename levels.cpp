#include <GL/glut.h>
#include "levels.h"
#include "game.h"
int currentLevel = 1;
Brick bricks[50];
extern float ballDX, ballDY;

void initLevel(int level){

    currentLevel = level;

    if (level == 1) {
        ballDX = 4.0;  
        ballDY = 4.0;
    }
    else if (level == 2) {
        ballDX = 6.0;  
        ballDY = 6.0;
    }
    else if (level == 3) {
        ballDX = 7.5;  
        ballDY = 7.5;
    }

    int index=0;

    for(int i=0;i<5;i++){

        for(int j=0;j<10;j++){

            bricks[index].x = j*80;
            bricks[index].y = 500 - i*35;
            bricks[index].active = true;

            index++;
        }
    }
}

void drawBricks(){

    for(int i=0;i<50;i++){
        if(bricks[i].active){

            if(currentLevel==1)
                glColor3f(0,1,1);

            else if(currentLevel==2)
                glColor3f(1,0.3,0);

            else
                glColor3f(1,0,1);

            glRectf(bricks[i].x,
                    bricks[i].y,
                    bricks[i].x+70,
                    bricks[i].y+20);
        }
    }
}
