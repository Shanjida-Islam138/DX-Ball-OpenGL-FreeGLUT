#ifndef INPUT_H
#define INPUT_H

void handleInput(unsigned char key,int x,int y);

void handleSpecial(int key,int x,int y);

void mouseClick(int button,int state,int x,int y);
void mouseMove(int x,int y);

#endif