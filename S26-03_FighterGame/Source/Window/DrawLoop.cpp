#include "sfml.h"

void window::DrawLoop()
{
	player1.IdleAnimation();
	player2.IdleAnimation();
	player1.MovementAnimation();
	player2.MovementAnimation();
	resize();
	MainWindow.draw(player1.Sprite);
	MainWindow.draw(player2.Sprite);
	debug();
}