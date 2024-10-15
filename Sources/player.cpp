#include "player.h"


//class Monster;





//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
Player::Player(Race race, Spec spec, StringClass name) :
    Creature {Creature::Type::PLAYER, 1},
    mb_race {race},
    mb_spec {spec},
    mb_name {name}
{
    // ######## Add new attributes (RATINGS ans SKILLS)
    mb_attribute.insert(std::end(mb_attribute), std::begin(mb_ratings), std::end(mb_ratings));
    mb_attribute.insert(std::end(mb_attribute), std::begin(mb_skills), std::end(mb_skills));

}



//==================================================================================================
//         TYPE:    Virtual Destructor
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
Player::~Player()
{
    //std::cerr << "\n[DEBUG]: Player's destructor has called...";
    // Nothing to do
}

//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
void Player::setRace(Player::Race race)
{
    mb_race = race;
}



//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
Player::Spec Player::getSpec() const
{
    return mb_spec;
}



//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
int Player::getTimeLived() const
{
    return mb_timeLived;
}



//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
bool Player::metNewDay()
{
    std::cout << "A new day has come! Do you want to wake up? [y/n]" << std::endl;

    // ######## Choice loop
    char choice {};
    bool choiceLoop {true};
    do {
        std::cout << "Your choice: ";
        std::cin >> choice;

        switch(choice) {
        case 'y': case 'Y':
            choiceLoop = false;
            break;
        case 'n': case 'N':
            choiceLoop = false;
            break;
        default:
            std::cout << "Incorrect choice. Please, try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    while (choiceLoop);

    if (choice == 'y' || choice == 'Y') {
        this->getRest();
        mb_timeLived += 1;
        return true;
    }
    else {
        std::cout << "\nPlayer died in his sleep..." << std::endl;
        this->setCurAttr(Attr::Name::HEALTH, 0);
        return false;
    }
}




//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
const StringClass& Player::getName() const
{
    return mb_name;
}



//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
void Player::setName(StringClass& name)
{
    mb_name = name;
}




//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
//void Player::changeHealth(int health)
//{
//    Creature::changeHealth(health);
//}



//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
//void Player::changeStamina(int stamina)
//{
//    Creature::changeStamina(stamina);
//}



//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
//void Player::changeStrength(int strength)
//{
//    Creature::changeStrength(strength);
//}

//int Player::getDamage() const
//{
//    return mb_damage;
//}



//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
void Player::addGold(int gold)
{
    mb_gold += gold;

    if (gold > 0) {
        std::cout << "You found " << gold << " gold and now has " << mb_gold << " golden coins." << std::endl;
    }
    else {
        std::cout << "You didn't find any gold..." << std::endl;
    }
}



//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
void Player::levelUp()
{

    mb_level++;

    // ######## Set the new max health and restore current health
    this->setMaxAttr(Attr::Name::HEALTH, this->getBaseAttr(Attr::Name::HEALTH) + (mb_level - 1) * 20);
    this->setCurAttr(Attr::Name::HEALTH, this->getMaxAttr(Attr::Name::HEALTH));


    std::cout << "Congratulation! You've reached " << mb_level << " level.\n";
    std::cout << "What do you want to upgrade?\n"
              << "[1] - Strength (+" << mb_level << ")\n"
              << "[2] - Intellect (+" << mb_level << ")\n"
              << "[3] - Agility (+" << mb_level << ")\n"
              << "\nYour choice: "
              << std::flush;

    bool inLoop {true};
    char choice {'\0'};
    while (inLoop) {
        std::cin >> choice;
        switch (choice) {
        case '1':
            this->modMaxAttr(Attr::Name::STRENGTH, +mb_level);
            this->setCurAttr(Attr::Name::STRENGTH, this->getMaxAttr(Attr::Name::STRENGTH));

            this->setMaxAttr(Attr::Name::STAMINA, this->getBaseAttr(Attr::Name::STAMINA) + (mb_level - 1) * 10);
            this->setCurAttr(Attr::Name::STAMINA, this->getMaxAttr(Attr::Name::STAMINA));
            inLoop = false;
            break;
        case '2':
//            mb_maxIntellect += mb_level;
//            mb_curMana = mb_maxMana = player_default::MANA + mb_level * 10;
            inLoop = false;
            break;
        case '3':
//            mb_agility++;
//            mb_dodgeChance += 1;
//            mb_critChance += 1;
            inLoop = false;
            break;
        default:
            std::cout << "Incorrect choice, please - try again:"
                      << "\nYour choice: " << std::endl;
            break;
        } // switch
    } // while

    // Set new damage after the leveling up and changes in the player's parameters
//    this->setDamage();

}

//==============================================================================
// WHAT: Member function
//  WHY: Increase the player's experience (and level up) depending on
//       the monster, that was killed by player.
//==============================================================================
//==================================================================================================
//         TYPE:    --------
//   PARAMETERS:    --------
//  DESCRIPTION:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
void Player::increaseExp(Monster& monster)
{
    int receivedExp {monster.getLevel() * 100};
    int totalExp {mb_curExp + receivedExp};

    while (totalExp >= mb_nextLevelExp) {
        this->levelUp();
        totalExp -= mb_nextLevelExp;
    }
    mb_curExp = totalExp;

    return;
}




//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    Function handles the player's looting monster's corpse.
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    At this moment we just use items, that monster "generates" after its death.
//                  In the future, I'll plan to transfer loot from monster's corpse to player's bag.
//
//                  Another issue is that I need to downcast object under std::unique_ptr<Item> to
//                  <Gold*> (or <Potion*>). I'm not sure, that my current solution correct, but
//                  I going to left it as is 'cause don't want to making a mess.
//==================================================================================================
void Player::getLootFrom(Monster& monster)
{
    for (auto& itemPtr: monster.mb_loot) {

        if (itemPtr) {
            Item::Type type {itemPtr->getType()};

            switch (type) {
            case Item::Type::GOLD: {
                Gold* gold = static_cast<Gold*>(itemPtr.release());         // HERE dangerous place!
                this->addGold(gold->getCount());

                delete gold;
                break;
            }
            case Item::Type::POTION: {
                Potion* potion = static_cast<Potion*>(itemPtr.release());
                this->getPotion(*potion);
                delete potion;
                break;
            }
            case Item::Type::TRASH:
            case Item::Type::TOTAL:
                break;
            }
        }
        else {} // Nothing to do

    }


}


//==============================================================================
// WHAT: Member function
//  WHY: It handles the case when player is going to drink smth.
//==============================================================================
void Player::drink(const Potion& potion)
{
    switch(potion.mb_type) {
    case Potion::Type::EXHAUSTED:
        std::cout << "You had drunk potion, but nothing happened.\n";
        break;
    case Potion::Type::HEALTH:
        this->modCurAttr(Attr::Name::HEALTH, potion.getEffect());
        std::cout << "You had drunk a " << potion.getName() << ", that restored "
                  << potion.getEffect() << " hp.\n";
        break;
    case Potion::Type::STAMINA:
        this->modCurAttr(Attr::Name::STAMINA, potion.getEffect());
        std::cout << "You had drunk a " << potion.getName() << ", that restored "
                  << potion.getEffect() << " stamina.\n";
        break;
    case Potion::Type::STRENGTH:
        this->modMaxAttr(Attr::Name::STRENGTH, +potion.getEffect());
        this->setCurAttr(Attr::Name::STRENGTH, this->getMaxAttr(Attr::Name::STRENGTH));
        std::cout << "You had drunk a " << potion.getName() << ", that increased your damage by "
                  << potion.getEffect() << " points.\n";
        break;
    case Potion::Type::POISON:
        this->modCurAttr(Attr::Name::HEALTH, -potion.getEffect());
        std::cout << "You had drunk a " << potion.getName() << ". You got poisoned and lost "
                  << potion.getEffect() << " hp.\n";
        break;
    case Potion::Type::TOTAL:
        break;
    //default:
        //break;
    }
}


//==================================================================================================
//         TYPE:    fightWith
//  DESCRIPTION:    Member function, that realize player's fight with specified @monster
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
void Player::fightWith(Monster& monster)
{
    bool isFled {false};
    int turn {1};


    // ########
    while (!(this->isDead()) && !(monster.isDead()) && !isFled) {

        SetConsoleTextAttribute(hConsole, CLR_DARK_GOLDENROD);
        std::cout << "\n\n[Turn " << turn++ << "]:" << std::endl;
        SetConsoleTextAttribute(hConsole, CLR_VERY_LIGHT_GREY);

        FightOption fightOption {chooseFightOption(monster)};

        switch (fightOption) {
        case FightOption::ATTACK:
            this->attack(monster);
            if (!monster.isDead()) {
                monster.attack(*this);      // Monster attacks in return
            }
            else {} // Nothing to do;
            break;

        case FightOption::SUPER_ATTACK:
            // If can't make super attack -> just break without doing smth
            if (!this->superAttack(monster)) {
                break;
            }
            else if (!monster.isDead()) {
                monster.attack(*this);
            }
            else {} // Nothing to do;
        break;
        case FightOption::FLEE:
            if (getRandomNumber(1, 100) <= this->getCurAttr(Attr::Name::ESCAPE_CHANCE)) {
                isFled = true;
            }
            else {
                std::cout << "You couldn't flee...\n";
                monster.attack(*this);
                std::this_thread::sleep_for(std::chrono::milliseconds(1500));
            }
            break;
        case FightOption::COMMIT_SUICIDE:
            this->commitSuicide();
            break;
        case FightOption::TOTAL:
            break;
        }
    }

    if (this->isDead()) {
        ;// Nothing to do
    }
    else if (monster.isDead()) {
        std::cout << "You killed monster!\n" << std::endl;
        this->increaseExp(monster);
    }
    else if (isFled) {
         std::cout << "You have successfully fled from monster!\n" << std::endl;
    }
    else {} // Nothing to do

}




//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    Function displays player's option while fighting with monster.
//   PARAMETERS:    --------
// RETURN VALUE:    Returns player's choice.
//     COMMENTS:    --------
//==================================================================================================
//Player::FightOption Player::chooseFightOption(Monster& monster)
//{
//    int playerStamina {this->getCurrentStamina()};


//    // ######## Intro message title
//    std::cout << "Monster has (" << monster.getCurrentHealth() << ") hp and deals (" << monster.getDamage()
//              << ") points of damage per attack."
//              << "\nYours current health: " << this->getCurrentHealth() << std::endl;

//    std::cout << "What are you going to do? Press an appropriate button:\n";

//    // ######## 1-st option
//    std::cout << "\n[1] - Attack monster: deal (" << this->getAttackDamage() << ") damage to the monster";

//    // ######## 2-nd option
//    /* Maybe it is better to replace Stamina on structure (or array) of player resources. Or add function
//     * to get main resources...
//     */
//    if (playerStamina >= this->getSuperAttackCost()) {
//        std::cout << "\n[2] - Super atack monster: deal (" << this->getSuperAttackDamage() << ") damage to the monster (costs 30 stamina points)";
//    }
//    else {
//        HANDLE hConsole {GetStdHandle(STD_OUTPUT_HANDLE)};
//        SetConsoleTextAttribute(hConsole, CLR_PALE_PRIM);
//        std::cout << "\n[2] - Super atack monster: not enough stamina points!";
//        SetConsoleTextAttribute(hConsole, CLR_VERY_LIGHT_GREY);
//    }

//    // ######## 3-rd option
//    std::cout << "\n[3] - Commit suicide...";

//    // ######## 4-th option
//    std::cout << "\n[0] - Run away: You have (" << mb_escapeChance << ") chance to escape from monster."
//              << " If you could't, monster would deal (" << monster.getDamage() << ") damage."<< std::endl;


//    // ######## Choice loop
//    int choice {};
//    bool choiceLoop {true};
//    do {
//        std::cout << "Your choice: ";
//        std::cin >> choice;

//        if ((choice >= 0 && choice <= 2) || choice == 3) {
//            choiceLoop = false;
//        }
//        else {
//            std::cout << "Incorrect choice. Please, try again." << std::endl;
//        }

//    }
//    while (choiceLoop);
//    std::cout << '\n';

//    // ######## Returning player's choice
//    return static_cast<Player::FightOption>(choice);
//}



//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
void Player::commitSuicide()
{
    std::cout << "\nPlayer commited suicide!" << std::endl;
    this->setCurAttr(Attr::Name::HEALTH, 0);
}


//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    Get potion
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
void Player::getPotion(const Potion& potion)
{
    char            choice {};
    /*
     *  Check players knowleges in alchemy - if less then [alchemy-level] - then player couldn't define
     * potion before he drinks it.
     */
    std::cout << "You found a mythical potion. Do you want to drink it? [y/n]: ";
    std::cin >> choice;
    switch(choice) {
    case 'y': case 'Y':
        this->drink(potion);
        break;
    case 'n': case 'N':
        std::cout << "You've decided not to drink it.\n";
        break;
    default:
        break;
    }

}




//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    Player getting a rest and restores some part of his characteristics during this
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
void Player::getRest()
{
    this->modCurAttr(Attr::Name::HEALTH, this->getMaxAttr(Attr::Name::HEALTH) / 5);
    this->modCurAttr(Attr::Name::STAMINA, this->getMaxAttr(Attr::Name::STAMINA) / 2);

    std::cout << "Player had a rest and now he has (" <<  this->getCurAttr(Attr::Name::HEALTH)
              << ") hp and ("<<  this->getCurAttr(Attr::Name::STAMINA) << ") stamina points" << std::endl;
}




//==================================================================================================
//         TYPE:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//  DESCRIPTION:    --------
//     COMMENTS:    --------
//==================================================================================================
int Player::getCurExp() const
{
    return mb_curExp;
}



//==================================================================================================
//         TYPE:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//  DESCRIPTION:    --------
//     COMMENTS:    --------
//==================================================================================================
int Player::getNextLvlExp() const
{
    return mb_nextLevelExp;
}



//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
void Player::printAttr() const
{
    std::cout << this->getTypeName() << "'s attributes:" << std::endl;
    std::cout << "           LEVEL:    " << mb_level << std::endl;
    std::cout << "             EXP:    " << mb_curExp << '/' << mb_nextLevelExp << std::endl;
    Creature::printAttr();
}



