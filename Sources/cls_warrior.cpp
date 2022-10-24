

#include "header.h"
#include "cls_warrior.h"
#include "cls_monster.h"


Warrior::~Warrior()
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

int Warrior::getAttackDamage() const
{
    return mb_autoAttackDamage;
}

int Warrior::getSuperAttackDamage() const
{
    return mb_heavyBlowDamage;
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
    bool retValue {};

    if (this->getCurrentStamina() >= staminaCost) {
        monster.reduceHealth(mb_heavyBlowDamage);
        this->reduceStamina(staminaCost);
        std::cout << "You've dealed " << mb_heavyBlowDamage << " damage to the " << monster.getName()
                  << ". (It had " << monster.getCurrentHealth() << " hp left)." << std::endl;

        retValue = true;
    }
    else {
        clearWorkScreen(WORK_SCREEN_LINES, WORK_SCREEN_COLUMNS);
        std::cout << "\nNot enough stamina for the super attack. "
                  << "You have only " << this->getCurrentStamina()
                  << "stamina points (need " << staminaCost << ")"
                  << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
        moveCursor(-2, 0);
        clearWorkScreen(2, WORK_SCREEN_COLUMNS);

        retValue = false;
    }

    return retValue;
}

