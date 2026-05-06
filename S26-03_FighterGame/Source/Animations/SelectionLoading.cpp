#include "sfml.h"

void showSelectionScreen(sf::RenderWindow& window) {
    sf::Texture sloadingTexture;
    sf::Sprite sloadingSprite;

    if (sloadingTexture.loadFromFile("assets/SelectionLoading.jpeg")) {
        sloadingSprite.setTexture(sloadingTexture);

        sf::Vector2u windowSize = window.getSize();
        sf::Vector2u textureSize = sloadingTexture.getSize();
        float scaleX = (float)windowSize.x / textureSize.x;
        float scaleY = (float)windowSize.y / textureSize.y;
        sloadingSprite.setScale(scaleX, scaleY);
    }
    window.draw(sloadingSprite);
}