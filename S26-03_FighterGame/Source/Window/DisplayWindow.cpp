#include "sfml.h"

void window::DisplayWindow()
{
	MainWindow.clear(sf::Color::Black);
	healthBar1.update(player1.currentHealth);
	healthBar2.update(player2.currentHealth);
	DrawLoop();
	gameEndScreen.render(MainWindow);
	MainWindow.display();

}