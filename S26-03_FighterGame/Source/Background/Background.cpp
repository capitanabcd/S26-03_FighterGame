#include "sfml.h"
Background::Background() {
    currentFrame = 0;
    frameDuration = 0.1f;
    direction = 1;
    animationComplete = false;
}
void Background::resetAnimation() {
    currentFrame = 0;
    direction = 1;
    animationComplete = false;
    if (!backgroundTextures.empty()) {
        backgroundSprite.setTexture(backgroundTextures[0]);
    }
    animationClock.restart();
}
void Background::updateBackground() {
    if (backgroundTextures.empty()) return;
    if (animationComplete) resetAnimation();

    if (animationClock.getElapsedTime().asSeconds() >= frameDuration) {
        int nextFrame = currentFrame + direction;

        if (nextFrame >= (int)backgroundTextures.size()) {
            direction = -1;
            nextFrame = backgroundTextures.size() - 2;
        }
        else if (nextFrame < 0) {
            animationComplete = true;
            return;
        }

        currentFrame = nextFrame;
        backgroundSprite.setTexture(backgroundTextures[currentFrame]);
        animationClock.restart();
    }
}

void Background::renderBackground(sf::RenderWindow& window) {
    window.draw(backgroundSprite);
}