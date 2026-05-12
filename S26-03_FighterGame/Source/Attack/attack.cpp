#include "sfml.h"

void Attack::TakeDamage(Players& player, float damage)
{
    player.currentHealth -= damage;

    if (player.currentHealth < 0)
    {
        player.currentHealth = 0;
    }
}

void Attack::TakeDamageWithStagger(Players& player, float damage)
{
    player.AddDamage(damage);
    player.currentHealth -= damage;

    StartFlash(player);

    if (player.currentHealth < 0)
    {
        player.currentHealth = 0;
    }
}
void Attack::StartFlash(Players& player)
{
    if (!player.isFlashing)
    {
        player.originalColor = player.Sprite.getColor();
        player.isFlashing = true;
        player.flashClock.restart();
        player.Sprite.setColor(sf::Color(255, 100, 100));
    }
}
void Attack::UpdateFlash(Players& player, float dt)
{
    if (player.isFlashing)
    {
        if (player.flashClock.getElapsedTime().asSeconds() >= player.flashDuration)
        {
            player.Sprite.setColor(player.originalColor);
            player.isFlashing = false;
        }
    }
}