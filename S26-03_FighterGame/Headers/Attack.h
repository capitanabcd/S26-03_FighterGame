#pragma once
#include "sfml.h"
class Attack {
public:
	Players* player = nullptr;
	bool isattacking = false;
	bool hitTaken = false;
	bool isbeaming = false;
	bool fireRanged = false;
	sf::Sprite RangedAttack;
	sf::Clock attackClock;
	int oldFrame = 0;
	void CheckHit();
	void CheckRangeHit();
	void TakeDamage(Players& player, float damage);
	void TakeDamageWithStagger(Players& player, float damage);

};