#include <SFML/Graphics.hpp>
#include <iostream>
#pragma once
class cell
{
	public:
	sf::Texture CellTexture[8];
	virtual void LoadTexture(sf::Texture* temp);
};
class goku
{
	public:
	sf::Texture GokuTexture[8];
	sf::Texture GokuHeavyAttack[13];
	virtual void LoadTexture(sf::Texture* temp, sf::Texture* heavy);
};
class freeza
{
	public:
	sf::Texture FreezaTexture[8];
	virtual void LoadTexture(sf::Texture* temp);
};