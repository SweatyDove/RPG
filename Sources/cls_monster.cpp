
#include "header.h"
#include "cls_monster.h"


// #### Create a random monster
// #######
Monster::Monster() :
    mb_type {getRandomMonsterType()},
    mb_level {getRandomMonsterLevel()}
{
    mb_damage = this->setDamage(mb_type, mb_level);
    mb_currentHealth = this->setHealth(mb_type, mb_level);
}



// #### (Static class function) Returns random monster's [level] depending on the it's [type] (not release yet)
// ############
int Monster::getRandomMonsterLevel()
{
    return getRandomNumber(1, 10);
}




// #### (Static class function) Generate random monster [type] according to the monster's [chance] to appeare
// ############
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






// #### Function returns true if current Monster is dead
// #############
bool Monster::isDead() const
{
    return (mb_currentHealth <= 0);
}

// #### Function reduce health of the current Monster by specified magnitude
// #############
void Monster::reduceHealth(int health)
{
    mb_currentHealth -= health;
    return;
}

// #### Function returns the level of the creature
// ###############
int Monster::getLevel() const
{
    return mb_level;
}

// #### Function returns current health of the creature
// #############
int Monster::getCurrentHealth() const
{
    return mb_currentHealth;
}

int Monster::getDamage() const
{
    return mb_damage;
}






// #### Func sets the [damage] of the monster (depending on the monster's [type] and [level])
// #########
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
    //default:
        //break;
    }

    return damage;
}

// #### Func sets the "health" of the monster (depending on the monster's "type" and "level")
// #########
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
// WHAT: Virtual override member function
//  WHY: It is handling the case when montster attacks the [player].
//==============================================================================
void Monster::attack(Player& player) const
{
    player.reduceHealth(mb_damage);
    // QQQ - съедает первую букву в "The " и из-за этого ошибка delete[] так как не с первого символа удаление
    player.mb_log << "The " << this->getName() << " attacked player and dealt "
                  << this->mb_damage << " points of damage. At now, player has "
                  << player.getCurrentHealth() << " hp. "
                  << my::endRecord;

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
