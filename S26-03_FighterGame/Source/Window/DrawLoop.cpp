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
	player1.checkStatus();
	player2.checkStatus();
	gameBackground.renderBackground(MainWindow);
	MainWindow.draw(player1.Sprite);
	MainWindow.draw(player2.Sprite);
	MainWindow.draw(player1.RangedAttack);
	MainWindow.draw(player2.RangedAttack);
	healthBar1.draw(MainWindow);
	healthBar2.draw(MainWindow);
	debug();
}