#pragma once
#include "sfml.h"

class Players;

class Attack {
public:
	
	Players* player = nullptr;
	bool isattacking = false;
	bool isbasicattacking = false;
	bool hitTaken = false;
	bool isbeaming = false;
	bool fireRanged = false;
	int BeamNumbers = 3;
	sf::Sprite RangedAttack;
	sf::Clock attackClock;
	int oldFrame = 0;
	void CheckHit();
	void CheckRangeHit();
	void CheckBasicHit();
	void TakeDamage(Players& player, float damage);
	void TakeDamageWithStagger(Players& player, float damage);
	void StartFlash(Players& player);
	void UpdateFlash(Players& player, float dt);	
};