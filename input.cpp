#include <GL/glut.h>
#include <stdlib.h>

#include "input.h"
#include "game.h"
#include "levels.h"

extern int gameState;

void handleInput(unsigned char key,int x,int y){

    if(gameState==0){

        if(key=='1'){
            gameState=1;
            initLevel(1);
        }

        else if(key=='2'){
            gameState=2;
        }

        else if(key=='3'){
            exit(0);
        }
    }

    else if(gameState==2){

        if(key=='1'){
            initLevel(1);
            gameState=1;
        }

        else if(key=='2'){
            initLevel(2);
            gameState=1;
        }

        else if(key=='3'){
            initLevel(3);
            gameState=1;
        }
    }

    else if(gameState==1){

        if(key=='m'){
            gameState=0;
        }
    }

    glutPostRedisplay();
}

void handleSpecial(int key,int x,int y){

    if(gameState==1){

        if(key==GLUT_KEY_LEFT)
            paddleX -= 25;

        if(key==GLUT_KEY_RIGHT)
            paddleX += 25;

        // Left boundary
        if(paddleX < 0)
            paddleX = 0;

        // Right boundary
        if(paddleX > 700)
            paddleX = 700;
    }

    glutPostRedisplay();
}
