#include "sfml.h"

SelectionScreen::SelectionScreen()
{
    isSelecting = true;
    EnterFrames = 0;
    ArrowFrames = 0;
    SelectionFrames = 0;
    index = 0;
    frames = 0;
    selectingFor = 1;
}
void SelectionScreen::NormalizeCharacter()
{
    sf::FloatRect bounds = Character.getLocalBounds();

    if (bounds.height == 0)
        return;

    float targetHeight = 200.f;

    float scale = targetHeight / bounds.height;

    Character.setOrigin(
        bounds.width / 2.f,
        bounds.height
    );

    Character.setScale(scale, scale);

    Character.setPosition(650.f,500.f);
}
void SelectionScreen::UpdateSelectionScreen()
{
    if (isEnterPlaying)
    {
        if (EnterClock.getElapsedTime().asSeconds() >= 0.12f)
        {
            SelectionSprite.setTexture(EnterTextures[EnterFrames]);
            EnterFrames++;
            EnterClock.restart();

            if (EnterFrames >= EnterTextures.size())
            {
                isEnterPlaying = false;

                if (selectingFor == 1)
                {
                    player1Choice = index + 1;
                    selectingFor = 2;
                }
                else
                {
                    player2Choice = index + 1;
                    isSelecting = false;
                }
            }
        }

        return;
    }
    if (ArrowClock.getElapsedTime().asSeconds() <= 0.2f)
    {
        if (!OneTextures.empty())
        {
            SelectionSprite.setTexture(
                OneTextures[ArrowFrames % OneTextures.size()]
            );

            if (SelectionClock.getElapsedTime().asSeconds() >= 0.1f)
            {
                ArrowFrames++;
                SelectionClock.restart();
            }
        }
    }
    else
    {
        if (!TwoTextures.empty())
        {
            if (SelectionClock.getElapsedTime().asSeconds() >= 0.5f)
            {
                SelectionFrames =
                    (SelectionFrames + 1) % TwoTextures.size();

                SelectionSprite.setTexture(
                    TwoTextures[SelectionFrames]
                );

                SelectionClock.restart();
            }
        }
    }

    if (IdleCLock.getElapsedTime().asSeconds() >= 0.2f)
    {
        if (index == 0 && !C1.empty())
            Character.setTexture(C1[frames % C1.size()], true);

        else if (index == 1 && !C2.empty())
            Character.setTexture(C2[frames % C2.size()], true);

        else if (index == 2 && !C3.empty())
            Character.setTexture(C3[frames % C3.size()], true);

        NormalizeCharacter();
        frames++;
        IdleCLock.restart();
    }
}
void SelectionScreen::renderSelectionScreen(sf::RenderWindow& window)
{
    window.draw(SelectionSprite);
    window.draw(Character);
}
void SelectionScreen::HandleInput(sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Right)
        {
            index = (index + 1) % 3;

            ArrowFrames = 0;
            ArrowClock.restart();

            frames = 0;
            IdleCLock.restart();
        }

        else if (event.key.code == sf::Keyboard::Left)
        {
            index = (index - 1 + 3) % 3;

            ArrowFrames = 0;
            ArrowClock.restart();

            frames = 0;
            IdleCLock.restart();
        }
        else if (event.key.code == sf::Keyboard::Enter)
        {
            isEnterPlaying = true;
            EnterFrames = 0;
            EnterClock.restart();
        }
    }
}