#include "header.h"
#include "cls_player.h"
#include "cls_monster.h"
#include "cls_potion.h"

class Monster;


Player::~Player()
{
    //std::cerr << "\n[DEBUG]: Player's destructor has called...";
    // Nothing to do
}


void Player::setRace(Player::Race race)
{
    mb_race = race;
}


Player::Spec Player::getSpec() const
{
    return mb_spec;
}


int Player::getTimeLived() const
{
    return mb_timeLived;
}

void Player::newDay()
{
    mb_timeLived += 1;
    return;
}


const my::String& Player::getName() const
{
    return mb_name;
}

void Player::setName(my::String& name)
{
    mb_name = name;
}


void Player::addHealth(int health)
{
    if (mb_currentHealth + health >= mb_maxHealth) {
        mb_currentHealth = mb_maxHealth;
    }
    else {
        mb_currentHealth += health;
    }

    return;

}

void Player::addStamina(int stamina)
{
    if (mb_currentStamina + stamina >= mb_maxStamina) {
        mb_currentStamina = mb_maxStamina;
    }
    else {
        mb_currentStamina += stamina;
    }
    return;
}

void Player::addStrength(int strength)
{
    mb_strength += strength;
    return;
}

//int Player::getDamage() const
//{
//    return mb_damage;
//}

int Player::addGold(int gold)
{
    mb_gold += gold;
    return mb_gold;
}

// #### Function returns true if current Player is dead
// #############
bool Player::isDead() const
{
    return (mb_currentHealth <= 0);
}

// #### Function reduce health of the current Player by specified magnitude
// #############
void Player::reduceHealth(int health)
{
    if (mb_currentHealth - health <= 0) {
        mb_currentHealth = 0;
    }
    else {
        mb_currentHealth -= health;
    }
    return;
}

void Player::reduceStamina(int stamina)
{
    if (mb_currentStamina - stamina <= 0) {
        mb_currentStamina = 0;
    }
    else {
        mb_currentStamina -= stamina;
    }

    return;

}

// #### Function returns the level of the creature
// ###############
int Player::getLevel() const
{
    return mb_level;
}

// #### Function returns current health of the creature
// #############
int Player::getCurrentHealth() const
{
    return mb_currentHealth;
}

int Player::getCurrentStamina() const
{
    return mb_currentStamina;
}

//void Player::setHealth()
//{
//    mb_currentHealth = player_default::HEALTH + mb_level * 20;
//}

// #### Handling player's leveling up.
// #########
void Player::levelUp()
{
    bool inLoop {false};
    char choice {'\0'};

    // Set the new max health and restore current health
    mb_currentHealth = mb_maxHealth = player_default::HEALTH + mb_level * 20;

    std::cout << "Congratulation! You've reached " << mb_level << " level.\n";
    std::cout << "What do you want to upgrade?:\n"
              << " 1 - Strength (+1)\n"
              << " 2 - Intellect (+1)\n"
              << " 3 - Agility (+1)\n"
              << std::flush;
    while (inLoop) {
        std::cin >> choice;
        std::cout << "\033[F \b";
        switch (choice) {
        case '1':
            mb_strength++;
            mb_currentStamina = mb_maxStamina = player_default::STAMINA + mb_level * 5;
            break;
        case '2':
            mb_intellect++;
            mb_currentMana = mb_maxMana = player_default::MANA + mb_level * 5;
            break;
        case '3':
            mb_agility++;
            mb_dodgeChance += 1;
            mb_critChance += 1;
            break;
        default:
            inLoop = true;
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

    if (mb_currentExp + exp >= mb_nextLevelExp) {
        mb_level++;
        this->levelUp();
        mb_currentExp = mb_currentExp + exp - mb_nextLevelExp;
    }
    else {
        mb_currentExp += exp;
    }

    return;
}



//==============================================================================
// WHAT: Member function
//  WHY: It handles the player's looting monster's corpse.
//==============================================================================
void Player::getLootFrom(Monster& monster)
{
    char            choice {};
    constexpr char  potionChance {30};


    // #### Generate gold
    int gold {getRandomNumber(0, monster.getLevel() * 10)};
    if (gold > 0) {

        std::cout << "You found " << gold << " gold and now has "
               << this->addGold(gold) << " golden coins."
               << std::endl;
    }
    else {
        std::cout << "You didn't find any gold..." << std::endl;
    }

    // #### Generate potion
    if (getRandomNumber(0, 100) <= potionChance) {

        Potion potion {};
        potion.createRandomPotion(monster.getLevel());

        /*
         * Check players knowleges in alchemy - if less then [alchemy-level] - then player couldn't define
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
    else {} // Nothing to do

    // #### Generate other loot
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
    case Potion::Type::MAX_TYPE:
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
Player::FightOption Player::chooseFightOption(Monster& monster)
{
    int playerStamina {this->getCurrentStamina()};


    // ######## Intro message title
    std::cout << "Monster has (" << monster.getCurrentHealth() << ") hp and deals (" << monster.getDamage()
              << ") points of damage per attack."
              << "\nYours current health: " << this->getCurrentHealth() << std::endl;

    std::cout << "What are you going to do? Press an appropriate button:\n";

    // ######## 1-st option
    std::cout << "\n[1] - Attack monster: deal (" << this->getAttackDamage() << ") damage to the monster";

    // ######## 2-nd option
    /* Maybe it is better to replace Stamina on structure (or array) of player resources. Or add function
     * to get main resources...
     */
    if (playerStamina >= this->getSuperAttackCost()) {
        std::cout << "\n[2] - Super atack monster: deal (" << this->getSuperAttackDamage() << ") damage to the monster (costs 30 stamina points)";
    }
    else {
        HANDLE hConsole {GetStdHandle(STD_OUTPUT_HANDLE)};
        SetConsoleTextAttribute(hConsole, CLR_PALE_PRIM);
        std::cout << "\n[2] - Super atack monster: not enough stamina points!";
        SetConsoleTextAttribute(hConsole, CLR_VERY_LIGHT_GREY);
    }

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

        if ((choice >= 0 && choice <= 2) || choice == 3) {
            choiceLoop = false;
        }
        else {
            std::cout << "Incorrect choice. Please, try again." << std::endl;
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
void Player::commitSuicide()
{
    std::cout << "\nPlayer commited suicide!" << std::endl;
    this->mb_currentHealth = 0;
}




