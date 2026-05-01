#include "SelectionManager.h"
#include <iostream>
#include <algorithm> 
#include <vector>    

SelectionManager::SelectionManager() : currentIndex(0), state(SelectionState::Player1) {}

// FIX: Added sf::RenderWindow& window to match the header declaration
bool SelectionManager::init(sf::RenderWindow& window) {
    // 1. Load Backgrounds
    if (!bgP1.loadFromFile("assets/selectionscreens/selection image player 1.jpeg") ||
        !bgP2.loadFromFile("assets/selectionscreens/selection image player 2.jpeg")) {
        return false;
    }
    background.setTexture(bgP1);

    // Scaling background to fit window
    sf::Vector2u windowSize = window.getSize();
    sf::Vector2u textureSize = bgP1.getSize();
    background.setScale((float)windowSize.x / textureSize.x, (float)windowSize.y / textureSize.y);

    // 2. Load Character Data
    std::vector<std::string> names = { "goku", "cell", "freeza" };
    std::vector<std::string> files = { "assets/goku/goku idle1.png", "assets/cell/cell1.png", "assets/freeza/freeza idle1.png" };

    fighters.reserve(names.size());

    for (size_t i = 0; i < names.size(); ++i) {
        Character c; // This works now because it's defined in SelectionManager.h
        c.name = names[i];

        if (c.texture.loadFromFile(files[i])) {
            fighters.push_back(c);
            size_t lastIdx = fighters.size() - 1;
            fighters[lastIdx].sprite.setTexture(fighters[lastIdx].texture);
            fighters[lastIdx].sprite.setScale(4.0f, 4.0f);

            sf::FloatRect bounds = fighters[lastIdx].sprite.getLocalBounds();
            fighters[lastIdx].sprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
            fighters[lastIdx].sprite.setPosition(previewPos);
        }
    }
    return !fighters.empty();
}

void SelectionManager::handleInput(sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::A) {
            previousCharacter();
        }
        else if (event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::D) {
            nextCharacter();
        }
        else if (event.key.code == sf::Keyboard::Enter || event.key.code == sf::Keyboard::Space) {
            confirmSelection();
        }
    }
}

void SelectionManager::confirmSelection() {
    if (state == SelectionState::Player1) {
        p1Choice = fighters[currentIndex].name;
        std::cout << "[SELECTION] Player 1 has chosen: " << p1Choice << std::endl;
        state = SelectionState::Player2;
        currentIndex = 0;
    }
    else if (state == SelectionState::Player2) {
        p2Choice = fighters[currentIndex].name;
        std::cout << "[SELECTION] Player 2 has chosen: " << p2Choice << std::endl;
        state = SelectionState::Finished;
    }
}

// FIX: Added sf::RenderWindow& window to match the header declaration
void SelectionManager::update(sf::RenderWindow& window) {
    if (state == SelectionState::Player1) {
        background.setTexture(bgP1);
    }
    else if (state == SelectionState::Player2) {
        background.setTexture(bgP2);
    }
}

void SelectionManager::render(sf::RenderWindow& window) {
    window.draw(background);
    if (!fighters.empty() && state != SelectionState::Finished) {
        window.draw(fighters[currentIndex].sprite);
    }
}

void SelectionManager::nextCharacter() {
    if (!fighters.empty()) {
        // Using .size() ensures it counts all 3 characters
        currentIndex = (currentIndex + 1) % fighters.size();
    }
}

void SelectionManager::previousCharacter() {
    if (!fighters.empty()) {
        if (currentIndex == 0) currentIndex = fighters.size() - 1;
        else currentIndex--;
    }
}