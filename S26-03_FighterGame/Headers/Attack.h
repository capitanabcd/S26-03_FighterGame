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

	void punch();
	void beam();
	void CheckHit();

};