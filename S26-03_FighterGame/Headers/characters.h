#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class HealthBar {
private:
    float maxHealth;
    float currentHealth;

    sf::RectangleShape backgroundBar;
    sf::RectangleShape foregroundBar;

public:
    
    HealthBar(float maxHealthValue, sf::Vector2f position);
    void TakeDamage(float damage);
    void Heal(float amount);
    void Draw(sf::RenderWindow& window);
    void SetPosition(sf::Vector2f pos);

    float GetCurrentHealth() const { return currentHealth; }
    bool IsDead() const { return currentHealth <= 0; }
};

class cell : public HealthBar
{
public:
    HealthBar healthBar;
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
    HealthBar healthBar;
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
    HealthBar healthBar;
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