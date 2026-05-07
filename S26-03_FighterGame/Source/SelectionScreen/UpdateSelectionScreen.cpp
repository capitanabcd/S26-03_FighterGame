#include "sfml.h"
void SelectionScreen::UpdateSelectionScreen( sf::RenderWindow& window)
{
    sf::Vector2u windowSize = window.getSize();
    float windowWidth = static_cast<float>(windowSize.x);
    float windowHeight = static_cast<float>(windowSize.y);
    float centerX = windowWidth / 2.f;
    float centerY = windowHeight / 2.f;

    Character1.setPosition(windowWidth * p1CharX, windowHeight * p1CharY);
    Character2.setPosition(windowWidth * p2CharX, windowHeight * p2CharY);

    Character1.setColor(sf::Color(255, 255, 255, 255));
    Character2.setColor(sf::Color(255, 255, 255, 255));

    if (selectingFor == 1 && !player1Selected) {
        Character1.setScale(Character1.getScale().x * 1.1f, Character1.getScale().y * 1.1f);
    }
    else if (selectingFor == 2 && !player2Selected) {
        Character2.setScale(Character2.getScale().x * 1.1f, Character2.getScale().y * 1.1f);
    }

    if (isEnterPlaying)
    {
        if (enterClock.getElapsedTime().asSeconds() >= 0.05f)
        {
            if (EnterFrames < EnterTextures.size())
            {
                SelectionSprite.setTexture(EnterTextures[EnterFrames]);

                sf::Vector2u textureSize = EnterTextures[EnterFrames].getSize();
                int cropX = 100;
                SelectionSprite.setTextureRect(sf::IntRect(
                    cropX, 0,
                    textureSize.x - cropX * 2,
                    textureSize.y
                ));

                float scaleX = windowWidth / static_cast<float>(textureSize.x - cropX * 2);
                float scaleY = windowHeight / static_cast<float>(textureSize.y);
                SelectionSprite.setScale(scaleX, scaleY);

                sf::FloatRect bounds = SelectionSprite.getLocalBounds();
                SelectionSprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
                SelectionSprite.setPosition(centerX, centerY);

                enterClock.restart();
                EnterFrames++;

                if (EnterFrames >= EnterTextures.size())
                {
                    EnterFrames = 0;
                    isEnterPlaying = false;
                    isSelecting = false;
                }
            }
        }
        return;
    }

    if (isOnePlaying)
    {
        if (oneClock.getElapsedTime().asSeconds() >= 0.03f)
        {
            if (!OneTextures.empty() && OneFrames < OneTextures.size())
            {
                SelectionSprite.setTexture(OneTextures[OneFrames]);

                sf::Vector2u textureSize = OneTextures[OneFrames].getSize();
                int cropX = 100;
                SelectionSprite.setTextureRect(sf::IntRect(
                    cropX, 0,
                    textureSize.x - cropX * 2,
                    textureSize.y
                ));

                float scaleX = windowWidth / static_cast<float>(textureSize.x - cropX * 2);
                float scaleY = windowHeight / static_cast<float>(textureSize.y);
                SelectionSprite.setScale(scaleX, scaleY);

                sf::FloatRect bounds = SelectionSprite.getLocalBounds();
                SelectionSprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
                SelectionSprite.setPosition(centerX, centerY);

                oneClock.restart();
                OneFrames++;

                if (OneFrames >= OneTextures.size())
                {
                    OneFrames = 0;
                    isOnePlaying = false;
                }
            }
        }
        return;
    }

    if (isTwoPlaying)
    {
        if (twoClock.getElapsedTime().asSeconds() >= 0.03f)
        {
            if (!TwoTextures.empty() && TwoFrames < TwoTextures.size())
            {
                SelectionSprite.setTexture(TwoTextures[TwoFrames]);

                sf::Vector2u textureSize = TwoTextures[TwoFrames].getSize();
                int cropX = 100;
                SelectionSprite.setTextureRect(sf::IntRect(
                    cropX, 0,
                    textureSize.x - cropX * 2,
                    textureSize.y
                ));

                float scaleX = windowWidth / static_cast<float>(textureSize.x - cropX * 2);
                float scaleY = windowHeight / static_cast<float>(textureSize.y);
                SelectionSprite.setScale(scaleX, scaleY);

                sf::FloatRect bounds = SelectionSprite.getLocalBounds();
                SelectionSprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
                SelectionSprite.setPosition(centerX, centerY);

                twoClock.restart();
                TwoFrames++;

                if (TwoFrames >= TwoTextures.size())
                {
                    TwoFrames = 0;
                    isTwoPlaying = false;
                }
            }
        }
        return;
    }

    if (idleClock1.getElapsedTime().asSeconds() >= 0.2f)
    {
        if (index1 == 0 && !C1.empty())
            Character1.setTexture(C1[frames1 % C1.size()], true);
        else if (index1 == 1 && !C2.empty())
            Character1.setTexture(C2[frames1 % C2.size()], true);
        else if (index1 == 2 && !C3.empty())
            Character1.setTexture(C3[frames1 % C3.size()], true);

        NormalizeCharacter(Character1);
        idleClock1.restart();
        frames1++;
    }

    if (idleClock2.getElapsedTime().asSeconds() >= 0.2f)
    {
        if (index2 == 0 && !C1.empty())
            Character2.setTexture(C1[frames2 % C1.size()], true);
        else if (index2 == 1 && !C2.empty())
            Character2.setTexture(C2[frames2 % C2.size()], true);
        else if (index2 == 2 && !C3.empty())
            Character2.setTexture(C3[frames2 % C3.size()], true);

        NormalizeCharacter(Character2);
        idleClock2.restart();
        frames2++;
    }
}