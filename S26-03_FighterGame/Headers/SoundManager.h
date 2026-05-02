#pragma once
#include"sfml.h"

class SoundManager
{
public:
    bool loadSounds();   
    void playHit();
    void playJump();

    sf::SoundBuffer hitBuffer;
    sf::SoundBuffer jumpBuffer;

    sf::Sound hitSound;
    sf::Sound jumpSound;
};