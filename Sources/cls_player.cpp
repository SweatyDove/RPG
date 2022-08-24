#include "header.h"
#include "cls_player.h"
#include "cls_monster.h"
#include "cls_potion.h"

class Monster;


Player::Player(const my::String& name, Race race, Spec spec) :
    mb_name {name},
    mb_race {race},
    mb_spec {spec}
    {
        // Nothing to do;
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

// #########################
const my::String& Player::getName() const
{
    return mb_name;
}

void Player::addHealth(int health)
{
    mb_health += health;
    return;

}

void Player::addStrength(int strength)
{
    mb_damage += strength;
    return;
}

void Player::attack(Monster& monster) const
{
    monster.reduceHealth(mb_damage);
    std::cout << "You've dealed " << mb_damage << " damage to the " << monster.getName()
              << ". (It had " << monster.getCurrentHealth() << " hp left)." << std::endl;
    return;
}

int Player::getDamage() const
{
    return mb_damage;
}

int Player::addGold(int gold)
{
    mb_gold += gold;
    return mb_gold;
}

// #### Function returns true if current Player is dead
// #############
bool Player::isDead() const
{
    return (mb_health <= 0);
}

// #### Function reduce health of the current Player by specified magnitude
// #############
void Player::reduceHealth(int health)
{
    mb_health -= health;
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
    return mb_health;
}




void Player::getLootFrom(Monster& monster)
{
    char            choice {};
    constexpr char  potionChance {100};


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



// ########################
void Player::fightWith(Monster& monster)
{
    char choice {};
    bool isFled {false};

    while (!(this->isDead()) && !(monster.isDead()) && !isFled) {
        std::cout << "(F)ight or (R)un? ";
        std::cin >> choice;
        switch (choice) {
        case 'F': case 'f':
            this->attack(monster);
            if (!monster.isDead()) {
                monster.attack(*this);
            }
            else {
                std::cout << "You killed monster!\n";
            }
            break;
        case 'R': case 'r':
            if (getRandomNumber(0, 1)) {
                isFled = true;
                std::cout << "You have successfully fled from monster!\n";
            }
            else {
                std::cout << "You couldn't flee...\n";
                monster.attack(*this);
            }
            break;
        default:
            break;
        } // end-of-switch
    } // end-of-while
} // end-of-func
