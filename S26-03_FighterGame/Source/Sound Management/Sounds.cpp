#include "SoundManager.h"

bool SoundManager::loadSounds()
{
    if (!hitBuffer.loadFromFile("assets/Sounds/hit.wav"))
    {
        return false;
    }

    if (!jumpBuffer.loadFromFile("assets/Sounds/jump.wav"))
    {
        return false;
    }

    hitSound.setBuffer(hitBuffer);
    jumpSound.setBuffer(jumpBuffer);

    return true;
}

void SoundManager::playHit()
{
    hitSound.play();
}

void SoundManager::playJump()
{
    jumpSound.play();
}


