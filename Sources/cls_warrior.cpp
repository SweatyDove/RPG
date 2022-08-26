

#include "header.h"
#include "cls_warrior.h"
#include "cls_monster.h"

// #### Constructor
// #########
Warrior::Warrior(my::String& playerName, Player::Race playerRace) :
    Player(playerName, playerRace, Player::Spec::WARRIOR)
{
    // Nothing to do;
}

// #### Set damage for all warrior's skills
// ########
void Warrior::setDamage()
{
    mb_autoAttackDamage = warrior_default::autoAttackDamage + mb_strength * 2;
    mb_heavyBlowDamage  = warrior_default::heavyBlowDamage  + mb_strength * 5;
}

void Warrior::attack(Monster& monster) const
{
    monster.reduceHealth(mb_autoAttackDamage);
    std::cout << "You've dealed " << mb_autoAttackDamage << " damage to the " << monster.getName()
              << ". (It had " << monster.getCurrentHealth() << " hp left)." << std::endl;
    return;
}

bool Warrior::superAttack(Monster& monster)
{
    int staminaCost {30};

    if (this->getCurrentStamina() >= staminaCost) {
        monster.reduceHealth(mb_heavyBlowDamage);
        this->reduceStamina(staminaCost);
        std::cout << "You've dealed " << mb_heavyBlowDamage << " damage to the " << monster.getName()
                  << ". (It had " << monster.getCurrentHealth() << " hp left)." << std::endl;

        return true;
    }
    else {
        std::cout << "\nNot enough stamina for the super attack. "
                  << "You have only " << this->getCurrentStamina()
                  << "stamina points (need " << staminaCost << ")";

        return false;

    }
}

