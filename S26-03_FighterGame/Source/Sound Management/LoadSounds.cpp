#include "SoundManager.h"

bool SoundManager::loadSounds()
{
    if (!hitBuffer.loadFromFile("assets/Sounds/hit.wav"))
    {
        return false;
    }

    if (!jumpBuffer.loadFromFile("assets/Sounds/Jump.wav"))
    {
        return false;
    }
    if (!beamBuffer.loadFromFile("assets/Sounds/Beam.wav"))
    {
        return false;
    }
    if (!kickBuffer.loadFromFile("assets/Sounds/Kick.wav"))
    {
        return false;
    }
    if (!knockbackBuffer.loadFromFile("assets/Sounds/KnockBack.wav"))
    {
        return false;
    }



    hitSound.setBuffer(hitBuffer);
    jumpSound.setBuffer(jumpBuffer);
    beamSound.setBuffer(beamBuffer);
    kickSound.setBuffer(kickBuffer);
    knockbackSound.setBuffer(knockbackBuffer);



    return true;
}