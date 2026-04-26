#include "sfml.h"

void showLoadingScreen(sf::RenderWindow& window) {
    sf::Texture loadingTexture;
    sf::Sprite loadingSprite;

    if (loadingTexture.loadFromFile("assets/loading.png")) {
        loadingSprite.setTexture(loadingTexture);

        sf::Vector2u windowSize = window.getSize();
        sf::Vector2u textureSize = loadingTexture.getSize();
        float scaleX = (float)windowSize.x / textureSize.x;
        float scaleY = (float)windowSize.y / textureSize.y;
        loadingSprite.setScale(scaleX, scaleY);
    }

    window.clear();
    window.draw(loadingSprite);
    window.display();
}