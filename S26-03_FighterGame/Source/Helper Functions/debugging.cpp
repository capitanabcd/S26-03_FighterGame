#include"sfml.h"

void debug()
{
    std::cout << "\r";

    if (player1.IsMoving)
        std::cout << "MOVING";
    else
        std::cout << "      ";

    std::cout << " | ";

    if (player1.isjumping)
        std::cout << "JUMPING";
    else
        std::cout << "       ";

    std::cout << " | HP1: " << (int)player1.currentHealth
        << " | HP2: " << (int)player2.currentHealth
        << "        "   
        << std::flush;
}