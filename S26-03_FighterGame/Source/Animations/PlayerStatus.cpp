#include "sfml.h"

void animations::checkStatus() {
	if (player->isalive) {
		if (player->currentHealth <= 0) {
			player->isalive = false;
		}
	}
}