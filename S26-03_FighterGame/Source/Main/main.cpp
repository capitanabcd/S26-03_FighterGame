#include"sfml.h"
Players player1;
Players player2;
Background gameBackground;
SelectionScreen gameSelectionScreen;

int main()
{
	window GameWindow;
	showLoadingScreen(GameWindow.MainWindow);
	gameBackground.loadBackground(GameWindow.MainWindow);
	gameSelectionScreen.loadSelectionScreen();
	gameSelectionScreen.Load_IdleTextures();
	while (GameWindow.WindowisOpen() && gameSelectionScreen.isSelecting)
	{
		sf::Event event;

		while (GameWindow.MainWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				GameWindow.MainWindow.close();

			gameSelectionScreen.HandleInput(event);		}

		gameSelectionScreen.UpdateSelectionScreen();

		GameWindow.MainWindow.clear();
		gameSelectionScreen.renderSelectionScreen(GameWindow.MainWindow);
		GameWindow.MainWindow.display();
	}
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