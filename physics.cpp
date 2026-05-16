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

// ================= নতুন ফাংশন: লেভেল শেষ হয়েছে কি না চেক করা =================
 void checkLevelComplete() {
    int activeBricksCount = 0;
    
    // কোনো ব্রিক এখনো স্ক্রিনে একটিভ আছে কি না চেক করা হচ্ছে
    for(int i = 0; i < 50; i++) {
        if(bricks[i].active) {
            activeBricksCount++; // একটি ব্রিকও যদি একটিভ থাকে, তবে লেভেল শেষ হয়নি
            
        }
    }

   // যদি একটি ব্রিকও বাকি না থাকে (সব ভেঙে গেছে)
    if(activeBricksCount == 0) {
        if(currentLevel == 1) {
            currentLevel = 2;
            initLevel(2); // লেভেল ২ লোড হবে
            
            // বলের পজিশন প্যাডেলের উপরে রিসেট
            ballX = paddleX + 50; 
            ballY = 45; 
            
            // বলের ডিরেকশন আবার উপরের দিকে করে দেওয়া (যাতে নিচে পড়ে না যায়)
            if(ballDY < 0) ballDY *= -1; 
        }

        else if(currentLevel == 2) {
            currentLevel = 3;
            initLevel(3); // লেভেল ৩ এর ব্রিক লোড হবে এবং গতি আরও বাড়বে
            
            // বলের পজিশন প্যাডেলের উপরে রিসেট করা
            ballX = paddleX + 50; 
            ballY = 45;
            
            if(ballDY < 0) ballDY *= -1;
        }
        else if(currentLevel == 3) {
            // লেভেল ৩ শেষ মানে পুরো গেম ওভার (প্লেয়ার জিতে গেছে!)
            gameState = 0; // আপাতত মেইন মেনুতে ফেরত পাঠানো হলো
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