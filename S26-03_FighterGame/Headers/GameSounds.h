#pragma once
#include"sfml.h"

class SoundManager
{
public:
    bool loadSounds();   
    void playHit();
    void playJump();

private:
    sf::SoundBuffer hitBuffer;
    sf::SoundBuffer jumpBuffer;

    sf::Sound hitSound;
    sf::Sound jumpSound;
};