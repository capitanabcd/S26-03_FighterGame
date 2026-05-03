#pragma once
#include "sfml.h"

class SoundManager
{
public:
    bool loadSounds();
    bool loadMusic();     
    void playHit();
    void playJump();

    void playBackground();

    sf::SoundBuffer hitBuffer;
    sf::SoundBuffer jumpBuffer;

    sf::Sound hitSound;
    sf::Sound jumpSound;

    sf::Music backgroundMusic; 
};