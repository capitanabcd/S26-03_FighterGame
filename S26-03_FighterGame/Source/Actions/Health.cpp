#include "sfml.h"

void HealthBar::init(sf::Vector2f position, sf::Color fillColor, bool isMirrored)
{
    mirrored = isMirrored;
    background.setPointCount(4);
    fill.setPointCount(4);

    if (!mirrored) {
        background.setPoint(0, sf::Vector2f(slant, 0.f));
        background.setPoint(1, sf::Vector2f(maxWidth, 0.f));
        background.setPoint(2, sf::Vector2f(maxWidth - slant, barHeight));
        background.setPoint(3, sf::Vector2f(0.f, barHeight));

        fill.setPoint(0, sf::Vector2f(slant, 0.f));
        fill.setPoint(1, sf::Vector2f(maxWidth, 0.f));
        fill.setPoint(2, sf::Vector2f(maxWidth - slant, barHeight));
        fill.setPoint(3, sf::Vector2f(0.f, barHeight));
    }
    else {
        background.setPoint(0, sf::Vector2f(0.f, 0.f));
        background.setPoint(1, sf::Vector2f(maxWidth - slant, 0.f));
        background.setPoint(2, sf::Vector2f(maxWidth, barHeight));
        background.setPoint(3, sf::Vector2f(slant, barHeight));

        fill.setPoint(0, sf::Vector2f(0.f, 0.f));
        fill.setPoint(1, sf::Vector2f(maxWidth - slant, 0.f));
        fill.setPoint(2, sf::Vector2f(maxWidth, barHeight));
        fill.setPoint(3, sf::Vector2f(slant, barHeight));
    }

    background.setFillColor(sf::Color(50, 50, 50, 180));
    fill.setFillColor(fillColor);
    background.setPosition(position);
    fill.setPosition(position);
}
void HealthBar::update(float currentHealth)
{
    float percent = currentHealth / maxHealth;
    if (percent < 0.f) percent = 0.f;
    if (percent > 1.f) percent = 1.f;

    float currentWidth = maxWidth * percent;

    if (!mirrored) {
        fill.setPoint(0, sf::Vector2f(slant, 0.f));
        fill.setPoint(1, sf::Vector2f(slant + currentWidth, 0.f));
        fill.setPoint(2, sf::Vector2f(currentWidth, barHeight));
        fill.setPoint(3, sf::Vector2f(0.f, barHeight));
    }
    else {
        float left = maxWidth - currentWidth;
        float leftB = left + slant;

        if (leftB > maxWidth - slant) leftB = maxWidth - slant;
        if (left > maxWidth)         left = maxWidth;

        fill.setPoint(0, sf::Vector2f(left, 0.f));
        fill.setPoint(1, sf::Vector2f(maxWidth - slant, 0.f));
        fill.setPoint(2, sf::Vector2f(maxWidth, barHeight));
        fill.setPoint(3, sf::Vector2f(leftB, barHeight));
    }
}
void HealthBar::draw(sf::RenderWindow& window)
{
    window.draw(background);
    window.draw(fill);
}