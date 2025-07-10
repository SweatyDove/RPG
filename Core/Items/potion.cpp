
#include "potion.h"


//==================================================================================================
//         TYPE:    ........
//  DESCRIPTION:    Generate potion with the given @type and @effect
//   PARAMETERS:    ........
// RETURN VALUE:    ........
//     COMMENTS:    ........
//==================================================================================================
Potion::Potion(Potion::Type potionType, int effect) :
    Item(Item::Type::POTION, false, 1, defaultWeight),
    mb_type {potionType},
    mb_effect {effect}
{
    mb_cost = this->generateCost();
}



//==================================================================================================
//         TYPE:    ........
//  DESCRIPTION:    Generate RANDOM potion according to @level
//   PARAMETERS:    ........
// RETURN VALUE:    ........
//     COMMENTS:    ........
//==================================================================================================
Potion::Potion(int level) :
    Item(Item::Type::POTION, 1, defaultWeight),
    mb_type {this->generateRandomType()},
    mb_effect {this->generateRandomEffect(mb_type, level)}
{
    mb_cost = this->generateCost();
}


//==================================================================================================
//         TYPE:    ........
//  DESCRIPTION:    Get name of the potion as a string
//   PARAMETERS:    ........
// RETURN VALUE:    ........
//     COMMENTS:    ........
//==================================================================================================
const my::String Potion::getName() const
{
    my::String retString {""};

    // # Add effect type
    if (mb_effect < 0) {
        retString << "poisoned ";
    }
    else if (mb_effect == 0) {
        retString << "exhausted ";
    }
    else {}


    switch(mb_type) {
    case Type::HEALTH:
        retString << "health potion";
        break;
    case Type::STAMINA:
        retString << "stamina potion";
        break;
    case Type::STRENGTH:
        retString << "strength potion";
        break;
    case Type::TOTAL:
        assert(false && "Incorrect potion type. Abort.");
        break;
    }


    return retString;
}


//==================================================================================================
//         TYPE:    ........
//  DESCRIPTION:    ........
//   PARAMETERS:    ........
// RETURN VALUE:    ........
//     COMMENTS:    ........
//==================================================================================================
int Potion::generateCost()
{

    int typeMult {0};                        // Cost's multiplier, that depends on potion's type
    int effectAdd {0};                      // Cost's additive, that depends on potion's effect


    // # Define @typeMult
    switch (mb_type) {
    case Potion::Type::HEALTH:
        typeMult = 5;
        break;
    case Potion::Type::STAMINA:
        typeMult = 4;
        break;
    case Potion::Type::STRENGTH:
        typeMult = 3;
        break;
    case Potion::Type::TOTAL:
        assert(false && "Incorrect potion type!");
        break;
    }


    // # Define @effectAdd
    effectAdd = (mb_effect >= 0) ? mb_effect : -mb_effect;

    // # Formula
    return typeMult * 10 + effectAdd;
}



//==================================================================================================
//         TYPE:    ........
//  DESCRIPTION:    Generate random potion with @mb_effect, that depends on the @lvl
//   PARAMETERS:    ........
// RETURN VALUE:    ........
//     COMMENTS:    ........
//==================================================================================================
void Potion::generateRandomPotion(int lvl)
{
    mb_type = this->generateRandomType();
    mb_effect = this->generateRandomEffect(mb_type, lvl);
    mb_cost = this->generateCost();
}




//==================================================================================================
//         TYPE:    ........
//  DESCRIPTION:    Generate random potion effect, that depends on @lvl
//   PARAMETERS:    @lvl - level of creature (player/monster/trader/etc)
// RETURN VALUE:    ........
//     COMMENTS:    ........
//==================================================================================================
int Potion::generateRandomEffect(Potion::Type pType, int lvl)
{
    int effect {0};

    switch (pType) {
    case Type::HEALTH:
        effect = my::getRandomNumber(lvl * (-10), lvl * 10);
        break;
    case Type::STAMINA:
        effect = my::getRandomNumber(lvl * (-10), lvl * 10);
        break;
    case Type::STRENGTH:
        effect = my::getRandomNumber(0, (lvl + 1) / 2);
        break;
    case Type::TOTAL:
        assert(false && "Incorrect potion type. Abort.");
        break;
    }

    return effect;
}



//==================================================================================================
//         TYPE:    ........
//  DESCRIPTION:    Generate random potion type.
//   PARAMETERS:    ........
// RETURN VALUE:    ........
//     COMMENTS:    ........
//==================================================================================================
Potion::Type Potion::generateRandomType()
{
    return (static_cast<Type>(my::getRandomNumber(0, static_cast<unsigned int>(Type::TOTAL) - 1)));
}



//==================================================================================================
//         TYPE:    Member function (getter)
//  DESCRIPTION:    Get value of the potion's effect
//   PARAMETERS:    ........
// RETURN VALUE:    ........
//     COMMENTS:    ........
//==================================================================================================
int Potion::getEffect() const
{
    return mb_effect;
}
