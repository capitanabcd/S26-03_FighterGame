#pragma once
#include "PlayerComponents.h"
#include "Characters.h"
#include "Attack.h"

class Players : public movement, public jumping, public animations, public collide , public Attack , public Loadtextures , public Stagger
{
public:
    int PlayerNumber;
    float x;
    float y;
    float maxHealth;
    float currentHealth;
    sf::Clock clock;
    sf::Sprite Sprite;
    void setupOrigin()
    {
        sf::FloatRect bounds = Sprite.getLocalBounds();
        Sprite.setOrigin(bounds.width / 2.f, bounds.height);
    }

    Players()
    {
        maxHealth = 100;
        currentHealth = maxHealth;

        movement::player = this;
        jumping::player = this;
        animations::player = this;
        collide::player = this;
        Attack::player = this;
        Stagger::player = this;

        static int nextPlayerNumber = 1;
        PlayerNumber = nextPlayerNumber;
        nextPlayerNumber++;

        clock.restart();
        x = 100;
    }

    void InitAfterTextureLoad()
    {
        if (!IdleTextures.empty())
        {
            Sprite.setTexture(IdleTextures[0]);
            Sprite.setScale(4.f, 4.f);
            setupOrigin();
            if (PlayerNumber == 1)
                Sprite.setPosition(x, ground);
            else
                Sprite.setPosition(x + 400, ground);
        }
    }
};

extern Players player1;
extern Players player2;