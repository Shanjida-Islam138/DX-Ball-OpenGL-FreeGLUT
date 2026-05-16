#include <GL/glut.h>
#include <stdlib.h>

#include "input.h"
#include "game.h"
#include "levels.h"
#include "sound.h"

int mouse_x = 0;
int mouse_y = 0;

extern int gameState;
extern float ballX, ballY;
extern float ballDX, ballDY;
extern float paddleX, paddleY;
extern int score;
extern int lives;

void resetGame() {
    score = 0;
    lives = 3;         // আপনার গেমের ডিফল্ট লাইভস যত (৩ বা ৫) তা দিন
    paddleX = 350;     // প্যাডেল মাঝখানে নিয়ে আসা
    ballX = 400;       // বল রিসেট
    ballY = 45;
    ballDX = 4.0;      // লেভেল ১ এর ডিফল্ট স্পিড
    ballDY = 4.0;
    initLevel(1);      // লেভেল ১ এর ইটগুলো নতুন করে জ্যান্ত করা
}

void handleInput(unsigned char key, int x, int y) {

    if(gameState == 0) {
        if(key == '1') {
            resetGame();
            gameState = 1;
        }
        else if(key == '2') {
            gameState = 2;
        }
        else if(key == '3') {
            exit(0);
        }
    }
    else if(gameState == 2) {
        if(key == '1') {
            resetGame();
            initLevel(1);
            gameState = 1;
        }
        else if(key == '2') {
            resetGame();
            initLevel(2);
            gameState = 1;
        }
        else if(key == '3') {
            resetGame();
            initLevel(3);
            gameState = 1;
        }
    }
    else {
        // গেম চলাকালীন বা গেম ওভার স্ক্রিনে 'm' বা 'M' চাপলে মেইন মেনুতে যাবে এবং সব রিসেট হবে
        if (key == 'm' || key == 'M') {
            resetGame();
            gameState = 0;
        }
    }

    glutPostRedisplay();
}

void handleSpecial(int key, int x, int y) {

    if(gameState == 1) {
        if(key == GLUT_KEY_LEFT)
            paddleX -= 25;

        if(key == GLUT_KEY_RIGHT)
            paddleX += 25;

        if(paddleX < 0)
            paddleX = 0;

        if(paddleX > 700)
            paddleX = 700;
    }

    glutPostRedisplay();
}

void mouseClick(int button, int state, int x, int y) {

    // Convert mouse coordinate
    y = 600 - y;

    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        // ================= MENU =================
        if(gameState == 0) {
            // START GAME
            if(x >= 270 && x <= 520 && y >= 340 && y <= 390) {
                resetGame();
                gameState = 1;
                playLevelMusic();
            }
            // LEVEL SELECT
            else if(x >= 270 && x <= 520 && y >= 260 && y <= 310) {
                gameState = 2;
            }
            // EXIT
            else if(x >= 270 && x <= 520 && y >= 180 && y <= 230) {
                exit(0);
            }
        }
        // ================= LEVEL SCREEN =================
        else if(gameState == 2) {
            // LEVEL 1
            if(x >= 250 && x <= 550 && y >= 380 && y <= 430) {
                resetGame();
                initLevel(1);
                gameState = 1;
                playLevelMusic();
            }
            // LEVEL 2
            else if(x >= 250 && x <= 550 && y >= 300 && y <= 350) {
                resetGame();
                initLevel(2);
                gameState = 1;
                playLevelMusic();
            }
            // LEVEL 3
            else if(x >= 250 && x <= 550 && y >= 220 && y <= 270) {
                resetGame();
                initLevel(3);
                gameState = 1;
                playLevelMusic();
            }
        }
    }

    glutPostRedisplay();
}

void mouseMove(int x, int y) {
    
    mouse_x = x;
    mouse_y = y;

    if(gameState == 1) {
        paddleX = x - 50; 

        if(paddleX < 0) 
            paddleX = 0;
        if(paddleX > 700) 
            paddleX = 700;
    }

    // এখানে কন্ডিশনাল এবং গ্লোবাল রিডিসপ্লে ক্লিন করা হয়েছে
    glutPostRedisplay(); 
}