#include "sfml.h"

void RestartGame()
{
    player1.currentHealth = player1.maxHealth;
    player2.currentHealth = player2.maxHealth;
    player1.isalive = true;
    player2.isalive = true;

    player1.Sprite.setColor(sf::Color::White);
    player2.Sprite.setColor(sf::Color::White);
    player1.isFlashing = false;
    player2.isFlashing = false;
    player1.originalColor = sf::Color::White;
    player2.originalColor = sf::Color::White;

    player1.Sprite.setPosition(100, ground);
    player2.Sprite.setPosition(500, ground);

    player1.isattacking = false;
    player1.isbasicattacking = false;
    player1.isbeaming = false;
    player1.fireRanged = false;
    player1.hitTaken = false;
    player1.isStaggered = false;
    player1.isFlashing = false;

    player2.isattacking = false;
    player2.isbasicattacking = false;
    player2.isbeaming = false;
    player2.fireRanged = false;
    player2.hitTaken = false;
    player2.isStaggered = false;
    player2.isFlashing = false;

    player1.ResetStagger();
    player2.ResetStagger();

    player1.BeamNumbers = 3;
    player2.BeamNumbers = 3;

    gameSelectionScreen.isSelecting = true;
    gameSelectionScreen.player1Selected = false;
    gameSelectionScreen.player2Selected = false;
    gameSelectionScreen.isEnterPlaying = false;
    gameSelectionScreen.isOnePlaying = false;
    gameSelectionScreen.isTwoPlaying = false;
    gameSelectionScreen.player1Choice = 0;
    gameSelectionScreen.player2Choice = 0;
    gameSelectionScreen.index1 = 0;
    gameSelectionScreen.index2 = 1;
    gameSelectionScreen.frames1 = 0;
    gameSelectionScreen.frames2 = 0;

    player1.IdleTextures.clear();
    player1.MovementTextures.clear();
    player1.StaggerTextures.clear();
    player1.HeavyAttackTextures.clear();
    player1.BeamTextures.clear();
    player1.RangedTexture.clear();
    player1.BasicAttackTexture.clear();

    player2.IdleTextures.clear();
    player2.MovementTextures.clear();
    player2.StaggerTextures.clear();
    player2.HeavyAttackTextures.clear();
    player2.BeamTextures.clear();
    player2.RangedTexture.clear();
    player2.BasicAttackTexture.clear();

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
}