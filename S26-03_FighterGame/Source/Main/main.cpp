#include "sfml.h"
#include "background.h"
Players player1;
Players player2;
Background gameBackground;

int main()
{
	window GameWindow;
	gameBackground.loadBackground(GameWindow.MainWindow);
	while (GameWindow.WindowisOpen())
	{	
		DeltaTime();
		while (GameWindow.MainWindow.pollEvent(GameWindow.event))
		{
			GameWindow.HandleEvents();
		}
		gameBackground.updateBackground();
		player1.Updatejump();
		player1.Movement();
		player2.Updatejump();
		player2.Movement();
		GameWindow.DisplayWindow();
	}
	return 0;
}