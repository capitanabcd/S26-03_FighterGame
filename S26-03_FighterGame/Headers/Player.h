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

    
    void setupOrigin()
    {
        sf::FloatRect bounds = Sprite.getLocalBounds();
        if (bounds.width > 0 && bounds.height > 0) {
            Sprite.setOrigin(bounds.width / 2.f, bounds.height);
        }
    }

  
    void loadCharacter(std::string name)
    {
       
        IdleTextures.clear();
        MovementTextures.clear();
        HeavyAttackTextures.clear();
        StaggerTextures.clear();

        if (name == "goku")
        {
            IdleFrames = 6;
            MovementFrames = 8;
            HeavyAttackFrames = 10;
            StaggerFrames = 4;
           
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

      
        if (!IdleTextures.empty())
        {
            Sprite.setTexture(IdleTextures[0]);
            setupOrigin();

          
            y = ground - Sprite.getGlobalBounds().height;
            Sprite.setPosition(Sprite.getPosition().x, ground);

          
            std::cout << "[GAME] Player " << PlayerNumber << " initialized as: " << name << std::endl;
        }
        else
        {
            std::cout << "[ERROR] Player " << PlayerNumber << ": Could not find textures for " << name << std::endl;
        }
    }

    Players()
    {
      
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

      
        y = 0.f;
        x = (PlayerNumber == 1) ? 100.f : 500.f;

        Sprite.setScale(4.f, 4.f);
        Sprite.setPosition(x, ground);
    }
};

extern Players player1;
extern Players player2;