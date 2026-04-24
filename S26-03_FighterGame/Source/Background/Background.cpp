#include "sfml.h"
Background::Background() {
    currentFrame = 0;
    frameDuration = 0.3f;
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