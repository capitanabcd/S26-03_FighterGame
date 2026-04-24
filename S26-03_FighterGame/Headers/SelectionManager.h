#include <SFML/Graphics.hpp>
#include <iostream>
#include "SelectionBox.h" // Crucial: This links the box to the manager
#pragma once

class SelectionManager {
private:
    sf::Texture menuTexture;
    sf::Sprite menuSprite;
    SelectionBox slots[3]; // This defines the "slots" that were red in your screenshot
    bool keyReleased = true;
    int p1Choice = -1;
    int p2Choice = -1;
    sf::Clock selectionClock;

public:
    int getP1Choice() { return p1Choice; }
    int getP2Choice() { return p2Choice; }
    bool isSelectionFinished() { return (p1Choice != -1 && p2Choice != -1); }
    void load(sf::RenderWindow& window);
    void update(sf::RenderWindow& window);
    void render(sf::RenderWindow& window);
};