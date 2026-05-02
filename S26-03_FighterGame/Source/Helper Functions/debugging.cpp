#include "sfml.h"
void debug()
{
    std::string display;
    if (player1.IsMoving)
        display += "MOVING";
    else
    display += "      ";
    display += " | ";

    if (player1.isjumping)
        display += "JUMPING";
    else
        display += "       ";
    std::cout << "\r" << display;

    std::cout << player1.HeavyAttackTextures.size() << std::flush;
}