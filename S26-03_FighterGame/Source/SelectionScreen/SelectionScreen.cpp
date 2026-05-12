#include "sfml.h"

SelectionScreen::SelectionScreen()
{
    isSelecting = true;
    isEnterPlaying = false;
    isOnePlaying = false;
    isTwoPlaying = false;
    player1Selected = false;
    player2Selected = false;
    player2Active = false;

    player1Choice = 0;
    player2Choice = 0;

    EnterFrames = 0;
    OneFrames = 0;
    TwoFrames = 0;
    index1 = 0;
    index2 = 1;
    frames1 = 0;
    frames2 = 0;
    selectingFor = 1;

    selectionBackgroundFrame = 0;
    selectionBackgroundFrameDuration = 0.1f;
    selectionBackgroundClock.restart();

    if (!C1.empty()) {
        Character1.setTexture(C1[0], true);
        Character2.setTexture(C1[0], true);
    }
}
void SelectionScreen::NormalizeCharacter(sf::Sprite& character)
{
    sf::FloatRect bounds = character.getLocalBounds();

    if (bounds.height == 0)
        return;

    float targetHeight = 180.f;
    float scale = targetHeight / bounds.height;

    character.setOrigin(bounds.width / 2.f, bounds.height);
    character.setScale(scale, scale);
}

void SelectionScreen::renderSelectionScreen(sf::RenderWindow& window)
{
    window.draw(SelectionSprite);
    NormalizeCharacter(Character1);
    NormalizeCharacter(Character2);
    window.draw(Character1);
    window.draw(Character2);
}