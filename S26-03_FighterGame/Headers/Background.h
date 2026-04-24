#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Background {
private:
    sf::Texture backgroundTextures[5];
    sf::Sprite backgroundSprite;
    sf::Clock animationClock;
    int currentFrame;
    float frameDuration;

public:
    Background();
    void loadBackground(sf::RenderWindow& window);
    void updateBackground();
    void renderBackground(sf::RenderWindow& window);
};