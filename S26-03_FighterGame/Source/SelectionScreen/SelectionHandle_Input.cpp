#include "sfml.h"
void SelectionScreen::HandleInput(sf::Event& event)
{
    if (isEnterPlaying) return;

    if (event.type == sf::Event::KeyPressed)
    {
        if (selectingFor == 1 || true)
        {
            if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::D)
            {
                if (event.key.code == sf::Keyboard::D)
                    index1 = (index1 + 1) % 3;
                else
                    index1 = (index1 - 1 + 3) % 3;

                if (index1 == 0 && !C1.empty())
                    Character1.setTexture(C1[0], true);
                else if (index1 == 1 && !C2.empty())
                    Character1.setTexture(C2[0], true);
                else if (index1 == 2 && !C3.empty())
                    Character1.setTexture(C3[0], true);

                NormalizeCharacter(Character1);
                frames1 = 0;

                isOnePlaying = true;
                isTwoPlaying = false;
                OneFrames = 0;
                oneTimer = 0.f;
            }
            else if (event.key.code == sf::Keyboard::Enter && selectingFor == 1)
            {
                player1Choice = index1 + 1;
                player1Selected = true;
                player2Active = true;
                selectingFor = 2;

                isOnePlaying = false;
                isTwoPlaying = false;
            }
        }

        if (selectingFor == 2 && player2Active)
        {
            if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::Right)
            {
                if (event.key.code == sf::Keyboard::Right)
                    index2 = (index2 + 1) % 3;
                else
                    index2 = (index2 - 1 + 3) % 3;

                if (index2 == 0 && !C1.empty())
                    Character2.setTexture(C1[0], true);
                else if (index2 == 1 && !C2.empty())
                    Character2.setTexture(C2[0], true);
                else if (index2 == 2 && !C3.empty())
                    Character2.setTexture(C3[0], true);

                NormalizeCharacter(Character2);
                frames2 = 0;

                isTwoPlaying = true;
                isOnePlaying = false;
                TwoFrames = 0;
                twoTimer = 0.f;
            }
            else if (event.key.code == sf::Keyboard::RShift || event.key.code == sf::Keyboard::LShift)
            {
                player2Choice = index2 + 1;
                player2Selected = true;

                isEnterPlaying = true;
                isOnePlaying = false;
                isTwoPlaying = false;
                EnterFrames = 0;
                enterTimer = 0.f;
            }
        }
    }
}