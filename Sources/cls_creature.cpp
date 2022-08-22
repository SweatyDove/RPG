
#include "header.h"
#include "cls_creature.h"



// #### Creature constructor
// #############
Creature::Creature(Type type) :
    mb_type {type}
{
    // Nothing to do;
}

Creature::Creature(Creature::Type type, int level) :
    mb_type {type},
    mb_level {level}
{
    // Nothing to do;
}

Creature::Creature(Creature::Type type, int level, int health) :
    mb_type {type},
    mb_level {level},
    mb_health {health}
{
    // Nothing to do;
}

// #### Function returns true if current creature is dead
// #############
bool Creature::isDead() const
{
    return (mb_health <= 0);
}

// #### Function reduce health of the current creature by specified magnitude
// #############
void Creature::reduceHealth(int health)
{
    mb_health -= health;
    return;
}

// #### Function returns the level of the creature
// ###############
int Creature::getLevel() const
{
    return mb_level;
}

// #### Function returns current health of the creature
// #############
int Creature::getCurrentHealth() const
{
    return mb_health;
}
