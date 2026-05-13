#include "sfml.h"

EndScreen::EndScreen()
{
    isActive = false;
    restartRequested = false;
}

void EndScreen::loadEndTextures()
{
    p1WinTex.loadFromFile("assets/Player1 end.png");
    p2WinTex.loadFromFile("assets/Player2 end.png");
}

void EndScreen::showWinner(int winnerPlayerNumber, sf::RenderWindow& window)
{
    isActive = true;
    restartRequested = false;

    if (winnerPlayerNumber == 1)
        winSprite.setTexture(p1WinTex);
    else
        winSprite.setTexture(p2WinTex);

    sf::Vector2u windowSize = window.getSize();
    sf::Vector2u textureSize = winSprite.getTexture()->getSize();

    float scaleX = (float)windowSize.x / textureSize.x;
    float scaleY = (float)windowSize.y / textureSize.y;
    winSprite.setScale(scaleX, scaleY);
    winSprite.setPosition(0, 0);
}

void EndScreen::render(sf::RenderWindow& window)
{
    if (isActive)
    {
        window.draw(winSprite);
    }
}

void EndScreen::handleInput(sf::Event& event)
{
    if (isActive && event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
    {
        restartRequested = true;
        isActive = false;
    }
}