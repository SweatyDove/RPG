#include "monster.h"

//==================================================================================================
//         TYPE:    Constructor
//  DESCRIPTION:    Create random monster
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
Monster::Monster():
    Creature {Creature::Type::MONSTER, my::getRandomNumber(1, 10)},
    mb_type {getRandomMonsterType()},
    mb_baseAttack{mb_attribute, mb_baseAttackMultiplier}
{
    //mb_damage = this->setDamage(mb_type, mb_level);
    this->setHealth(mb_type, mb_level);

    StringClass spellName {};
    Spell::School spellSchool {};
    int spellBaseEffect {};
    int spellBaseCost {};

    // ######## Set spell type depending on the monster's type. In a future just make concrete
    // ######## monsters derived from <Monster>7592 class
    switch(mb_type) {
    case Type::SKELETON:
        spellName = "STRIKE";
        spellSchool = Spell::School::PHYSICAL;
        spellBaseEffect = 10;
        spellBaseCost = 0;
        break;
    case Type::ZOMBIE:
        spellName = "INFECTED BLOW";
        spellSchool = Spell::School::PHYSICAL_NATURE;
        spellBaseEffect = 5;
        spellBaseCost = 0;
        //mb_baseAttack = Spell("INFECTED BLOW", Spell::School::PHYSICAL_NATURE, 5, 0, mb_attribute, mb_baseAttackMultiplier);
        break;
    case Type::GHOST:
        spellName = "SHADOW STRIKE";
        spellSchool = Spell::School::PHYSICAL_DARKNESS;
        spellBaseEffect = 15;
        spellBaseCost = 0;
        //mb_baseAttack = Spell("SHADOW STRIKE", Spell::School::PHYSICAL_DARKNESS, 15, 0, mb_attribute, mb_baseAttackMultiplier);
        break;
    case Type::TOTAL:
        assert("Incorrect monster type!");
        break;
    }

    mb_baseAttack.setName(spellName);
    mb_baseAttack.setSchool(spellSchool);
    mb_baseAttack.setBaseEffect(spellBaseEffect);
    mb_baseAttack.setBaseCost(spellBaseCost);

    this->generateLoot();


}

//==================================================================================================
//         TYPE:    Destructor
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
Monster::~Monster()
{
//    std::cout << "[DEBUG]: monster object has been destroyed." << std::endl;

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

    roll = my::getRandomNumber(1, 100);
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
int Monster::getLevel() const
{
    return mb_level;
}


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
    return mb_baseAttack.getEffect(mb_level);
}





//==============================================================================
// WHAT: Public member function.
//  WHY: It sets the [mb_damage] of the monster (depending on the monster's [type]
//       and [level]).
//==============================================================================
//int Monster::setDamage(Type type, int level) const
//{
//    int damage {};

//    switch (type) {
//    case Type::SKELETON:
//        damage = base[static_cast<std::size_t>(type)].damage + level;
//        break;
//    case Type::ZOMBIE:
//        damage = base[static_cast<std::size_t>(type)].damage + level * 2;
//        break;
//    case Type::GHOST:
//        damage = base[static_cast<std::size_t>(type)].damage + level * 3;
//    case Type::TOTAL:
//        assert("Invalid monster");
//        break;
//    }

//    return damage;
//}



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
void Monster::setHealth(Type type, int level)
{
    Attribute::NameId health {Attr::NameId::HEALTH};

    switch (type) {
    case Type::SKELETON:
        // #### MaxHealth == BaseHealth * level
        this->setBaseAttr(health, mb_baseHealth[static_cast<int>(type)]);
        this->setMaxAttr(health, this->getBaseAttr(health) * level);
        this->setCurAttr(health, this->getMaxAttr(health));
        break;
    case Type::ZOMBIE:
        // #### CurrentHealth == BaseHealth * level
        this->setBaseAttr(health, mb_baseHealth[static_cast<int>(type)]);
        this->setMaxAttr(health, this->getBaseAttr(health) * level);
        this->setCurAttr(health, this->getMaxAttr(health));
        break;
    case Type::GHOST:
        this->setBaseAttr(health, mb_baseHealth[static_cast<int>(type)]);
        this->setMaxAttr(health, this->getBaseAttr(health) * level);
        this->setCurAttr(health, this->getMaxAttr(health));
        break;
    case Type::TOTAL:
        assert(false && "Invalid monster's type");
        break;
    //default:
        //break;
    }

}

//==================================================================================================
//         TYPE:    Virtual override member function.
//  DESCRIPTION:    Returns the name of the monster depending on it's type.
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
const StringClass& Monster::getName() const
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
    player.modCurAttr(Attr::NameId::HEALTH, -mb_baseAttack.getEffect(mb_level));

//    SetConsoleTextAttribute(hConsole, CLR_FLAMINGO);
    std::cout << "The " << this->getName() << " attacked player and dealt (" << mb_baseAttack.getEffect(mb_level)
              << ") points of damage.";
//    SetConsoleTextAttribute(hConsole, CLR_VERY_LIGHT_GREY);
    std::cout << " At now, player has (" << player.getCurAttr(Attr::NameId::HEALTH) << ") hp. " << std::endl;

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
    this->setCurAttr(Attr::NameId::HEALTH, 0);
    std::cout << "Monster was scared to death of you and died of a heart attack..." << std::endl;
}



//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    Function generate loot, that remains after monster's death. Loot depends on the
//                  monster's @level (and player's @type in the future, maybe).
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
            UniquePtrClass<Item> gold {new Gold(my::getRandomNumber(0, mb_level * 10))};

            // # Проблема в том, что в my::DynamicArray::pushBack происходит два копирования элементов
            // # (при реаллокации и при непосредственном копировании аргумента в массив). Но почему
            // # копирование, когда я задал move-семантику?
            mb_loot.push_back(std::move(gold));
        }
            break;
        case Item::Type::POTION:
            if (my::getRandomNumber(0, 100) <= Potion::mb_defaultPotionChance) {
                UniquePtrClass<Item> potion {new Potion(mb_level)};
                mb_loot.push_back(std::move(potion));
            }
            else {}
            break;
        case Item::Type::TRASH:
        case Item::Type::TOTAL:
            break;
        }
    }

}



//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
void Monster::printAttr()
{
    std::cout << this->getTypeName() << "'s attributes:" << std::endl;
    Creature::printAttr();
    std::cout << "          DAMAGE:    " << mb_baseAttack.getEffect(mb_level) << std::endl;

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
