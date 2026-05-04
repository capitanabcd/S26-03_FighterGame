#include"sfml.h"
Players player1;
Players player2;
HealthBar ui;
Background gameBackground;
SoundManager soundManager;


int main()
{
	
	window GameWindow;
	ui.setNames(player1.characterName, player2.characterName);
	showLoadingScreen(GameWindow.MainWindow);

	//background sound add-ons
	gameBackground.loadBackground(GameWindow.MainWindow);
	if (!soundManager.loadMusic())
		return -1;
	soundManager.playBackground();

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