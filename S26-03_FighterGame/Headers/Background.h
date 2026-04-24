#include <SFML/Graphics.hpp>
#include <iostream>
#pragma once

class Background {
private:
    sf::Texture backgroundTextures[5];
    sf::Sprite backgroundSprite;
    int currentFrame;
    sf::Clock animationClock;
    float frameDuration;

public:
    Background(); 
    void loadBackground(sf::RenderWindow& window); 
    void updateBackground(); 
    void renderBackground(sf::RenderWindow& window); 
};