

#include "header.h"
#include "cls_warrior.h"

// #### Constructor
// #########
Warrior::Warrior(my::String& playerName, Player::Race playerRace) :
    Player(playerName, playerRace, Player::Spec::WARRIOR)
{
    // Nothing to do;
}

// #### Set damage for all warrior's skills
// ########
void Warrior::setDamage() override
{
    mb_autoAttackDamage = warrior_default::autoAttackDamage + mb_strength * 2;
    mb_heavyBlowDamage  = warrior_default::heavyBlowDamage  + mb_strength * 5;
}

void Warrior::attack(Monster& monster) const override
{
    monster.reduceHealth(mb_autoAttackDamage);
    std::cout << "You've dealed " << mb_autoAttackDamage << " damage to the " << monster.getName()
              << ". (It had " << monster.getCurrentHealth() << " hp left)." << std::endl;
    return;
}

void Warrior::superAttack(Monster& monster) const override
{
    monster.reduceHealth(mb_heavyBlowDamage);
    std::cout << "You've dealed " << mb_heavyBlowDamage << " damage to the " << monster.getName()
              << ". (It had " << monster.getCurrentHealth() << " hp left)." << std::endl;
    return;

}

