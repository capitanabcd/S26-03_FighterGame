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
    if (isEnterPlaying)
    {
        if (!EnterTextures.empty() && EnterFrames < (int)EnterTextures.size())
        {
            SelectionSprite.setTexture(EnterTextures[EnterFrames]);
            EnterFrames += 1;
            if (EnterFrames >= (int)EnterTextures.size())
            {
                EnterFrames = 0;
                isEnterPlaying = false;
                isSelecting = false;
            }
        }
    }
    if (isOnePlaying)
    {
        if (!OneTextures.empty() && OneFrames < (int)OneTextures.size())
        {
            SelectionSprite.setTexture(OneTextures[OneFrames]);
            OneFrames += 3;
            if (OneFrames >= (int)OneTextures.size())
            {
                OneFrames = 0;
                isOnePlaying = false;
            }
        }
    }
    if (isTwoPlaying)
    {
        if (!TwoTextures.empty() && TwoFrames < (int)TwoTextures.size())
        {
            SelectionSprite.setTexture(TwoTextures[TwoFrames]);
            TwoFrames += 3;
            if (TwoFrames >= (int)TwoTextures.size())
            {
                TwoFrames = 0;
                isTwoPlaying = false;
            }
        }
    }

    if (idleClock1.getElapsedTime().asSeconds() >= 0.2f)
    {
        if (index1 == 0 && !C1.empty())
            Character1.setTexture(C1[frames1 % C1.size()], true);
        else if (index1 == 1 && !C2.empty())
            Character1.setTexture(C2[frames1 % C2.size()], true);
        else if (index1 == 2 && !C3.empty())
            Character1.setTexture(C3[frames1 % C3.size()], true);
        else if (index1 == 3 && !C4.empty())
            Character1.setTexture(C4[frames1 % C4.size()], true);
        else if (index1 == 4 && !C5.empty())
            Character1.setTexture(C5[frames1 % C5.size()], true);

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
        else if (index2 == 3 && !C4.empty())
            Character2.setTexture(C4[frames2 % C4.size()], true);
        else if (index2 == 4 && !C5.empty())
            Character2.setTexture(C5[frames2 % C5.size()], true);

        NormalizeCharacter(Character2);
        idleClock2.restart();
        frames2++;
    }
}