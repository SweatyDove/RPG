

#include "main.h"
#include "warrior.h"
#include "monster.h"




//==================================================================================================
//         TYPE:    Constructor
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
Warrior::Warrior(Player::Race race, std::string name):
    Player {race, name}
{
    // STAYED HERE! Need to set values to all warrior active characteristics
    mb_baseAttack.setEffect();
    mb_autoAttackDamage = warrior_default::autoAttackDamage + mb_maxStrength * 2;
    mb_heavyBlowDamage  = warrior_default::heavyBlowDamage  + mb_maxStrength * 5;
}


//==================================================================================================
//         TYPE:    --------
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
//  DESCRIPTION:    Set settings for warriors skills. Another option is to calculate settings of one
//                  or another skill in place.
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
//void Warrior::setDamage()
//{
//    this->setAutoAttackSettings();
//    this->setHeavyBlowSettings();
//    mb_autoAttackDamage = warrior_default::autoAttackDamage + mb_strength * 2;
//    mb_heavyBlowDamage  = warrior_default::heavyBlowDamage  + mb_strength * 5;
//}




//==================================================================================================
//         NAME:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
void Warrior::cast(Spell& spell, Creature& creature)
{
    int spellEffect {spell.getEffect()};

    this->changeStamina(-spell.getCost());
    creature.changeHealth(-spellEffect);

    SetConsoleTextAttribute(hConsole, CLR_DARK_PASTEL_GREEN);
    std::cout << "You've dealed (" << spellEffect << ") damage to the " << creature.getName()
           << ". It had (" << creature.getCurrentHealth() << ") hp left." << std::endl;
    SetConsoleTextAttribute(hConsole, CLR_VERY_LIGHT_GREY);

}


//==================================================================================================
//         NAME:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
Player::FightOption Warrior::chooseFightOption(Monster& monster)
{
    int playerStamina {this->getCurrentStamina()};


//    // ######## Intro message title
//    std::cout << "Monster has (" << monster.getCurrentHealth() << ") hp and deals (" << monster.getDamage()
//              << ") points of damage per attack."
//              << "\nYours current health: " << this->getCurrentHealth() << std::endl;

//    std::cout << "What are you going to do? Press an appropriate button:\n";

    // ######## 1-st option
    std::cout << "\n[1] - attack monster with " << mb_baseAttack.getName() << "and deal ("
              << mb_baseAttack.getEffect() << ") damage to the monster";

    // ######## 2-nd option
    /* Maybe it is better to replace Stamina on structure (or array) of player resources. Or add function
     * to get main resources...
     */
    std::cout << "\n[2] - attack monster with " << mb_specialAttack.getName() << "and deal ("
              << mb_specialAttack.getEffect() << ") to the monster. " << "This attack costs ("
              << mb_specialAttack.getCost() <<") stamina points." << std::endl;

    // ######## 3-rd option
    std::cout << "\n[3] - Commit suicide...";

    // ######## 4-th option
    std::cout << "\n[0] - Run away: You have (" << mb_escapeChance << ") chance to escape from monster."
              << " If you could't, monster would deal (" << monster.getDamage() << ") damage."<< std::endl;


    // ######## Choice loop
    int choice {};
    bool choiceLoop {true};
    do {
        std::cout << "Your choice: ";
        std::cin >> choice;

        switch(choice) {
        case static_cast<int>(Warrior::FightOption::SUPER_ATTACK):
            if (playerStamina >= mb_specialAttack.getCost()) {
                choiceLoop = false;
            }
            else {
                HANDLE hConsole {GetStdHandle(STD_OUTPUT_HANDLE)};
                SetConsoleTextAttribute(hConsole, CLR_PALE_PRIM);
                std::cout << "Not enough stamina points!";
                SetConsoleTextAttribute(hConsole, CLR_VERY_LIGHT_GREY);
            }
            break;
        case static_cast<int>(Warrior::FightOption::FLEE):
        case static_cast<int>(Warrior::FightOption::ATTACK):
        case static_cast<int>(Warrior::FightOption::COMMIT_SUICIDE):
            choiceLoop = false;
            break;
        default:
            std::cout << "Incorrect choice. Please, try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    while (choiceLoop);

    std::cout << '\n';

    // ######## Returning player's choice
    return static_cast<Player::FightOption>(choice);
}






//==================================================================================================
//         NAME:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
//int Warrior::getAttackDamage() const
//{
//    return mb_autoAttackDamage;
//}



//==================================================================================================
//         NAME:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
//int Warrior::getSuperAttackDamage() const
//{
//    return mb_heavyBlowDamage;
//}



//==================================================================================================
//         NAME:    --------
//  DESCRIPTION:    Member function that realizes the warrior's base attack.
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
//void Warrior::attack(Monster& monster)
//{
//    monster.reduceHealth(mb_autoAttackDamage);

//    SetConsoleTextAttribute(hConsole, CLR_DARK_PASTEL_GREEN);
//    std::cout << "You've dealed " << mb_autoAttackDamage << " damage to the " << monster.getName()
//           << ". It had (" << monster.getCurrentHealth() << ") hp left." << std::endl;
//    SetConsoleTextAttribute(hConsole, CLR_VERY_LIGHT_GREY);

//    return;
//}



//==================================================================================================
//         NAME:    --------
//  DESCRIPTION:    Member function that realizes the warrior's special attack.
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
//bool Warrior::superAttack(Monster& monster)
//{
//    int staminaCost {30};
//    bool retValue {};

//    if (this->getCurrentStamina() >= staminaCost) {
//        monster.reduceHealth(mb_heavyBlowDamage);
//        this->reduceStamina(staminaCost);

//        SetConsoleTextAttribute(hConsole, CLR_DARK_PASTEL_GREEN);
//        std::cout << "You've dealed (" << mb_heavyBlowDamage << ") damage to the " << monster.getName()
//               << ". It had (" << monster.getCurrentHealth() << ") hp left." << std::endl;
//        SetConsoleTextAttribute(hConsole, CLR_VERY_LIGHT_GREY);


//        retValue = true;
//    }
//    else {
//        std::cout << "\nNot enough stamina for the super attack. "
//                  << "You have only " << this->getCurrentStamina()
//                  << "stamina points (need " << staminaCost << ")."
//                  << std::endl;
//        //std::this_thread::sleep_for(std::chrono::milliseconds(2000));
//        retValue = false;
//    }

//    return retValue;
//}


//==================================================================================================
//         NAME:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    Return the cost of warrior's special attack in points of his main resource.
//                  Or I can add cost in all available resources (0 in mana, 30 in stamina and 10 in
//                  concentration, for example).
//==================================================================================================
//int Warrior::getSuperAttackCost() const
//{
//    return mb_heavyBlowStaminaCost;
//}



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
    this->mb_curHealth = 0;
}
