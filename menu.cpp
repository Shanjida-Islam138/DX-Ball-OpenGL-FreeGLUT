#include "menu.h"
#include "ui.h"
#include <GL/glut.h>
#include <math.h>
extern int mouse_x;
extern int mouse_y;
extern float anim;


void drawHugeTitle(float y, const char* txt) {
    glPushMatrix();
    
    // ১. পজিশন এবং স্কেলিং (মাঝখানে আনার জন্য ২৬০ পিক্সেল ডানে সরানো হয়েছে)
    glTranslatef(315, y, 0); 
    glScalef(3.5, 3.5, 1); // এটি লিখাটিকে ৩.৫ গুণ বড় করবে
    
    // ২. শ্যাডো (Shadow) - মেইন টেক্সটের সামান্য নিচে এবং ডানে
    glColor3f(0.2, 0.1, 0.0); // গাঢ় খয়েরি বা কালো শ্যাডো
    glRasterPos2f(0.05, -0.05); // স্কেলিং এর ভেতর পজিশন ০.০৫ দেওয়া মানেই এটি সরে যাবে
    for (int k = 0; txt[k] != '\0'; k++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, txt[k]);

    // ৩. মেইন টাইটেল (Main Title) - উজ্জ্বল কমলা রঙ
    glColor3f(1.0, 0.5, 0.0);
    glRasterPos2f(0, 0); // মেইন পজিশন
    for (int k = 0; txt[k] != '\0'; k++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, txt[k]);
        
    glPopMatrix();
}

void drawMenuButton(float x, float y, const char* txt, int active) {
    // মাউস হোভার লজিক ঠিক করা হয়েছে (বাটনের এরিয়া: ২৫০ থেকে ৫৫০)
    bool hovered = (mouse_x >= x && mouse_x <= x+300 && (600-mouse_y) >= y && (600-mouse_y) <= y+55);

    if (active || hovered) {
        if(hovered) glColor3f(1.0, 0.7, 0.0); // মাউস নিলে আরও উজ্জ্বল হলুদ-অরেঞ্জ হবে
        else glColor3f(1.0, 0.5, 0.0); // শুধু একটিভ থাকলে নরমাল অরেঞ্জ
        
        glRectf(x, y, x + 300, y + 55);
        
        // সিলেকশন বর্ডার
        glColor3f(1, 1, 1);
        glLineWidth(3);
        glBegin(GL_LINE_LOOP);
            glVertex2f(x, y); glVertex2f(x + 300, y);
            glVertex2f(x + 300, y + 55); glVertex2f(x, y + 55);
        glEnd();

        // সিলেকশন অ্যারো (শুধু একটিভ বাটনের জন্য)
        if(active){
            glBegin(GL_TRIANGLES);
                glVertex2f(x - 40, y + 27);
                glVertex2f(x - 15, y + 45);
                glVertex2f(x - 15, y + 10);
            glEnd();
        }
    } else {
        // বাটন যখন একটিভ না বা মাউস উপরে নেই তখন হালকা বর্ডার
        glColor3f(0.2, 0.2, 0.4);
        glBegin(GL_LINE_LOOP);
            glVertex2f(x, y); glVertex2f(x + 300, y);
            glVertex2f(x + 300, y + 55); glVertex2f(x, y + 55);
        glEnd();
    }
    
    glColor3f(1, 1, 1);
    glRasterPos2f(x + 60, y + 20);
    for (int j = 0; txt[j] != '\0'; j++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, txt[j]);
}

void drawPreviewBox() {
    // startX বাড়িয়ে ৫৯০ করা হয়েছে যেন এটি আরও ডানে সরে যায়
    float startX = 590; 
    float startY = 230;
    float width = 160; // বক্সের উইডথ কিছুটা কমিয়েছি যাতে ডানে জায়গা পায়
    float height = 150;

    // বক্স বর্ডার
    glColor3f(0, 1, 1);
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
        glVertex2f(startX, startY); glVertex2f(startX + width, startY);
        glVertex2f(startX + width, startY + height); glVertex2f(startX, startY + height);
    glEnd();

    // ব্রিকস (বক্সের ভেতরের ইটের পজিশন অটোমেটিক ডানে চলে যাবে startX এর কারণে)
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            glColor3f(0.2, 0.4, 0.8);
            glRectf(startX + 15 + j * 35, startY + 110 - i * 20, startX + 40 + j * 35, startY + 125 - i * 20);
        }
    }
 
    // এনিমেটেড বল (হালকা নড়াচড়া করবে)
    float ballX = startX + 80 + sin(anim) * 30;
    float ballY = startY + 60 + cos(anim * 1.5) * 15;
    
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i += 20) {
        float t = i * 3.1416 / 180;
        glVertex2f(ballX + cos(t) * 6, ballY + sin(t) * 6);
    }
    glEnd();

    // প্যাডেল
    glColor3f(1, 0.5, 0);
    glRectf(startX + 50, startY + 15, startX + 110, startY + 25);
}

void drawMenu() {
    anim += 0.04;
    drawStars(); 


   drawHugeTitle(440, "DX BALL");

    // বাটনগুলোকে মাঝখানে সেট করা হয়েছে (x = ২৫০)
    // ২৫০ থেকে শুরু করলে ৩০০ চওড়া বাটনটি ৫৫০ এ শেষ হবে, যা ৮০০ স্ক্রিনে একদম সেন্টার
    drawMenuButton(250, 330, "NEW GAME", 0);
    drawMenuButton(250, 255, "LEVEL SELECT", 0);
    drawMenuButton(250, 180, "EXIT", 0);

    drawPreviewBox();
}