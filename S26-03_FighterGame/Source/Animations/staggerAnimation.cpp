#include "sfml.h"

void animations::stagger() {
	//stagger animation

	if (player->hitTaken) {
		staggerTime = 0.5f;
	}
}