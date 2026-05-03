#pragma once
#include"SoundManager.h"
#include "PlayerComponents.h"
#include "Characters.h"
#include "Attack.h"
class SoundManager;
class Players : public movement, public jumping, public animations, public collide , public Attack , public Loadtextures , public Stagger
{
public:
    SoundManager* s;
    int PlayerNumber;
    float x;
    float y;
    int maxHealth;
    int currentHealth;
    sf::Clock clock;
    sf::Sprite Sprite;
    void setupOrigin()
    {
        sf::FloatRect bounds = Sprite.getLocalBounds();
        Sprite.setOrigin(bounds.width / 2.f, bounds.height);
    }
    Players();
};

extern Players player1;
extern Players player2;