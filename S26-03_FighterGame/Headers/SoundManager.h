#pragma once
#include <SFML/Audio.hpp>
#include <iostream>

class SoundManager
{
public:
    bool loadSounds();
    bool loadMusic();     
    void playHit();
    void playJump();
    void playBeam();
    void playKick();
    void playKnockBack();
    void playBackground();
    void playSelect();
    void playGameStart();
    void playGameEnd();

    sf::SoundBuffer hitBuffer;
    sf::SoundBuffer jumpBuffer;
    sf::SoundBuffer beamBuffer;
    sf::SoundBuffer kickBuffer;
    sf::SoundBuffer knockbackBuffer;
    sf::SoundBuffer selectBuffer;
    sf::SoundBuffer gamestartBuffer;
    sf::SoundBuffer gameendBuffer;


    sf::Sound hitSound;
    sf::Sound jumpSound;
    sf::Sound beamSound;
    sf::Sound kickSound;
    sf::Sound knockbackSound;
    sf::Sound selectSound;
    sf::Sound gameStartSound;
    sf::Sound gameEndSound;

    sf::Music backgroundMusic; 
};