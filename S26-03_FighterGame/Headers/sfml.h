#include "Game.h"
#pragma once
class window
{
public:

	sf::RenderWindow MainWindow;
	sf::Event event;

	window() : MainWindow(sf::VideoMode(1280, 720), "game"), event()
	{
		MainWindow.setVerticalSyncEnabled(true);
	}

	void CloseWindow();
	void HandleEvents();
	void DisplayWindow();
	bool WindowisOpen() const;
	void DrawLoop();
};
void debug();

