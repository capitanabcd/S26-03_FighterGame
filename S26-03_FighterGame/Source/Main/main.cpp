#include"sfml.h"
Players player1;
Players player2;
Background gameBackground;

int main()
{
	window GameWindow;
	showLoadingScreen(GameWindow.MainWindow);
	gameBackground.loadBackground(GameWindow.MainWindow);
	while (GameWindow.WindowisOpen())
	{	
		DeltaTime();
		while (GameWindow.MainWindow.pollEvent(GameWindow.event))
		{
			GameWindow.HandleEvents();
		}
		gameBackground.updateBackground();
		PlayerCalls();
		GameWindow.DisplayWindow();
	}
	return 0;
}