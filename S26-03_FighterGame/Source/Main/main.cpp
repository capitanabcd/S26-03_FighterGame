#include "sfml.h"
#include "SelectionManager.h"

// Global/Member Objects
Players player1;
Players player2;
Background gameBackground;
SelectionManager characterSelector;

int main()
{
    window GameWindow;

    // 1. Initialize the Selection Manager first
    // We pass the window to handle scaling for different background sizes
    if (!characterSelector.init(GameWindow.MainWindow)) {
        std::cerr << "Failed to initialize Selection Screen assets!" << std::endl;
        return -1;
    }

    while (GameWindow.WindowisOpen())
    {
        DeltaTime();

        while (GameWindow.MainWindow.pollEvent(GameWindow.event))
        {
            // If we are still selecting characters, let the manager handle input
            if (!characterSelector.isSelectionFinished()) {
                characterSelector.handleInput(GameWindow.event);
            }
            GameWindow.HandleEvents();
        }

        if (!characterSelector.isSelectionFinished())
        {
            // --- PHASE 1: SELECTION ---
            characterSelector.update(GameWindow.MainWindow);

            GameWindow.MainWindow.clear();
            characterSelector.render(GameWindow.MainWindow);
            GameWindow.MainWindow.display();
        }
        else
        {
            // --- PHASE 2: LOADING & GAMEPLAY ---
            static bool assetsLoaded = false;

            if (!assetsLoaded) {
                // Show a quick loading screen while textures move to GPU
                showLoadingScreen(GameWindow.MainWindow);

                // BRIDGE: Pass the selected names to the Player objects
                player1.loadCharacter(characterSelector.getP1Choice());
                player2.loadCharacter(characterSelector.getP2Choice());

                // Final gameplay background load
                gameBackground.loadBackground(GameWindow.MainWindow);

                assetsLoaded = true;
            }

            // Actual Combat Logic
            gameBackground.updateBackground();
            PlayerCalls();
            GameWindow.DisplayWindow();
        }
    }
    return 0;
}