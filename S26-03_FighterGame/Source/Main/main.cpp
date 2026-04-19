#include "sfml.h"
Players player1;
Players player2;
int main()
{
	window GameWindow;
	while (GameWindow.WindowisOpen())
	{	
		DeltaTime();
		while (GameWindow.MainWindow.pollEvent(GameWindow.event))
		{
			GameWindow.HandleEvents();
		}
		player1.Updatejump();
		player1.Movement();
		player2.Updatejump();
		player2.Movement();
		GameWindow.DisplayWindow();
	}
	return 0;
}