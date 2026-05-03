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

bool SoundManager::loadMusic()
{
    if (!backgroundMusic.openFromFile("assets/Sounds/Hornet.wav"))
        return false;

    backgroundMusic.setLoop(true);   
    backgroundMusic.setVolume(50);  

    return true;
}

void SoundManager::playBackground()
{
    backgroundMusic.play();
}