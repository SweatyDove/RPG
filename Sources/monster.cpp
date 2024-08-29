#include "monster.h"

//==================================================================================================
//         TYPE:    Constructor
//  DESCRIPTION:    Create random monster
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
Monster::Monster():
    Creature {Creature::Type::MONSTER, getRandomNumber(1, 10)},
    mb_type {getRandomMonsterType()}
{
    //mb_damage = this->setDamage(mb_type, mb_level);
    mb_curHealth = this->setHealth(mb_type, mb_level);

    // ######## Set spell type depending on the monster's type
    switch(mb_type) {
    case Type::SKELETON:
        mb_baseAttack = Spell("STRIKE", Spell::School::PHYSICAL);
        break;
    case Type::ZOMBIE:
        mb_baseAttack = Spell("INFECTED BLOW", Spell::School::PHYSICAL_NATURE);
        break;
    case Type::GHOST:
        mb_baseAttack = Spell("SHADOW STRIKE", Spell::School::PHYSICAL_DARKNESS);
        break;
    case Type::TOTAL:
        assert("Incorrect monster type!");
        break;
    }
}





//==============================================================================
// WHAT: Static member function
//  WHY: Returns random monster's [level].
//==============================================================================
//int Monster::getRandomMonsterLevel()
//{
//    return getRandomNumber(1, 10);
//}



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
//bool Monster::isDead() const
//{
//    return (mb_currentHealth <= 0);
//}


//==============================================================================
// WHAT: Member function.
//  WHY:
//==============================================================================
//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    Function reduce health of the current Monster by specified magnitude. If monster
//                  has 0 hp - it generate loot on its dead body.
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
//void Monster::reduceHealth(int health)
//{
//    mb_currentHealth = ((mb_currentHealth - health) <= 0) ? (0) : (mb_currentHealth - health);
//    if (mb_currentHealth <= 0) {
//        this->generateLoot();
//    }
//    else {} // Nothing to do
//}


//==============================================================================
// WHAT: Getter.
//  WHY: Function returns the level of the creature.
//==============================================================================
//int Monster::getLevel() const
//{
//    return mb_level;
//}


//==============================================================================
// WHAT: Getter.
//  WHY: Returns current health of the [*this] monster.
//==============================================================================
//int Monster::getCurrentHealth() const
//{
//    return mb_currentHealth;
//}


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
// WHAT:
//  WHY:
//==============================================================================
//==================================================================================================
//         TYPE:    Public member function.
//  DESCRIPTION:    It sets the health of the monster (depending on the monster's
//                  @type and @level)
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
void Monster::setHealth(Type type, int level) const
{
    switch (type) {
    case Type::SKELETON:
        // #### CurrentHealth == BaseHealth + (level - 1) * 2
        this->setBaseAttr(Attr::Name::HEALTH, mb_baseHealth[static_cast<int>(type)]);
        this->setMaxAttr(Attr::Name::HEALTH, this->getBaseAttr(Attr::Name::HEALTH) + (level - 1) * 2);
        this->setCurAttr(Attr::Name::HEALTH, this->getMaxAttr(Attr::Name::HEALTH));
        break;
    case Type::ZOMBIE:
        // #### CurrentHealth == BaseHealth + (level - 1) * 10
        this->setBaseAttr(Attr::Name::HEALTH, mb_baseHealth[static_cast<int>(type)]);
        this->setMaxAttr(Attr::Name::HEALTH, this->getBaseAttr(Attr::Name::HEALTH) + (level - 1) * 2);
        this->setCurAttr(Attr::Name::HEALTH, this->getMaxAttr(Attr::Name::HEALTH));
        break;
    case Type::GHOST:
        this->setBaseAttr(Attr::Name::HEALTH, mb_baseHealth[static_cast<int>(type)]);
        this->setMaxAttr(Attr::Name::HEALTH, this->getBaseAttr(Attr::Name::HEALTH) + (level - 1) * 5);
        this->setCurAttr(Attr::Name::HEALTH, this->getMaxAttr(Attr::Name::HEALTH));
    case Type::TOTAL:
        assert(false && "Invalid monster's type");
        break;
    //default:
        //break;
    }

    return health;
}

//==================================================================================================
//         TYPE:    Virtual override member function.
//  DESCRIPTION:    Returns the name of the monster depending on it's type.
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
const std::string& Monster::getName() const
{
    return mb_name[static_cast<unsigned int>(mb_type)];
}



//==================================================================================================
//         TYPE:    Virtual override member function.
//  DESCRIPTION:    It handles the case when @this monster attacks the @player.
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
void Monster::attack(Player& player) const
{
    player.modCurAttr(Attr::Name::HEALTH, -mb_damage);

    SetConsoleTextAttribute(hConsole, CLR_FLAMINGO);
    std::cout << "The " << this->getName() << " attacked player and dealt (" << this->mb_damage
              << ") points of damage. At now, player has (" << player.getCurAttr(Attr::Name::HEALTH) << ") hp. "
              << std::endl;
    SetConsoleTextAttribute(hConsole, CLR_VERY_LIGHT_GREY);

    return;
}


//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    Function returns type of the monster
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
Monster::Type Monster::getType() const
{
    return mb_type;
}



//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    Function returns type of the monster
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
void Monster::commitSuicide()
{
    this->setCurAttr(Attr::Name::HEALTH, 0);
    std::cout << "Monster was scared to death of you and died of a heart attack..." << std::endl;
}



//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    Function generate loot, that remains after monster's death. Loot depends on the
//                  monster @level and player's @type.
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
void Monster::generateLoot()
{

    // ######## Iterate each type of <Item>
    for (int ii {0}; ii < static_cast<int>(Item::Type::TOTAL); ++ii) {

        // #### For convinience purpose added @type variable
        Item::Type type {static_cast<Item::Type>(ii)};
        switch (type) {
        case Item::Type::GOLD:
        {
            // Can't create Gold object in stack, 'cause it will be destroyed after exiting current
            // function - that's why should use dynamic allocated memory (in such case GOLD - is
            // resource and therewhy it is a good idea to use smart poiner for it)
            std::unique_ptr<Item> gold {new Gold(getRandomNumber(0, mb_level * 10))};
            mb_loot.push_back(std::move(gold));
        }
            break;
        case Item::Type::POTION:
            if (getRandomNumber(0, 100) <= Potion::mb_defaultPotionChance) {
                std::unique_ptr<Item> potion {new Potion(mb_level)};
                mb_loot.push_back(std::move(potion));
            }
            else {}
            break;
        case Item::Type::TOTAL:
            break;
        }
    }

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
