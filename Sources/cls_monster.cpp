
#include "header.h"
#include "cls_monster.h"

//==============================================================================
// WHAT: Constructor.
//  WHY: Create a random monster.
//==============================================================================
Monster::Monster() :
    mb_type {getRandomMonsterType()},
    mb_level {getRandomMonsterLevel()}
{
    mb_damage = this->setDamage(mb_type, mb_level);
    mb_currentHealth = this->setHealth(mb_type, mb_level);
}


//==============================================================================
// WHAT: Static member function
//  WHY: Returns random monster's [level].
//==============================================================================
int Monster::getRandomMonsterLevel()
{
    return getRandomNumber(1, 10);
}



//==============================================================================
// WHAT: Static member function.
//  WHY: Generate random monster [type] according to the monster's [chance]
//       to appeare.
//==============================================================================
Monster::Type Monster::getRandomMonsterType()
{
    int roll {};
    Type type {};

    roll = getRandomNumber(1, 100);
    if (roll <= 20) {
        type = Type::GHOST;
    }
    else if (roll <= 50 ) {
        type = Type::ZOMBIE;
    }
    else {
        type = Type::SKELETON;
    }

    return type;
}





//==============================================================================
// WHAT: Member function.
//  WHY: Function returns true if the current Monster is dead.
//==============================================================================
bool Monster::isDead() const
{
    return (mb_currentHealth <= 0);
}


//==============================================================================
// WHAT: Member function.
//  WHY: Function reduce health of the current Monster by specified magnitude
//==============================================================================
void Monster::reduceHealth(int health)
{
    mb_currentHealth = ((mb_currentHealth - health) < 0) ? (0) : (mb_currentHealth - health);
}


//==============================================================================
// WHAT: Getter.
//  WHY: Function returns the level of the creature.
//==============================================================================
int Monster::getLevel() const
{
    return mb_level;
}


//==============================================================================
// WHAT: Getter.
//  WHY: Returns current health of the [*this] monster.
//==============================================================================
int Monster::getCurrentHealth() const
{
    return mb_currentHealth;
}


//==============================================================================
// WHAT: Getter.
//  WHY: Returns the amount of damage of the [*this] monster.
//==============================================================================
int Monster::getDamage() const
{
    return mb_damage;
}





//==============================================================================
// WHAT: Public member function.
//  WHY: It sets the [mb_damage] of the monster (depending on the monster's [type]
//       and [level]).
//==============================================================================
int Monster::setDamage(Type type, int level) const
{
    int damage {};

    switch (type) {
    case Type::SKELETON:
        damage = base[static_cast<std::size_t>(type)].damage + level;
        break;
    case Type::ZOMBIE:
        damage = base[static_cast<std::size_t>(type)].damage + level * 2;
        break;
    case Type::GHOST:
        damage = base[static_cast<std::size_t>(type)].damage + level * 3;
    case Type::MAX_TYPE:
        assert("Invalid monster");
        break;
    }

    return damage;
}



//==============================================================================
// WHAT: Public member function.
//  WHY: It sets the [mb_health] of the monster (depending on the monster's
//       [type] and [level])
//==============================================================================
int Monster::setHealth(Type type, int level) const
{
    int health {};

    switch (type) {
    case Type::SKELETON:
        health = base[static_cast<std::size_t>(type)].health + level * 2;
        break;
    case Type::ZOMBIE:
        health = base[static_cast<std::size_t>(type)].health + level * 10 ;
        break;
    case Type::GHOST:
        health = base[static_cast<std::size_t>(type)].health + level * 5;
    case Type::MAX_TYPE:
        assert("Invalid monster");
        break;
    //default:
        //break;
    }

    return health;
}

// #### Func returns "name" of the current monster
// #########
my::String Monster::getName() const
{
    switch(mb_type) {
    case Type::SKELETON:
        return "skeleton";
    case Type::ZOMBIE:
        return "zombie";
    case Type::GHOST:
        return "ghost";
    case Type::MAX_TYPE:
        return "";
    //default:
        //break;
    }

    return "";
}


//==============================================================================
// WHAT: Virtual override member function.
//  WHY: It is handling the case when [*this] monster attacks the [player].
//==============================================================================
void Monster::attack(Player& player) const
{
    player.reduceHealth(mb_damage);

    SetConsoleTextAttribute(hConsole, CLR_FLAMINGO);
    std::cout << "The " << this->getName() << " attacked player and dealt (" << this->mb_damage
              << ") points of damage. At now, player has (" << player.getCurrentHealth() << ") hp. "
              << std::endl;
    SetConsoleTextAttribute(hConsole, CLR_VERY_LIGHT_GREY);

    return;
}












//int getRandomLevel()
//{
//    // ## In the future, minLevel and maxLevel will depend on the monster's type
//    int minLevel {0};
//    int maxLevel {10};

//    return getRandomNumber(minLevel, maxLevel);
//}



//Monster::Type getRandomType()
//{
//    return static_cast<Monster::Type>(getRandomNumber(0, static_cast<unsigned int>(Monster::Type::MAX_TYPE) - 1));
//}
