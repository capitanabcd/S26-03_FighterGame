#include "sfml.h"

void window::DisplayWindow()
{
	MainWindow.clear(sf::Color::Black);
	DrawLoop();
	MainWindow.display();

}


