#include "sfml.h"
extern Background gameBackground;

void window::DrawLoop()
{
	player1.IdleAnimation();
	player2.IdleAnimation();
	player1.MovementAnimation();
	player2.MovementAnimation();
	resize();
	gameBackground.renderBackground(MainWindow);
	MainWindow.draw(player1.Sprite);
	MainWindow.draw(player2.Sprite);
	debug();
}