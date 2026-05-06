#pragma once 
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <filesystem>
#include <algorithm>
class SelectionScreen {
public:
    SelectionScreen();

    void loadSelectionScreen(sf::RenderWindow& window);
    void Load_IdleTextures();
    void HandleInput(sf::Event& event);
    void UpdateSelectionScreen(float dt, sf::RenderWindow& window);
    void renderSelectionScreen(sf::RenderWindow& window);

    bool isSelecting;
    int player1Choice;
    int player2Choice;

private:
    void NormalizeCharacter(sf::Sprite& character);

    // Selection UI
    sf::Sprite SelectionSprite;
    sf::Sprite Character1;  // Player 1's character preview
    sf::Sprite Character2;  // Player 2's character preview

    // Textures
    std::vector<sf::Texture> OneTextures, TwoTextures, EnterTextures;
    std::vector<sf::Texture> C1, C2, C3;  // Character idle textures

    // Animation states
    bool isEnterPlaying, isOnePlaying, isTwoPlaying;
    bool player1Selected, player2Selected;
    bool player2Active;  // NEW: Tracks if P2 can be controlled

    // Frame counters
    int EnterFrames, OneFrames, TwoFrames;
    int index1, index2;
    int frames1, frames2;
    int selectingFor;

    // Timers
    float enterTimer, oneTimer, twoTimer;
    float idleTimer1, idleTimer2;

    // CHARACTER POSITIONS - ADJUST THESE VALUES
    // ==========================================
    float p1CharX = 0.25f;  // Player 1 X position (0.0 = left, 1.0 = right)
    float p1CharY = 0.7f;   // Player 1 Y position (0.0 = top, 1.0 = bottom)
    float p2CharX = 0.75f;  // Player 2 X position
    float p2CharY = 0.7f;   // Player 2 Y position
};