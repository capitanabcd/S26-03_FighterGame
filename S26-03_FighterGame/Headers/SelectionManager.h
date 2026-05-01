#ifndef SELECTION_MANAGER_H
#define SELECTION_MANAGER_H

#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>


struct Character {
    std::string name;
    sf::Texture texture;
    sf::Sprite sprite;
};

enum class SelectionState { Player1, Player2, Finished };

class SelectionManager {
private:
    sf::Texture bgP1;
    sf::Texture bgP2;
    sf::Sprite background;
    std::string p1Choice;
    std::string p2Choice;


    std::vector<Character> fighters;

    int currentIndex;
    SelectionState state;
    const sf::Vector2f previewPos = { 670.f, 380.f };

public:
    SelectionManager();
    bool init(sf::RenderWindow& window);
    void handleInput(sf::Event& event);
    void update(sf::RenderWindow& window);
    void render(sf::RenderWindow& window);
    void nextCharacter();
    void previousCharacter();
    void confirmSelection();

    bool isSelectionFinished() const { return state == SelectionState::Finished; }
    std::string getP1Choice() const { return p1Choice; }
    std::string getP2Choice() const { return p2Choice; }
};

#endif