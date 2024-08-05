

#include "header.h"
#include "cls_warrior.h"
#include "cls_monster.h"


Warrior::~Warrior()
{
    //std::cerr << "\n[DEBUG]: Warrior destructor has called...";
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


//==============================================================================
// WHAT: Member function
//  WHY: Realizes the main (simple) player's attack.
//==============================================================================
void Warrior::attack(Monster& monster)
{
    monster.reduceHealth(mb_autoAttackDamage);

    SetConsoleTextAttribute(hConsole, CLR_DARK_PASTEL_GREEN);
    std::cout << "You've dealed " << mb_autoAttackDamage << " damage to the " << monster.getName()
           << ". It had (" << monster.getCurrentHealth() << ") hp left." << std::endl;
    SetConsoleTextAttribute(hConsole, CLR_VERY_LIGHT_GREY);

    return;
}

bool Warrior::superAttack(Monster& monster)
{
    int staminaCost {30};
    bool retValue {};

    if (this->getCurrentStamina() >= staminaCost) {
        monster.reduceHealth(mb_heavyBlowDamage);
        this->reduceStamina(staminaCost);

        SetConsoleTextAttribute(hConsole, CLR_DARK_PASTEL_GREEN);
        std::cout << "You've dealed (" << mb_heavyBlowDamage << ") damage to the " << monster.getName()
               << ". It had (" << monster.getCurrentHealth() << ") hp left." << std::endl;
        SetConsoleTextAttribute(hConsole, CLR_VERY_LIGHT_GREY);


        retValue = true;
    }
    else {
        std::cout << "\nNot enough stamina for the super attack. "
                  << "You have only " << this->getCurrentStamina()
                  << "stamina points (need " << staminaCost << ")."
                  << std::endl;
        //std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        retValue = false;
    }

    return retValue;
}



//==================================================================================================
//         NAME:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
void Warrior::commitSuicide()
{
    std::cout << "\nThe warrior threw his sword into the air, spread his arms and arched his chest to the sky... "
              << "\n...and the sword pierced his chest, thereby taking his life..." << std::endl;
    this->mb_currentHealth = 0;
}
