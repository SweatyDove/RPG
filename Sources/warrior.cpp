#include "warrior.h"




//==================================================================================================
//         TYPE:    Constructor
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
Warrior::Warrior(Player::Race race, Player::Spec spec, StringClass name):
    Player {race, spec, name}
{
    this->setAllAttr(Attr::NameId::STAMINA, 50, 50, 50);
    this->setAllAttr(Attr::NameId::STRENGTH, 10, 10, 10);
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
//         TYPE:    --------
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
//         TYPE:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
void Warrior::cast(Spell& spell, Creature& creature)
{
    int spellEffect {spell.getEffect(mb_level)};

    this->modCurAttr(Attr::NameId::STAMINA, -spell.getCost(mb_level));
    creature.modCurAttr(Attr::NameId::HEALTH, -spellEffect);

//    SetConsoleTextAttribute(hConsole, CLR_DARK_PASTEL_GREEN);
    std::cout << "You've dealed (" << spellEffect << ") damage to the " << creature.getName()
           << ". It had (" << creature.getCurAttr(Attr::NameId::HEALTH) << ") hp left." << std::endl;
//    SetConsoleTextAttribute(hConsole, CLR_VERY_LIGHT_GREY);

}


//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
Warrior::FightOption Warrior::chooseFightOption(Monster& monster)
{
    int playerStamina {this->getCurAttr(Attr::NameId::STAMINA)};


//    // ######## Intro message title
//    std::cout << "Monster has (" << monster.getCurrentHealth() << ") hp and deals (" << monster.getDamage()
//              << ") points of damage per attack."
//              << "\nYours current health: " << this->getCurrentHealth() << std::endl;

//    std::cout << "What are you going to do? Press an appropriate button:\n";

    // ######## 1-st option
    std::cout << "\n[1] - attack monster with " << mb_baseAttack.getName() << " and deal ("
              << mb_baseAttack.getEffect(mb_level) << ") damage to the monster";

    // ######## 2-nd option
    /* Maybe it is better to replace Stamina on structure (or array) of player resources. Or add function
     * to get main resources...
     */
    std::cout << "\n[2] - attack monster with " << mb_specialAttack.getName() << " and deal ("
              << mb_specialAttack.getEffect(mb_level) << ") to the monster. " << "This attack costs ("
              << mb_specialAttack.getCost(mb_level) <<") stamina points." << std::endl;

    // ######## 3-rd option
    std::cout << "[3] - Commit suicide...";

    // ######## 4-th option
    std::cout << "\n[0] - Run away: You have (" << this->getCurAttr(Attr::NameId::ESCAPE_CHANCE)
              << ") chance to escape from monster." << " If you could't, monster would deal ("
              << monster.getDamage() << ") damage."<< std::endl;


    // ######## Choice loop
    int choice {};
    bool choiceLoop {true};
    do {
        std::cout << "Your choice: ";
        std::cin >> choice;

        switch(choice) {
        case static_cast<int>(Warrior::FightOption::SUPER_ATTACK):
            if (playerStamina >= mb_specialAttack.getCost(mb_level)) {
                choiceLoop = false;
            }
            else {
//                HANDLE hConsole {GetStdHandle(STD_OUTPUT_HANDLE)};
//                SetConsoleTextAttribute(hConsole, CLR_PALE_PRIM);
                std::cout << "Not enough stamina points!" << std::endl;
//                SetConsoleTextAttribute(hConsole, CLR_VERY_LIGHT_GREY);
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
//         TYPE:    --------
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
//         TYPE:    --------
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
//         TYPE:    --------
//  DESCRIPTION:    Member function that realizes the warrior's base attack.
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
void Warrior::attack(Monster& monster)
{
    this->cast(mb_baseAttack, monster);
//    monster.reduceHealth(mb_autoAttackDamage);

//    SetConsoleTextAttribute(hConsole, CLR_DARK_PASTEL_GREEN);
//    std::cout << "You've dealed " << mb_autoAttackDamage << " damage to the " << monster.getName()
//           << ". It had (" << monster.getCurrentHealth() << ") hp left." << std::endl;
//    SetConsoleTextAttribute(hConsole, CLR_VERY_LIGHT_GREY);

//    return;
}








//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    Member function that realizes the warrior's special attack.
//   PARAMETERS:    --------
// RETURN VALUE:    true - if atack succeed; false - otherwise
//     COMMENTS:    At this moment I'm using only STAMINA as a resource for the super attack.
//                  But in the future need to add an array of costs (like in <Spell> class with
//                  spell's damage multipliers).
//==================================================================================================
bool Warrior::superAttack(Monster& monster)
{
    int curStamina {this->getCurAttr(Attr::NameId::STAMINA)};
    int costStamina {mb_specialAttack.getCost(mb_level)};

    if (curStamina > costStamina) {
        this->cast(mb_specialAttack, monster);
        return true;
    }
    else {
        std::cout << "\nNot enough stamina for the super attack. " << "You have only "
                  << curStamina << "stamina points (need " << costStamina << ")." << std::endl;
        return false;
    }

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
}


//==================================================================================================
//         TYPE:    --------
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
//         TYPE:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
void Warrior::commitSuicide()
{
    std::cout << "\nThe warrior threw his sword into the air, spread his arms and arched his chest to the sky...\n"
              << "And the sword pierced his chest, thereby taking his life..." << std::endl;
    this->setCurAttr(Attr::NameId::HEALTH, 0);
}
