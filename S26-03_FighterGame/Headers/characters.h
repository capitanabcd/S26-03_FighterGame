#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class cell
{
public:
    sf::Texture CellTexture[8];
    virtual void LoadTexture(sf::Texture* temp);
};

class goku
{
public:
    sf::Texture GokuTexture[8];
    virtual void LoadTexture(sf::Texture* temp);
};

class freeza
{
public:
    sf::Texture FreezaTexture[8];
    virtual void LoadTexture(sf::Texture* temp);
};

class Loadtextures : public cell, public goku, public freeza
{
public:
    sf::Texture Textures[8];
    void LoadTexture(sf::Texture* temp) override;
    void SetCharacterTexture();

    Loadtextures()
    {
        SetCharacterTexture();
    }
};