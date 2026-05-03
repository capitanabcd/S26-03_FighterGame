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

    if (player.currentHealth < 0)
    {
        player.currentHealth = 0;
    }
}