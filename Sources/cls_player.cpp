#include "header.h"
#include "cls_player.h"
#include "cls_monster.h"
#include "cls_potion.h"

class Monster;


Player::~Player()
{
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

// #### Increase the player's experience (and level up) depending on
// #### the monster, that was killed by player.
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




void Player::getLootFrom(Monster& monster)
{
    char            choice {};
    constexpr char  potionChance {30};


    // #### Generate gold
    int gold {getRandomNumber(0, monster.getLevel() * 10)};
    if (gold > 0) {
        std::cout << "You found " << gold << " gold and now has "
                  << this->addGold(gold) << " golden coins." << std::endl;
    }
    else {
        std::cout << "You didn't find any gold...\n";
    }

    // #### Generate potion
    if (getRandomNumber(0, 100) <= potionChance) {

        Potion potion {};
        potion.createRandomPotion(monster.getLevel());

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

    // #### Generate other loot
}



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



// #### Realize player's fight with specified @monster
// ####
void Player::fightWith(Monster& monster)
{
    char ch {};
    bool isFled {false};
    int keystroke {0};
    int state {0};
    int lastState {0};
    bool firstIn {true};

    enum class FightState {
        ATTACK,
        SUPER_ATTACK,
        RUN,

        MAX_STATE
    };



    linuxTerminalMode(!CANONICAL);

    while (!(this->isDead()) && !(monster.isDead()) && !isFled) {
        // ## Have to display menu only if (in the first time) or (last state != current state)
        if (state != lastState || firstIn) {
            displayFightMenu(state, monster);
            firstIn = false;
        }
        else {} // Nothing to do

        lastState = state;
        keystroke = linux_kbhit();
        if (keystroke) {
            ch = std::cin.get();

            if (MOVE_UP(ch)) {
                state = (state == 0) ? static_cast<int>(FightState::MAX_STATE) - 1 : state - 1;
            }
            else if (MOVE_DOWN(ch)) {
                state = (state == static_cast<int>(FightState::MAX_STATE) - 1) ? 0 : state + 1;
            }
            else if (ACCEPT(ch)) {
                switch (state) {

                case static_cast<int>(FightState::ATTACK):
                    this->attack(monster);
                    if (!monster.isDead()) {
                        monster.attack(*this);
                    }
                    else {} // Nothing to do;
                break;

                case static_cast<int>(FightState::SUPER_ATTACK):
                    // ## If can't make super attack -> just break without doing smth
                    if (!this->superAttack(monster)) {
                        break;
                    }
                    else if (!monster.isDead()) {
                        monster.attack(*this);
                    }
                    else {} // Nothing to do;
                break;

                case static_cast<int>(FightState::RUN):
                    if (0 == getRandomNumber(0, 2)) {
                        isFled = true;
                    }
                    else {
                        clearWorkScreen(WORK_SCREEN_LINES, WORK_SCREEN_COLUMNS);
                        std::cout << "You couldn't flee...\n";
                        monster.attack(*this);
                        std::this_thread::sleep_for(std::chrono::milliseconds(1500));
                    }
                    break;

                case static_cast<int>(FightState::MAX_STATE):
                break;
                //default: break;
                } // End of switch()
            }
            else {} // Nothing to do
        }
        else {} // Nothing to do
    }
    // End of while()


    if (this->isDead()) {

    }
    else if (monster.isDead()) {
        std::cout << "You killed monster!\n";
        this->increaseExp(monster);
    }
    else if (isFled) {
        std::cout << "You have successfully fled from monster!\n";
    }
    else {} // Nothing to do

}





void Player::displayFightMenu(int state, Monster& monster)
{
    int menuSize {11};
    clearWorkScreen(menuSize, WORK_SCREEN_COLUMNS);

    std::cout << "       What are you going to do?\n\n";

    switch(state) {
    case 0:
        std::cout << "\n########  Attack monster  #########"
                  << "\n          Super atack monster      "
                  << "\n          Run                      "
                  << "\n                                   "
                  << "\n                                   "
                  << "\n                                   "
                  << "\n[NOTE]: You'll deal " << this->getAttackDamage() << "points of damage."
                  << "\n                                                                      "
                  << std::endl;
        break;
    case 1:
        std::cout << "\n          Attack monster           "
                  << "\n########  Super atack monster  ####"
                  << "\n          Run                      "
                  << "\n                                   "
                  << "\n                                   "
                  << "\n                                   "
                  << "\n[NOTE]: You'll deal " << this->getSuperAttackDamage() << "points of damage."
                  << "\n        Attack requires 30 stamina points.                                 "
                  << std::endl;
        break;
    case 2:
        std::cout << "\n          Attack monster           "
                  << "\n          Super atack monster      "
                  << "\n########  Run  ####################"
                  << "\n                                   "
                  << "\n                                   "
                  << "\n                                   "
                  << "\n[NOTE]: You have 33% chance to escape from monster. If you could't, it     "
                  << "\n        would deal " << monster.getDamage() << " points of damage          "
                  << std::endl;
        break;
    default:
        break;
    }

    while (menuSize-- > 0) {
        std::cout << MOVE_CURSOR_ONE_LINE_UP;
    }


    return;
}
