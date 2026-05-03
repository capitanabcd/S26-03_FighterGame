#pragma once
#include "sfml.h"

class HealthBar {
public:
    sf::RectangleShape p1Back, p1Front;
    sf::RectangleShape p2Back, p2Front;

    // New Text Variables
    sf::Font font;
    sf::Text p1Name;
    sf::Text p2Name;

    const float barWidth = 400.0f;
    const float barHeight = 30.0f;
    const float margin = 20.0f;

    HealthBar();
    

    void setNames(std::string name1, std::string name2);

    void update(float p1Health, float p1Max, float p2Health, float p2Max);

    void render(sf::RenderWindow& window);
};

extern HealthBar ui;
static std::string name1;
static std::string name2;