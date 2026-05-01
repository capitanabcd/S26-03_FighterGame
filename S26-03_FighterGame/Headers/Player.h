#pragma once
#include "PlayerComponents.h"
#include "Characters.h"
#include "Attack.h"
#include <iostream>
#include <string>
#include <vector>

class Players : public movement, public jumping, public animations, public collide, public Attack, public Loadtextures, public Stagger
{
public:
    int PlayerNumber;
    float x;
    float y;
    sf::Clock clock;
    sf::Sprite Sprite;

    // Sets the origin to the bottom-center of the sprite for better ground alignment
    void setupOrigin()
    {
        sf::FloatRect bounds = Sprite.getLocalBounds();
        if (bounds.width > 0 && bounds.height > 0) {
            Sprite.setOrigin(bounds.width / 2.f, bounds.height);
        }
    }

    // THE BRIDGE: This replaces the old SetTexture.cpp logic
    // It maps the strings from the selection screen to the actual asset vectors
    void loadCharacter(std::string name)
    {
        // 1. Clear vectors to ensure a fresh start and prevent memory stacking
        IdleTextures.clear();
        MovementTextures.clear();
        HeavyAttackTextures.clear();
        StaggerTextures.clear();

        // 2. Logic Bridge: Call specific static character loaders from Characters.h
        if (name == "goku")
        {
            IdleFrames = 6;
            MovementFrames = 8;
            HeavyAttackFrames = 10;
            StaggerFrames = 4;
            // Explicitly call the goku class version of LoadTexture
            goku::LoadTexture(HeavyAttackTextures, IdleTextures, MovementTextures, StaggerTextures);
        }
        else if (name == "cell")
        {
            IdleFrames = 5;
            MovementFrames = 7;
            HeavyAttackFrames = 12;
            StaggerFrames = 3;
            cell::LoadTexture(HeavyAttackTextures, IdleTextures, MovementTextures, StaggerTextures);
        }
        else if (name == "freeza")
        {
            IdleFrames = 6;
            MovementFrames = 8;
            HeavyAttackFrames = 9;
            StaggerFrames = 5;
            freeza::LoadTexture(HeavyAttackTextures, IdleTextures, MovementTextures, StaggerTextures);
        }

        // 3. Finalize Sprite Setup
        if (!IdleTextures.empty())
        {
            Sprite.setTexture(IdleTextures[0]);
            setupOrigin();

            // Set the vertical position based on the character's height and ground level
            y = ground - Sprite.getGlobalBounds().height;
            Sprite.setPosition(Sprite.getPosition().x, ground);

            // Task: Show on console which character has been selected
            std::cout << "[GAME] Player " << PlayerNumber << " initialized as: " << name << std::endl;
        }
        else
        {
            std::cout << "[ERROR] Player " << PlayerNumber << ": Could not find textures for " << name << std::endl;
        }
    }

    Players()
    {
        // Bind component pointers
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

        // FIX: Initialize y to 0 (or ground) here to stop the warning
        y = 0.f;
        x = (PlayerNumber == 1) ? 100.f : 500.f;

        Sprite.setScale(4.f, 4.f);
        Sprite.setPosition(x, ground);
    }
};

extern Players player1;
extern Players player2;