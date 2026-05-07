#include"sfml.h"
Players player1;
Players player2;
Background gameBackground;
SelectionScreen gameSelectionScreen;

int main()
{
	window GameWindow;
	window SelectionWindow;
	showLoadingScreen(GameWindow.MainWindow);
	showLoadingScreen(SelectionWindow.MainWindow);
	gameBackground.loadBackground(GameWindow.MainWindow);
	gameSelectionScreen.loadSelectionScreen(SelectionWindow.MainWindow);
	gameSelectionScreen.Load_IdleTextures();
	while (SelectionWindow.WindowisOpen() && gameSelectionScreen.isSelecting)
	{
		DeltaTime();

		while (SelectionWindow.MainWindow.pollEvent(SelectionWindow.event))
		{
			if (SelectionWindow.event.type == sf::Event::Closed)
				SelectionWindow.MainWindow.close();

			gameSelectionScreen.HandleInput(SelectionWindow.event);
		}

		gameSelectionScreen.UpdateSelectionScreen(dt, SelectionWindow.MainWindow);

		SelectionWindow.MainWindow.clear();
		showSelectionScreen(SelectionWindow.MainWindow);
		gameSelectionScreen.renderSelectionScreen(SelectionWindow.MainWindow);
		SelectionWindow.MainWindow.display();
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