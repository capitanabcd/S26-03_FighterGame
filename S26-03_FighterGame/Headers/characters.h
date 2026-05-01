#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class cell
{
public:
    virtual void LoadTexture
        (std::vector<sf::Texture>&,
        std::vector<sf::Texture>&,
        std::vector<sf::Texture>&,
        std::vector<sf::Texture>&
            );
};

class goku
{
public:
    virtual void LoadTexture
       (std::vector<sf::Texture>&,
        std::vector<sf::Texture>&,
        std::vector<sf::Texture>&,
        std::vector<sf::Texture>&
       );
};

class freeza
{
public:
    virtual void LoadTexture
       (std::vector<sf::Texture>&,
        std::vector<sf::Texture>&,
        std::vector<sf::Texture>&,
        std::vector<sf::Texture>&
        );
};

class Loadtextures : public cell, public goku, public freeza
{
public:
    std::vector<sf::Texture> IdleTextures;
    std::vector<sf::Texture> MovementTextures;
    std::vector<sf::Texture> StaggerTextures;
    std::vector<sf::Texture> HeavyAttackTextures;
    std::vector<sf::Texture> BasicAttackTextures;
    void LoadTexture
       (std::vector<sf::Texture>&,
        std::vector<sf::Texture>&,
        std::vector<sf::Texture>&,
        std::vector<sf::Texture>&
           )override;
    void SetCharacterTexture();

    Loadtextures()
    {
        SetCharacterTexture();
    }
};