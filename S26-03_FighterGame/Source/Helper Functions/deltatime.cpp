#include "sfml.h"

float dt;
void DeltaTime()
{
    static sf::Clock clock;
    dt = clock.restart().asSeconds();
    if (dt > 0.2f)
    {
        dt = 0.2f;
    }
}