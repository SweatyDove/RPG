
#include "main.h"
#include "potion.h"



//==================================================================================================
//         NAME:    --------
//  DESCRIPTION:    Generate RANDOM potion according to @level
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
Potion::Potion(int level) :
    Item(Item::Type::POTION, 1, defaultWeight)
{
    this->generateRandomPotion(level);
}

//==================================================================================================
//         NAME:    --------
//  DESCRIPTION:    Generate with the given @type and @effect
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
Potion::Potion(Potion::Type type, int effect) :
    Item(Item::Type::POTION, 1, defaultWeight),
    mb_type {type},
    mb_effect {effect}
{
    // Nothing to do;
}


my::String Potion::getName() const
{
    my::String retString {""};

    switch(mb_type) {
    case Type::EXHAUSTED:   return "exhausted potion";
    case Type::HEALTH:      return "health potion";
    case Type::STAMINA:     return "stamina potion";
    case Type::STRENGTH:    return "strength potion";
    case Type::POISON:      return "poison";

    case Type::TOTAL:    return "";
    //default:
        //break;
    }
    return "";
}



//==================================================================================================
//         NAME:    --------
//  DESCRIPTION:    Generate random potion
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
void Potion::generateRandomPotion(int lvl)
{

    // ######## Generate random potion type
    mb_type = static_cast<Type>(getRandomNumber(0, static_cast<unsigned int>(Type::TOTAL) - 1));


    // ######## Generate random potion effect depending on the potion type and... (monster lvl?)
    switch (mb_type) {
    case Type::HEALTH:
        mb_effect = getRandomNumber(10, lvl * 10);
        break;
    case Type::STAMINA:
        mb_effect = getRandomNumber(10, lvl * 10);
        break;
    case Type::STRENGTH:
        mb_effect = getRandomNumber(1, (lvl + 1) / 2);
        break;
    case Type::POISON:
        mb_effect = getRandomNumber(1, lvl);
        break;
    case Type::EXHAUSTED:
        mb_effect = 0;
        break;
    case Type::TOTAL:
        mb_effect = 0;
        break;
    //default:
        //break;
    }

    return;
}


int Potion::getEffect() const
{
    return mb_effect;
}
