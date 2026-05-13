#include <windows.h>
#include <mmsystem.h>
#include "sound.h"

void playMenuSound(){

    PlaySound(TEXT("menu.wav"),NULL,SND_ASYNC);
}

void playHitSound(){

    PlaySound(TEXT("hit.wav"),NULL,SND_ASYNC);
}

void playLevelMusic(){

    PlaySound(TEXT("level.wav"),NULL,SND_ASYNC);
}
