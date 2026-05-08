#pragma once
#include "Player.h"
class HealthBar {
public:
    sf::ConvexShape background;
    sf::ConvexShape fill;

    float maxWidth = 410.f;
    float barHeight = 30.f;
    float slant = 20.f;
    float maxHealth = 100.f;
    bool mirrored = false;

    void init(sf::Vector2f position, sf::Color fillColor, bool mirrored = false);
    void update(float currentHealth);
    void draw(sf::RenderWindow& window);
};
class window
{
public:
    sf::RenderWindow MainWindow;
    sf::Event event;
    HealthBar healthBar1;
    HealthBar healthBar2;

    window() : MainWindow(sf::VideoMode(1280, 720), "game"), event()
    {
        float screenW = 1280.f;
        healthBar1.init({ 160.f, 66.f }, sf::Color(220, 30, 30), true); 
        healthBar2.init({ screenW - healthBar2.maxWidth - 160.f, 66.f }, sf::Color(30, 30, 220), false);
        MainWindow.setVerticalSyncEnabled(true);
    }

    void CloseWindow();
    void HandleEvents();
    void DisplayWindow();
    bool WindowisOpen() const;
    void DrawLoop();
};
