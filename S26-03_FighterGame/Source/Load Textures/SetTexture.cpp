#include "sfml.h"
#include "SelectionManager.h"
Loadtextures textures;
// 1. Ensure this matches your Header exactly!
void Loadtextures::LoadTexture(sf::Texture* temp)
{
    // Even if it's empty, it needs to exist so the Linker is happy
}

extern SelectionManager menu;

void Loadtextures::SetCharacterTexture()
{
   
    cell::LoadTexture(Textures);
    std::cout << "DEBUG: I am forcing the game to load Cell!" << std::endl;
}