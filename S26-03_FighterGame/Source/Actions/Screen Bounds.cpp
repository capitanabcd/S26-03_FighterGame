#include "sfml.h"

void movement::ScreenBounds(int screenwidth)
{
    sf::FloatRect bounds = player->Sprite.getGlobalBounds();
    sf::Vector2f position = player->Sprite.getPosition();

    if (bounds.left < 0)       //Left
    {
        position.x -= bounds.left;
    }

    if (bounds.left + bounds.width > screenwidth)     //Right
    {
        position.x -= (bounds.left + bounds.width - screenwidth);
    }

    player->Sprite.setPosition(position);

}