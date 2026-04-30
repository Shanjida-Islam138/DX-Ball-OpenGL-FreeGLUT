#include "input.h"
#include <GL/glut.h>

extern int gameState;

void handleInput(unsigned char key,int x,int y){

    if(gameState==0){
        if(key=='1') gameState=1;
        else if(key=='2') gameState=2;
        else if(key=='3') exit(0);
    }

    else if(gameState==2){
        if(key=='1' || key=='2' || key=='3'){
            gameState=1;
        }
    }

    else if(gameState==1){
        if(key=='p') gameState=0;
    }

    glutPostRedisplay();
}