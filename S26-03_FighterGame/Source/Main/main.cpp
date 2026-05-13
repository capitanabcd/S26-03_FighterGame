#include "sfml.h"
Players player1;
Players player2;
HealthBar ui;
Background gameBackground;
SelectionScreen gameSelectionScreen;
SoundManager soundManager;
EndScreen gameEndScreen;
window GameWindow;

int main()
{
    showLoadingScreen(GameWindow.MainWindow);
    gameBackground.loadBackground(GameWindow.MainWindow);
    gameSelectionScreen.loadSelectionScreen(GameWindow.MainWindow);
    gameSelectionScreen.Load_IdleTextures();
    gameEndScreen.loadEndTextures();

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
        {
            if (GameWindow.event.type == sf::Event::Closed)
            GameWindow.MainWindow.close();
            GameWindow.HandleEvents();
            gameEndScreen.handleInput(GameWindow.event);
        }
        if (!gameEndScreen.isActive && !gameEndScreen.restartRequested)
        {
            if (player1.currentHealth <= 0)
            {
                gameEndScreen.showWinner(2, GameWindow.MainWindow);
            }
            else if (player2.currentHealth <= 0)
            {
                gameEndScreen.showWinner(1, GameWindow.MainWindow);
            }
        }
        if (gameEndScreen.restartRequested)
        {
            RestartGame();
            gameEndScreen.restartRequested = false;
            gameEndScreen.isActive = false;
        }
        if (!gameEndScreen.isActive)
        {
            gameBackground.updateBackground();
            PlayerCalls();
        }

        GameWindow.DisplayWindow();
    }

    return 0;
}