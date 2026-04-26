#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class cell
{
	public:
	sf::Texture CellTexture[8];
	sf::Texture CellHeavyAttack[7];
	sf::Texture CellStagger[3];
	virtual void LoadTexture(sf::Texture* temp, sf::Texture* heavy, sf::Texture* stagger);

};
class goku
{
	public:
	sf::Texture GokuTexture[8];
	sf::Texture GokuHeavyAttack[13];
	sf::Texture GokuStagger[3];
	virtual void LoadTexture(sf::Texture* temp, sf::Texture* heavy, sf::Texture* stagger);
};
class freeza
{
	public:
	sf::Texture FreezaTexture[8];
	sf::Texture FreezaHeavyAttack[10];
	sf::Texture FreezaStagger[3];
	virtual void LoadTexture(sf::Texture* temp, sf::Texture* heavy, sf::Texture* stagger);
};