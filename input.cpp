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
    if(gameState==1){

    if(key=='m'){
        gameState=0;
    }
}

    glutPostRedisplay();
}

}

void handleSpecial(int key,int x,int y){

    if(gameState==1){

        if(key==GLUT_KEY_LEFT)
            paddleX -= 25;

        if(key==GLUT_KEY_RIGHT)
            paddleX += 25;

        if(paddleX<0)
            paddleX=0;

        if(paddleX>700)
            paddleX=700;
    }

    glutPostRedisplay();
}

void mouseClick(int button,int state,int x,int y){

    // Convert mouse coordinate
    y = 600 - y;

    if(button == GLUT_LEFT_BUTTON &&
       state == GLUT_DOWN)
    {
        // ================= MENU =================
        if(gameState == 0){

            // START GAME
            if(x>=270 && x<=520 &&
               y>=340 && y<=390)
            {
                initLevel(1);

                gameState = 1;
            }

            // LEVEL SELECT
            else if(x>=270 && x<=520 &&
                    y>=260 && y<=310)
            {
                gameState = 2;
            }

            // EXIT
            else if(x>=270 && x<=520 &&
                    y>=180 && y<=230)
            {
                exit(0);
            }
        }

        // ================= LEVEL SCREEN =================
        else if(gameState == 2){

            // LEVEL 1
            if(x>=250 && x<=550 &&
               y>=380 && y<=430)
            {
                initLevel(1);

                gameState = 1;
            }

            // LEVEL 2
            else if(x>=250 && x<=550 &&
                    y>=300 && y<=350)
            {
                initLevel(2);

                gameState = 1;
            }

            // LEVEL 3
            else if(x>=250 && x<=550 &&
                    y>=220 && y<=270)
            {
                initLevel(3);

                gameState = 1;
            }
        }
    }

    glutPostRedisplay();
}