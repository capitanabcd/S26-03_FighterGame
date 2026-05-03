#include "sfml.h"
extern Background gameBackground;

void window::DrawLoop()
{
	player1.invert();
	player2.invert();
	player1.IdleAnimation();
	player2.IdleAnimation();
	player1.MovementAnimation();
	player2.MovementAnimation();
	resize();
	player1.BeamAnimation();
	player2.BeamAnimation();
	player1.HeavyAttackAnimation();
	player2.HeavyAttackAnimation();
	player1.BasicAttackAnimation();
	player2.BasicAttackAnimation();
	player1.RangedAttackAnimation();
	player2.RangedAttackAnimation();
	player1.StaggerAnimation();
	player2.StaggerAnimation();
	gameBackground.renderBackground(MainWindow);
	MainWindow.draw(player1.Sprite);
	MainWindow.draw(player2.Sprite);
	MainWindow.draw(player1.RangedAttack);
	MainWindow.draw(player2.RangedAttack);
	debug();
}