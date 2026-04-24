#include "sfml.h"
#include "SelectionManager.h"

// 1. The "Shout-out" to your texture loader
extern Loadtextures textures;

Players player1;
Players player2;
Background gameBackground;
SelectionManager menu;
bool inMenu = true;

int main()
{
	window GameWindow;
	gameBackground.loadBackground(GameWindow.MainWindow);
	menu.load(GameWindow.MainWindow);

	while (GameWindow.WindowisOpen())
	{
		DeltaTime();
		while (GameWindow.MainWindow.pollEvent(GameWindow.event))
		{
			GameWindow.HandleEvents();
		}

		if (inMenu)
		{
			menu.update(GameWindow.MainWindow);

			if (menu.isSelectionFinished()) {
				// 2. SWITCH THE STATE
				inMenu = false;

				// 3. THE FIX: Tell the loader to look at the choice and swap textures!
				textures.SetCharacterTexture();

				std::cout << "Menu Closed. Choice Loaded!" << std::endl;
			}
		}
		else
		{
			gameBackground.updateBackground();
			player1.Updatejump();
			player1.Movement();
			player2.Updatejump();
			player2.Movement();
		}

		GameWindow.DisplayWindow();
	}
	return 0;
}