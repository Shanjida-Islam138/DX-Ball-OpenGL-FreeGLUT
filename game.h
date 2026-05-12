#ifndef GAME_H
#define GAME_H

extern float ballX;
extern float ballY;

extern float ballDX;
extern float ballDY;

extern float paddleX;

extern int score;
extern int lives;
extern int currentLevel;

void resetBall();
void updateGame();

#endif