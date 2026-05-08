#include "sfml.h"
void SelectionScreen::HandleInput(sf::Event& event)
{
    if (isEnterPlaying) return;

    if (event.type == sf::Event::KeyPressed)
    {
        // PLAYER 1 CONTROLS
        if (!player1Selected)
        {
            if (event.key.code == sf::Keyboard::D)
            {
                index1 = (index1 + 1) % 3;
                if (index1 == 0 && !C1.empty()) Character1.setTexture(C1[0], true);
                else if (index1 == 1 && !C2.empty()) Character1.setTexture(C2[0], true);
                else if (index1 == 2 && !C3.empty()) Character1.setTexture(C3[0], true);
                NormalizeCharacter(Character1);
                frames1 = 0;
                isOnePlaying = true;
                isTwoPlaying = false;  // override two
                OneFrames = 0;
                oneClock.restart();
            }
            else if (event.key.code == sf::Keyboard::A)
            {
                index1 = (index1 - 1 + 3) % 3;
                if (index1 == 0 && !C1.empty()) Character1.setTexture(C1[0], true);
                else if (index1 == 1 && !C2.empty()) Character1.setTexture(C2[0], true);
                else if (index1 == 2 && !C3.empty()) Character1.setTexture(C3[0], true);
                NormalizeCharacter(Character1);
                frames1 = 0;
                isOnePlaying = true;
                isTwoPlaying = false;  // override two
                OneFrames = 0;
                oneClock.restart();
            }
            else if (event.key.code == sf::Keyboard::Enter)
            {
                player1Choice = index1 + 1;
                player1Selected = true;
            }
        }

        // PLAYER 2 CONTROLS
        if (!player2Selected)
        {
            if (event.key.code == sf::Keyboard::Right)
            {
                index2 = (index2 + 1) % 3;
                if (index2 == 0 && !C1.empty()) Character2.setTexture(C1[0], true);
                else if (index2 == 1 && !C2.empty()) Character2.setTexture(C2[0], true);
                else if (index2 == 2 && !C3.empty()) Character2.setTexture(C3[0], true);
                NormalizeCharacter(Character2);
                frames2 = 0;
                isTwoPlaying = true;
                isOnePlaying = false;  // override one
                TwoFrames = 0;
                twoClock.restart();
            }
            else if (event.key.code == sf::Keyboard::Left)
            {
                index2 = (index2 - 1 + 3) % 3;
                if (index2 == 0 && !C1.empty()) Character2.setTexture(C1[0], true);
                else if (index2 == 1 && !C2.empty()) Character2.setTexture(C2[0], true);
                else if (index2 == 2 && !C3.empty()) Character2.setTexture(C3[0], true);
                NormalizeCharacter(Character2);
                frames2 = 0;
                isTwoPlaying = true;
                isOnePlaying = false;  // override one
                TwoFrames = 0;
                twoClock.restart();
            }
            else if (event.key.code == sf::Keyboard::RShift || event.key.code == sf::Keyboard::LShift)
            {
                player2Choice = index2 + 1;
                player2Selected = true;
            }
        }

        // BOTH SELECTED - trigger enter animation
        if (player1Selected && player2Selected && !isEnterPlaying)
        {
            isEnterPlaying = true;
            isOnePlaying = false;
            isTwoPlaying = false;
            EnterFrames = 0;
            enterClock.restart();
        }
    }
}