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
        std::vector<sf::Texture>&,
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
        std::vector<sf::Texture>&,
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
        std::vector<sf::Texture>&,
           std::vector<sf::Texture>&,
           std::vector<sf::Texture>&,
           std::vector<sf::Texture>&
        );
};

class broly
{
public:

    virtual void LoadTexture
    (std::vector<sf::Texture>&,
        std::vector<sf::Texture>&,
        std::vector<sf::Texture>&,
        std::vector<sf::Texture>&,
        std::vector<sf::Texture>&,
        std::vector<sf::Texture>&,
        std::vector<sf::Texture>&
    );
};


class trunks
{
public:

    virtual void LoadTexture
    (std::vector<sf::Texture>&,
        std::vector<sf::Texture>&,
        std::vector<sf::Texture>&,
        std::vector<sf::Texture>&,
        std::vector<sf::Texture>&,
        std::vector<sf::Texture>&,
        std::vector<sf::Texture>&
    );
};

class Loadtextures : public cell, public goku, public freeza, public trunks, public broly
{
public:
    std::string characterName;
    std::vector<sf::Texture> IdleTextures;
    std::vector<sf::Texture> MovementTextures;
    std::vector<sf::Texture> StaggerTextures;
    std::vector<sf::Texture> HeavyAttackTextures;
    std::vector<sf::Texture> BasicAttackTextures;
    std::vector<sf::Texture> BeamTextures;
    std::vector<sf::Texture> RangedTexture;
    std::vector<sf::Texture> BasicAttackTexture;
    sf::Texture EmptyTexture;
    void LoadTexture
       (std::vector<sf::Texture>&,
        std::vector<sf::Texture>&,
        std::vector<sf::Texture>&,
        std::vector<sf::Texture>&,
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