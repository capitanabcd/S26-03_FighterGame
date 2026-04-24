#include <SFML/Graphics.hpp>
#pragma once

class SelectionBox {
public:
    sf::FloatRect bounds;   // This is the AABB box
    int characterID;
    bool isHovered = false;

    SelectionBox() : characterID(0), isHovered(false) {}
};