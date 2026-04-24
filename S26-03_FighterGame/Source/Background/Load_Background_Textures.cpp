#include "sfml.h"

void Background::loadBackground(sf::RenderWindow& window) {
    backgroundTextures[0].loadFromFile("assets/background/background image 1.jpeg");
    backgroundTextures[1].loadFromFile("assets/background/background image 2.jpeg");
    backgroundTextures[2].loadFromFile("assets/background/background image 3.jpeg");
    backgroundTextures[3].loadFromFile("assets/background/background image 4.jpeg");
    backgroundTextures[4].loadFromFile("assets/background/background image 5.jpeg");

    backgroundSprite.setTexture(backgroundTextures[0]);
    sf::Vector2u windowSize = window.getSize();
    sf::Vector2u textureSize = backgroundTextures[0].getSize();
    float scaleX = (float)windowSize.x / textureSize.x;
    float scaleY = (float)windowSize.y / textureSize.y;
    backgroundSprite.setScale(scaleX, scaleY);
}