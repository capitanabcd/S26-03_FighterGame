#include "sfml.h"
void Stagger::stagger(Players& victim)
{
    if (!victim.hitTaken && victim.staggerTime <= 0) {
        if (!(player->HeavyAttackFrames >= player->HeavyAttackTextures.size()-1)) return;
        victim.hitTaken = true;
        victim.staggerTime = 3.0f;
        victim.staggerclock.restart();
        victim.StaggerFrames = 0;
    }
}
void Stagger::UpdateStagger() {
    if (player->hitTaken) {
        staggerTime -= dt;
        if (staggerTime <= 0.0f) {
            player->hitTaken = false;
            staggerTime = 0.0f;
            player->StaggerFrames = 0;
        }
    }
}