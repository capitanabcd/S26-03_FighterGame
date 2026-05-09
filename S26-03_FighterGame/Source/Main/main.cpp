#include "sfml.h"
Players player1;
Players player2;
HealthBar ui;
Background gameBackground;
SelectionScreen gameSelectionScreen;
SoundManager soundManager;


int main()
{
    window GameWindow;
    showLoadingScreen(GameWindow.MainWindow);
    showLoadingScreen(GameWindow.MainWindow);
    gameBackground.loadBackground(GameWindow.MainWindow);
    gameSelectionScreen.loadSelectionScreen(GameWindow.MainWindow);
    gameSelectionScreen.Load_IdleTextures();
    gameBackground.loadBackground(GameWindow.MainWindow);
    if (!soundManager.loadMusic())
        return -1;
    soundManager.playBackground();
    while (GameWindow.WindowisOpen() && gameSelectionScreen.isSelecting)
    {
        DeltaTime();
        while (GameWindow.MainWindow.pollEvent(GameWindow.event))
        {
            if (GameWindow.event.type == sf::Event::Closed)
                GameWindow.MainWindow.close();
            gameSelectionScreen.HandleInput(GameWindow.event);
        }
        gameSelectionScreen.UpdateSelectionScreen(GameWindow.MainWindow);
        GameWindow.MainWindow.clear();
        showSelectionScreen(GameWindow.MainWindow);
        gameSelectionScreen.renderSelectionScreen(GameWindow.MainWindow);
        GameWindow.MainWindow.display();
    }
    player1.SetCharacterTexture(gameSelectionScreen.player1Choice);
    player2.SetCharacterTexture(gameSelectionScreen.player2Choice);

    player1.InitAfterTextureLoad();
    player2.InitAfterTextureLoad();

    while (GameWindow.WindowisOpen())
    {
        DeltaTime();
        while (GameWindow.MainWindow.pollEvent(GameWindow.event))
            GameWindow.HandleEvents();
        gameBackground.updateBackground();
        PlayerCalls();
        GameWindow.DisplayWindow();
    }
    return 0;

}