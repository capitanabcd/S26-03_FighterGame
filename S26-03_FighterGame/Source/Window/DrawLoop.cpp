#include "sfml.h"
extern Background gameBackground;

void window::DrawLoop()
{
	player1.IdleAnimation();
	player2.IdleAnimation();
	player1.MovementAnimation();
	player2.MovementAnimation();
	resize();
	player1.BeamAnimation();
	player1.HeavyAttackAnimation();
	player2.HeavyAttackAnimation();
	player1.StaggerAnimation();
	player2.StaggerAnimation();
	player1.RangedAttackAnimation();
	gameBackground.renderBackground(MainWindow);
	MainWindow.draw(player1.Sprite);
	MainWindow.draw(player2.Sprite);
	MainWindow.draw(player1.RangedAttack);
	debug();
}