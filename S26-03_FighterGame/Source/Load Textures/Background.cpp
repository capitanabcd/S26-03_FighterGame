#include "Background.h"
Background::Background() {
    currentFrame = 0;
    frameDuration = 0.10f;
}
void Background::loadBackground(sf::RenderWindow& window) {
    bool success = true;
    if (!backgroundTextures[0].loadFromFile("assets/background/background image 1.jpeg")) success = false;
    if (!backgroundTextures[1].loadFromFile("assets/background/background image 2.jpeg")) success = false;
    if (!backgroundTextures[2].loadFromFile("assets/background/background image 3.jpeg")) success = false;
    if (!backgroundTextures[3].loadFromFile("assets/background/background image 4.jpeg")) success = false;
    if (!backgroundTextures[4].loadFromFile("assets/background/background image 5.jpeg")) success = false;

    if (!success) {
        std::cout << "Error: One or more background images failed to load!" << std::endl;
    }
    backgroundSprite.setTexture(backgroundTextures[0]);
    sf::Vector2u windowSize = window.getSize();
    sf::Vector2u textureSize = backgroundTextures[0].getSize();
    float scaleX = (float)windowSize.x / textureSize.x;
    float scaleY = (float)windowSize.y / textureSize.y;
    backgroundSprite.setScale(scaleX, scaleY);
}

void Background::updateBackground() {
    if (animationClock.getElapsedTime().asSeconds() > frameDuration) {
        currentFrame = (currentFrame + 1) % 5;
        backgroundSprite.setTexture(backgroundTextures[currentFrame]);
        animationClock.restart();
    }
}

void Background::renderBackground(sf::RenderWindow& window) {
    window.draw(backgroundSprite);
}