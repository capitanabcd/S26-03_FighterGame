#include"Player.h"
#include "SoundManager.h"
Players::Players()
{
    s = new SoundManager();
    if (!s->loadSounds()) {
        std::cout << "Player " << PlayerNumber << " failed to load sounds!" << std::endl;
    }
    maxHealth = 100;
    currentHealth = maxHealth;

    movement::player = this;
    jumping::player = this;
    animations::player = this;
    collide::player = this;
    Attack::player = this;
    Stagger::player = this;

    static int nextPlayerNumber = 1;
    PlayerNumber = nextPlayerNumber;
    nextPlayerNumber++;

    clock.restart();

    x = 100;
    Sprite.setTexture(IdleTextures[0]);
    Sprite.setScale(4.f, 4.f);
    setupOrigin();

    y = ground - Sprite.getGlobalBounds().height;

    if (PlayerNumber == 1)
    {
        Sprite.setPosition(x, ground);
    }
    if (PlayerNumber == 2)
    {
        Sprite.setPosition(x + 400, ground);
    }
}