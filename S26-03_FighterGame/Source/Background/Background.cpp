#include "sfml.h"
Background::Background() {
    currentFrame = 0;
    frameDuration = 0.1f;
}
void Background::updateBackground() {
    if (backgroundTextures.empty()) return;

    if (animationClock.getElapsedTime().asSeconds() >= frameDuration) {
        currentFrame = (currentFrame + 1) % backgroundTextures.size();
        backgroundSprite.setTexture(backgroundTextures[currentFrame]);
        animationClock.restart();
    }
}

void Background::renderBackground(sf::RenderWindow& window) {
    window.draw(backgroundSprite);
}