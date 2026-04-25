#pragma once
#include "PlayerComponents.h"
#include "Characters.h"

class Players : public movement, public jumping, public animations, public collide
{
public:
    int PlayerNumber;
    float x;
    float y;
    sf::Clock clock;
    sf::Texture PlayerTexture[8];
    sf::Sprite Sprite;

    void setupOrigin()
    {
        sf::FloatRect bounds = Sprite.getLocalBounds();
        Sprite.setOrigin(bounds.width / 2.f, bounds.height);
    }

    Players()
    {
        movement::player = this;
        jumping::player = this;
        animations::player = this;
        collide::player = this;

        static int nextPlayerNumber = 1;
        PlayerNumber = nextPlayerNumber;
        nextPlayerNumber++;

        clock.restart();

        Loadtextures ChosenTexture;
        for (int i = 0; i < 8; i++)
        {
            PlayerTexture[i] = ChosenTexture.Textures[i];
        }

        x = 100;

        Sprite.setTexture(PlayerTexture[0]);
        Sprite.setScale(4.f, 4.f);
        setupOrigin();

        y = ground - Sprite.getGlobalBounds().height;

        if (PlayerNumber == 1)
        {
            Sprite.setPosition(x, ground);
        }
        if (PlayerNumber == 2)
        {
            Sprite.setPosition(x + 400, ground);
        }
    }
};

extern Players player1;
extern Players player2;