#ifndef LEVELS_H
#define LEVELS_H

struct Brick{

    float x;
    float y;

    bool active;
};

extern Brick bricks[50];

void initLevel(int level);
void drawBricks();

#endif