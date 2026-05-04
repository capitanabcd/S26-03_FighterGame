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
    void playKick();
    void playBackground();

    sf::SoundBuffer hitBuffer;
    sf::SoundBuffer jumpBuffer;
    sf::SoundBuffer beamBuffer;
    sf::SoundBuffer kickBuffer;

    sf::Sound hitSound;
    sf::Sound jumpSound;
    sf::Sound beamSound;
    sf::Sound kickSound;

    sf::Music backgroundMusic; 
};