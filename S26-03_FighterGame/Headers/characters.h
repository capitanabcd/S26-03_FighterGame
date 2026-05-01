#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>

struct CharacterEntry {
    std::string name;
    sf::Texture texture;
    sf::Sprite sprite;
};

class cell {
public:
    static void LoadTexture(std::vector<sf::Texture>&, std::vector<sf::Texture>&, std::vector<sf::Texture>&, std::vector<sf::Texture>&);
};

class goku {
public:
    static void LoadTexture(std::vector<sf::Texture>&, std::vector<sf::Texture>&, std::vector<sf::Texture>&, std::vector<sf::Texture>&);
};

class freeza {
public:
    static void LoadTexture(std::vector<sf::Texture>&, std::vector<sf::Texture>&, std::vector<sf::Texture>&, std::vector<sf::Texture>&);
};

class Loadtextures : public cell, public goku, public freeza {
public:
    std::vector<sf::Texture> IdleTextures;
    std::vector<sf::Texture> MovementTextures;
    std::vector<sf::Texture> StaggerTextures;
    std::vector<sf::Texture> HeavyAttackTextures;
    // We keep the vectors here, but we delete SetCharacterTexture()
};