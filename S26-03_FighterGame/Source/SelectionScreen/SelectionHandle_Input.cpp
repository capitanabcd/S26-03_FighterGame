#include "sfml.h"

void SelectionScreen::HandleInput(sf::Event& event)
{
  
    if (isEnterPlaying) return;

    if (event.type == sf::Event::KeyPressed)
    {
        if (!player1Selected)
        {
            if (event.key.code == sf::Keyboard::D)
            {
                player1.s->selectSound.play();
                index1 = (index1 + 1) % 5;
                if (index1 == 0 && !C1.empty()) Character1.setTexture(C1[0], true);
                else if (index1 == 1 && !C2.empty()) Character1.setTexture(C2[0], true);
                else if (index1 == 2 && !C3.empty()) Character1.setTexture(C3[0], true);
                else if (index1 == 3 && !C4.empty()) Character1.setTexture(C4[0], true);
                else if (index1 == 4 && !C5.empty()) Character1.setTexture(C5[0], true);
                NormalizeCharacter(Character1);
                frames1 = 0;
                isOnePlaying = true;
                isTwoPlaying = false;
                OneFrames = 0;
            }
            else if (event.key.code == sf::Keyboard::A)
            {
                player1.s->selectSound.play();
                index1 = (index1 - 1 + 5) % 5;
                if (index1 == 0 && !C1.empty()) Character1.setTexture(C1[0], true);
                else if (index1 == 1 && !C2.empty()) Character1.setTexture(C2[0], true);
                else if (index1 == 2 && !C3.empty()) Character1.setTexture(C3[0], true);
                else if (index1 == 3 && !C4.empty()) Character1.setTexture(C4[0], true);
                else if (index1 == 4 && !C5.empty()) Character1.setTexture(C5[0], true);
                NormalizeCharacter(Character1);
                frames1 = 0;
                isOnePlaying = true;
                isTwoPlaying = false;
                OneFrames = 0;
            }
            else if (event.key.code == sf::Keyboard::Enter)
            {
                player1.s->gameStartSound.play();
                player1Choice = index1 + 1;
                player1Selected = true;
            }
        }

        if (!player2Selected)
        {
            if (event.key.code == sf::Keyboard::Right)
            {
                player2.s->selectSound.play();
                index2 = (index2 + 1) % 5;
                if (index2 == 0 && !C1.empty()) Character2.setTexture(C1[0], true);
                else if (index2 == 1 && !C2.empty()) Character2.setTexture(C2[0], true);
                else if (index2 == 2 && !C3.empty()) Character2.setTexture(C3[0], true);
                else if (index2 == 3 && !C4.empty()) Character2.setTexture(C4[0], true);
                else if (index2 == 4 && !C5.empty()) Character2.setTexture(C5[0], true);
                NormalizeCharacter(Character2);
                frames2 = 0;
                isTwoPlaying = true;
                isOnePlaying = false;
                TwoFrames = 0;
            }
            else if (event.key.code == sf::Keyboard::Left)
            {
                player2.s->selectSound.play();
                index2 = (index2 - 1 + 5) % 5;
                if (index2 == 0 && !C1.empty()) Character2.setTexture(C1[0], true);
                else if (index2 == 1 && !C2.empty()) Character2.setTexture(C2[0], true);
                else if (index2 == 2 && !C3.empty()) Character2.setTexture(C3[0], true);
                else if (index2 == 3 && !C4.empty()) Character2.setTexture(C4[0], true);
				else if (index2 == 4 && !C5.empty()) Character2.setTexture(C5[0], true);
                NormalizeCharacter(Character2);
                frames2 = 0;
                isTwoPlaying = true;
                isOnePlaying = false;
                TwoFrames = 0;
            }
            else if (event.key.code == sf::Keyboard::RShift || event.key.code == sf::Keyboard::LShift)
            {
                player2Choice = index2 + 1;
                player2Selected = true;
            }
        }

        if (player1Selected && player2Selected && !isEnterPlaying)
        {
            isEnterPlaying = true;
            isOnePlaying = false;
            isTwoPlaying = false;
            EnterFrames = 0;
        }
    }
}