#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <filesystem>
#include <algorithm>

class Background {
private:
    std::vector <sf::Texture> backgroundTextures;
    sf::Sprite backgroundSprite;
    sf::Clock animationClock;
    int currentFrame;
    float frameDuration;
    int direction;
    bool animationComplete;

public:
    Background();
    void loadBackground(sf::RenderWindow& window);
    void updateBackground();
    void renderBackground(sf::RenderWindow& window);
    void resetAnimation();
};