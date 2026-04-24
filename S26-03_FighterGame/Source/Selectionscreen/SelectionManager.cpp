#include "SelectionManager.h"
#include <iostream>

void SelectionManager::load(sf::RenderWindow& window) {
    // Make sure the filename matches your assets folder exactly!
    if (!menuTexture.loadFromFile("assets/menus/seleectionimage.jpeg")) {
        std::cout << "Error: Could not load selection image!" << std::endl;
    }
    menuSprite.setTexture(menuTexture);

    // Scale background to fit screen
    sf::Vector2u winSize = window.getSize();
    sf::Vector2u texSize = menuTexture.getSize();
    menuSprite.setScale((float)winSize.x / texSize.x, (float)winSize.y / texSize.y);

    // Initialize the Array Slots (AABB Hitboxes)
    for (int i = 0; i < 3; i++) {
        slots[i].characterID = i;
        // Logic: Calculate boxes side-by-side based on window percentages
        slots[i].bounds = sf::FloatRect(winSize.x * (0.17f + (i * 0.23f)),
            winSize.y * 0.35f,
            winSize.x * 0.19f,
            winSize.y * 0.35f);
    }
}

void SelectionManager::update(sf::RenderWindow& window) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

    // 1. Check if the Enter key is NOT being pressed
    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
        keyReleased = true; // The user let go of the key, so it's safe to pick again
    }

    for (int i = 0; i < 3; i++) {
        if (slots[i].bounds.contains(mousePosF)) {
            slots[i].isHovered = true;

            // 2. Only select if:
            // - The Enter key IS pressed
            // - We haven't already used this "press" (keyReleased is true)
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && keyReleased) {

                if (p1Choice == -1) {
                    p1Choice = i;
                    std::cout << "P1 Locked In: " << i << std::endl;
                    keyReleased = false; // "Lock" the key until they let go
                    return;
                }
                else if (p2Choice == -1) {
                    p2Choice = i;
                    std::cout << "P2 Locked In: " << i << std::endl;
                    keyReleased = false;
                    return;
                }
            }
        }
        else {
            slots[i].isHovered = false;
        }
    }
}
void SelectionManager::render(sf::RenderWindow& window) {
    // 1. Draw the main menu background
    window.draw(menuSprite);

    // 2. Create the highlight box
    sf::RectangleShape highlight;
    highlight.setFillColor(sf::Color(255, 255, 255, 100)); // Semi-transparent white

    // 3. Loop through the array to see which slot needs highlighting
    for (int i = 0; i < 3; i++) {
        if (slots[i].isHovered) {
            highlight.setPosition(slots[i].bounds.left, slots[i].bounds.top);
            highlight.setSize(sf::Vector2f(slots[i].bounds.width, slots[i].bounds.height));
            window.draw(highlight);
        }
    }
}