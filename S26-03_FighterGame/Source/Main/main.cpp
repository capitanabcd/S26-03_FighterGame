#include "sfml.h"
#include "SelectionManager.h"

    
Players player1;
Players player2;
Background gameBackground;
SelectionManager characterSelector;

int main()
{
    window GameWindow;


    if (!characterSelector.init(GameWindow.MainWindow)) {
        std::cerr << "Failed to initialize Selection Screen assets!" << std::endl;
        return -1;
    }

    while (GameWindow.WindowisOpen())
    {
        DeltaTime();

        while (GameWindow.MainWindow.pollEvent(GameWindow.event))
        {
          
            if (!characterSelector.isSelectionFinished()) {
                characterSelector.handleInput(GameWindow.event);
            }
            GameWindow.HandleEvents();
        }

        if (!characterSelector.isSelectionFinished())
        {
            
            characterSelector.update(GameWindow.MainWindow);

            GameWindow.MainWindow.clear();
            characterSelector.render(GameWindow.MainWindow);
            GameWindow.MainWindow.display();
        }
        else
        {
            
            static bool assetsLoaded = false;

            if (!assetsLoaded) {
                
                showLoadingScreen(GameWindow.MainWindow);

            
                player1.loadCharacter(characterSelector.getP1Choice());
                player2.loadCharacter(characterSelector.getP2Choice());

                
                gameBackground.loadBackground(GameWindow.MainWindow);

                assetsLoaded = true;
            }

            
            gameBackground.updateBackground();
            PlayerCalls();
            GameWindow.DisplayWindow();
        }
    }
    return 0;
}