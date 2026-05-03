#include "sfml.h"

Stagger::Stagger()
    : isStaggered(false)
    , currentStaggerTime(0.0f)
    , damageTakenInWindow(0.0f)
    , staggerTime(0.0f)
{
    damageWindowClock.restart();
    staggerAnimationClock.restart();
    staggerclock.restart();
}

void Stagger::AddDamage(float damage)
{
    if (isStaggered) return;

    damageTakenInWindow += damage;
}

void Stagger::UpdateStagger(float dt)
{
    if (!isStaggered)
    {
        if (damageWindowClock.getElapsedTime().asSeconds() >= StaggerWindow)
        {
            damageTakenInWindow = 0.0f;
            damageWindowClock.restart();
        }
        if (!player->hitTaken && damageTakenInWindow >= DamageToStagger)
        {
            TriggerStagger();
        }
    }
    else
    {
        currentStaggerTime -= dt;
        staggerTime = currentStaggerTime;

        if (currentStaggerTime <= 0.0f)
        {
            ResetStagger();
        }
    }
}

void Stagger::TriggerStagger()
{
    isStaggered = true;
    currentStaggerTime = StaggerDuration;
    staggerTime = StaggerDuration;

    damageTakenInWindow = 0.0f;
    damageWindowClock.restart();
    staggerAnimationClock.restart();
    staggerclock.restart();

    player->hitTaken = true;
    player->StaggerFrames = 0;

    player->isattacking = false;
    player->isbeaming = false;
    player->fireRanged = false;
    player->IsMoving = false;

    player->HeavyAttackFrames = 0;
    player->BeamFrames = 0;
    player->RangedFrames = 0;
}

void Stagger::ResetStagger()
{
    isStaggered = false;
    currentStaggerTime = 0.0f;
    staggerTime = 0.0f;

    player->hitTaken = false;
    player->StaggerFrames = 0;

    if (!player->IdleTextures.empty())
    {
        player->Sprite.setTexture(player->IdleTextures[0], true);
    }
    player->RevertOrigin();
}

void Stagger::UpdateStaggerAnimation()
{
    if (!isStaggered && !player->hitTaken) return;

    if (staggerAnimationClock.getElapsedTime().asSeconds() >= 0.2f)
    {
        if (player->StaggerFrames < player->StaggerTextures.size())
        {
            player->Sprite.setTexture(player->StaggerTextures[player->StaggerFrames], true);
            staggerAnimationClock.restart();
            staggerclock.restart();
            player->StaggerFrames++;

            if (player->StaggerFrames >= player->StaggerTextures.size())
            {
                player->StaggerFrames = player->StaggerTextures.size() - 1;
            }
            player->RevertOrigin();
        }
    }
}