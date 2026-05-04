#include "sfml.h"

HealthBar::HealthBar() {
    if (!font.loadFromFile("assets/Font/GalaferaMedium-V4xze.ttf")) {
        std::cout << "Error loading font!" << std::endl;
    }
    p1Back.setSize({ barWidth, barHeight });
    p1Back.setFillColor(sf::Color::Black);
    p1Back.setOutlineThickness(2);
    p1Back.setOutlineColor(sf::Color(100, 100, 100));
    p1Back.setPosition(margin, margin + 25.f);

    p1Front.setFillColor(sf::Color::Red);
    p1Front.setPosition(margin, margin + 25.f);

    p1Name.setFont(font);
    p1Name.setCharacterSize(20);
    p1Name.setFillColor(sf::Color::White);
    p1Name.setPosition(margin, margin);
    p1Name.setString("Player 1");

    p2Back.setSize({ barWidth, barHeight });
    p2Back.setFillColor(sf::Color::Black);
    p2Back.setOutlineThickness(2);
    p2Back.setOutlineColor(sf::Color(100, 100, 100));

    p2Back.setPosition(1280.0f - barWidth - margin, margin + 25.f);

    p2Front.setFillColor(sf::Color::Red);
    p2Front.setPosition(1280.0f - margin, margin + 25);
    p2Front.setScale(-1.f, 1.f);

    p2Name.setFont(font);
    p2Name.setCharacterSize(20);
    p2Name.setFillColor(sf::Color::White);
    p2Name.setString("Player 2");

    sf::FloatRect p2TextBounds = p2Name.getLocalBounds();
    p2Name.setPosition(1280.0f - p2TextBounds.width - margin, margin);
}

void HealthBar::setNames(std::string name1, std::string name2) {
    p1Name.setString(name1);
    p2Name.setString(name2);

    sf::FloatRect p2TextBounds = p2Name.getLocalBounds();
    p2Name.setPosition(1280.0f - p2TextBounds.width - margin, margin);
}

void HealthBar::update (float p1Health, float p1Max, float p2Health, float p2Max)
 {
    float p1Pct = p1Health / p1Max;
    float p2Pct = p2Health / p2Max;

    if (p1Pct < 0) p1Pct = 0;
    if (p2Pct < 0) p2Pct = 0;

    p1Front.setSize({ barWidth * p1Pct, barHeight });
    p2Front.setSize({ barWidth * p2Pct, barHeight });

    if (p1Pct < 0.3f) p1Front.setFillColor(sf::Color(255, 50, 50));
    if (p2Pct < 0.3f) p2Front.setFillColor(sf::Color(255, 50, 50));
}

void HealthBar::render(sf::RenderWindow& window) {
    window.draw(p1Back);
    window.draw(p1Front);
    window.draw(p2Back);
    window.draw(p2Front);
}