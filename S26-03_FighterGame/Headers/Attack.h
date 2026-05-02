#pragma once
#include "sfml.h"
class Attack {
public:
	Players* player = nullptr;
	bool isattacking = false;
	bool hitTaken = false;
	int oldFrame = 0;

	void punch();
	void CheckHit();
	void TakeDamage(Players& player, float damage);

};