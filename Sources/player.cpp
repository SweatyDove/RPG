#include "main.h"
#include "player.h"
#include "monster.h"
#include "potion.h"

//class Monster;


//Player::~Player()
//{
//    //std::cerr << "\n[DEBUG]: Player's destructor has called...";
//    // Nothing to do
//}


//==================================================================================================
//         NAME:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
Player::Player(Player::Race race, std::string name) :
    Creature {Creature::Type::PLAYER, 1},
    mb_race {race},
    mb_name {name}
{

}



//==================================================================================================
//         NAME:    --------
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
//         NAME:    --------
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
//         NAME:    --------
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
//         NAME:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
void Player::newDay()
{
    mb_timeLived += 1;
    return;
}




//==================================================================================================
//         NAME:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
const std::string& Player::getName() const
{
    return mb_name;
}



//==================================================================================================
//         NAME:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
void Player::setName(std::string& name)
{
    mb_name = name;
}




//==================================================================================================
//         NAME:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
void Player::changeHealth(int health)
{
    Creature::changeHealth(health);
}



//==================================================================================================
//         NAME:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
void Player::changeStamina(int stamina)
{
    Creature::changeStamina(stamina);
}



//==================================================================================================
//         NAME:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
void Player::changeStrength(int strength)
{
    Creature::changeStrength(strength);
}

//int Player::getDamage() const
//{
//    return mb_damage;
//}

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



// #### Handling player's leveling up.
// #########
void Player::levelUp()
{
    bool inLoop {false};
    char choice {'\0'};

    mb_level++;

    // Set the new max health and restore cur health
    mb_curHealth = mb_maxHealth = player_default::HEALTH + mb_level * 20;

    std::cout << "Congratulation! You've reached " << mb_level << " level.\n";
    std::cout << "What do you want to upgrade?\n"
              << "[1] - Strength (+" << mb_level << ")\n"
              << "[2] - Intellect (+" << mb_level << ")\n"
              << "[3] - Agility (+" << mb_level << ")\n"
              << "\nYour choice: "
              << std::flush;
    while (inLoop) {
        std::cin >> choice;
        switch (choice) {
        case '1':
            mb_maxStrength += mb_level;
            mb_curStamina = mb_maxStamina = player_default::STAMINA + mb_level * 10;
            break;
        case '2':
//            mb_maxIntellect += mb_level;
//            mb_curMana = mb_maxMana = player_default::MANA + mb_level * 10;
//            break;
        case '3':
//            mb_agility++;
//            mb_dodgeChance += 1;
//            mb_critChance += 1;
//            break;
        default:
            inLoop = true;
            std::cout << "Incorrect choice, please - try again:"
                      << "\nYour choice: " << std::endl;
            break;
        }
    }

    // Set new damage after the leveling up and changes in the player's parameters
    this->setDamage();

}

//==============================================================================
// WHAT: Member function
//  WHY: Increase the player's experience (and level up) depending on
//       the monster, that was killed by player.
//==============================================================================
void Player::increaseExp(Monster& monster)
{
    int exp {monster.getLevel() * 100};

    if (mb_curExp + exp >= mb_nextLevelExp) {
        this->levelUp();
        mb_curExp = mb_curExp + exp - mb_nextLevelExp;
    }
    else {
        mb_curExp += exp;
    }

    return;
}




//==================================================================================================
//         NAME:    --------
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
                this->drink(*potion);

                delete potion;
                break;
            }
            }
        }
        else {} // Nothing to do

    }


}


//==============================================================================
// WHAT: Member function
//  WHY: It handles the case when player is going to drink smth.
//==============================================================================
void Player::drink(Potion& potion)
{
    switch(potion.mb_type) {
    case Potion::Type::EXHAUSTED:
        std::cout << "You had drunk potion, but nothing happened.\n";
        break;
    case Potion::Type::HEALTH:
        this->addHealth(potion.getEffect());
        std::cout << "You had drunk a " << potion.getName() << ", that restored "
                  << potion.getEffect() << " hp.\n";
        break;
    case Potion::Type::STAMINA:
        this->addStamina(potion.getEffect());
        std::cout << "You had drunk a " << potion.getName() << ", that restored "
                  << potion.getEffect() << " stamina.\n";
        break;
    case Potion::Type::STRENGTH:
        this->addStrength(potion.getEffect());
        std::cout << "You had drunk a " << potion.getName() << ", that increased your damage by "
                  << potion.getEffect() << " points.\n";
        break;
    case Potion::Type::POISON:
        this->addHealth(-potion.getEffect());
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
//         NAME:    fightWith
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
            if (getRandomNumber(1, 100) <= mb_escapeChance) {
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
//         NAME:    --------
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
//         NAME:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
void Player::commitSuicide()
{
    std::cout << "\nPlayer commited suicide!" << std::endl;
    this->mb_curHealth = 0;
}


//==================================================================================================
//         NAME:    --------
//  DESCRIPTION:    Get potion
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
void Player::getPotion(int potionChance)
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
        //this->drink(potion);
        break;
    case 'n': case 'N':
        std::cout << "You've decided not to drink it.\n";
        break;
    default:
        break;

    }

}




//==================================================================================================
//         NAME:    --------
//  DESCRIPTION:    Player getting a rest and restores some part of his characteristics during this
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
void Player::getRest()
{
    this->addHealth(mb_maxHealth / 10);                     // Restore 10% hp
    this->addStamina(mb_maxStamina / 2);                    // Restore 50% stamina points

    std::cout << "Player had a rest and now he has (" << mb_curHealth << ") hp and ("
              << mb_curStamina << ") stamina points" << std::endl;
}










