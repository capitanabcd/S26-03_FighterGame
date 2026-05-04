#include "SoundManager.h"

bool SoundManager::loadMusic()
{
    if (!backgroundMusic.openFromFile("assets/Sounds/Hornet.wav"))
        return false;

    backgroundMusic.setLoop(true);
    backgroundMusic.setVolume(50);

    return true;
}


