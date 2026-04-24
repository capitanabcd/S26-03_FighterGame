#include "sfml.h"
#include "SelectionManager.h" // We need this to see the menu object

// Externs to connect to main.cpp
extern SelectionManager menu;
extern bool inMenu;
extern Background gameBackground;
extern Players player1;
extern Players player2;

void window::DrawLoop()
{
	if (inMenu)
	{
		// 1. Just draw the selection screen
		menu.render(MainWindow);
	}
	else
	{
		// 2. Battle Screen Logic
		player1.IdleAnimation();
		player2.IdleAnimation();
		player1.MovementAnimation();
		player2.MovementAnimation();

		resize();

		// Draw background first, then players on top
		gameBackground.renderBackground(MainWindow);

		MainWindow.draw(player1.Sprite);
		MainWindow.draw(player2.Sprite);

		debug();
	}
}