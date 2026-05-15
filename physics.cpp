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

// ২. প্যাডেল কলাইড চেক (প্যাডেলের সাথে ধাক্কা)
// এই ফাংশনটি নিচে যোগ করুন অথবা updatePhysics এর ভেতর লিখুন
void checkPaddleCollision() {
    // প্যাডেলের হাইট ১০ পিক্সেল ধরে (paddleY থেকে paddleY+10 পর্যন্ত)
    if (ballX >= paddleX && ballX <= paddleX + 100 && 
        ballY <= paddleY + 10 && ballY >= paddleY) 
    {
        if(ballDY < 0) { // বলটি যখন নিচের দিকে নামছে শুধু তখনই ধাক্কা খাবে
            ballDY *= -1;     
            playHitSound();
        }
    }
}

// ৩. মেইন ফিজিক্স আপডেট ফাংশন
void updatePhysics() {
    // বলের মুভমেন্ট কোড...
    ballX += ballDX;
    ballY += ballDY;

    // ফাংশনগুলো কল করা
    checkBrickCollision();
    checkPaddleCollision(); // এখানে প্যাডেলের লজিকটি কল হবে
    
    // দেয়ালের সাথে ধাক্কা চেক...
}