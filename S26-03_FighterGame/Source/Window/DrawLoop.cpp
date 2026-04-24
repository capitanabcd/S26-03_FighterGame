#include "sfml.h"

void window::DrawLoop()
{
	resize();
	player1.HeavyAttackAnimation();
	player1.IdleAnimation();
	player2.IdleAnimation();
	player1.MovementAnimation();
	player2.MovementAnimation();
	
	MainWindow.draw(player1.Sprite);
	MainWindow.draw(player2.Sprite);
	debug();
}