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

    std::cout << "| Health P1: " << (int)player1.currentHealth
        << "| Health P2: " << (int)player2.currentHealth
        << "        "   
        << std::flush;
}