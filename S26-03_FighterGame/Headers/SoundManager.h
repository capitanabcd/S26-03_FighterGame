#pragma once
#include "sfml.h"

class SoundManager
{
public:
    bool loadSounds();
    bool loadMusic();     
    void playHit();
    void playJump();
    void playBeam();

    void playBackground();

    sf::SoundBuffer hitBuffer;
    sf::SoundBuffer jumpBuffer;
    sf::SoundBuffer beamBuffer;

    sf::Sound hitSound;
    sf::Sound jumpSound;
    sf::Sound beamSound;

    sf::Music backgroundMusic; 
};