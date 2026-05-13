#pragma once
#include "sfml.h"

class EndScreen {
public:
    EndScreen();
    void loadEndTextures();
    void showWinner(int winnerPlayerNumber, sf::RenderWindow& window);
    void render(sf::RenderWindow& window);
    void handleInput(sf::Event& event);
    bool restartRequested;
    bool isActive;
private:
    sf::Texture p1WinTex;
    sf::Texture p2WinTex;
    sf::Sprite winSprite;
};
extern EndScreen gameEndScreen;