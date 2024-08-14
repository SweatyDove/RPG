

#include "main.h"
#include "warrior.h"
#include "monster.h"



//==================================================================================================
//         NAME:    --------
//  DESCRIPTION:    Destructor
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
Warrior::~Warrior()
{
    //std::cerr << "\n[DEBUG]: Warrior destructor has called...";
    // Nothing to do;
}



//==================================================================================================
//         NAME:    --------
//  DESCRIPTION:    Set damage for all warrior's skills
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
void Warrior::setDamage()
{
    mb_autoAttackDamage = warrior_default::autoAttackDamage + mb_strength * 2;
    mb_heavyBlowDamage  = warrior_default::heavyBlowDamage  + mb_strength * 5;
}



//==================================================================================================
//         NAME:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
int Warrior::getAttackDamage() const
{
    return mb_autoAttackDamage;
}



//==================================================================================================
//         NAME:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
int Warrior::getSuperAttackDamage() const
{
    return mb_heavyBlowDamage;
}



//==================================================================================================
//         NAME:    --------
//  DESCRIPTION:    Member function that realizes the warrior's base attack.
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
void Warrior::attack(Monster& monster)
{
    monster.reduceHealth(mb_autoAttackDamage);

    SetConsoleTextAttribute(hConsole, CLR_DARK_PASTEL_GREEN);
    std::cout << "You've dealed " << mb_autoAttackDamage << " damage to the " << monster.getName()
           << ". It had (" << monster.getCurrentHealth() << ") hp left." << std::endl;
    SetConsoleTextAttribute(hConsole, CLR_VERY_LIGHT_GREY);

    return;
}



//==================================================================================================
//         NAME:    --------
//  DESCRIPTION:    Member function that realizes the warrior's special attack.
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
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
//     COMMENTS:    Return the cost of warrior's special attack in points of his main resource.
//                  Or I can add cost in all available resources (0 in mana, 30 in stamina and 10 in
//                  concentration, for example).
//==================================================================================================
int Warrior::getSuperAttackCost() const
{
    return mb_heavyBlowStaminaCost;
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
