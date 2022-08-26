
#include "header.h"
#include "cls_potion.h"

Potion::Potion() :
    Item(Item::Type::POTION, 1, defaultWeight),
    mb_type {Potion::Type::EXHAUSTED},
    mb_effect {0}
{
    // Nothing to do;
}

Potion::Potion(Potion::Type type = Type::EXHAUSTED, int effect = 0) :
    Item(Item::Type::POTION, 1, defaultWeight),
    mb_type {type},
    mb_effect {effect}
{
    // Nothing to do;
}


my::String Potion::getName() const
{
    switch(mb_type) {
    case Type::EXHAUSTED:   return "exhausted potion";
    case Type::HEALTH:      return "health potion";
    case Type::STAMINA:     return "stamina potion";
    case Type::STRENGTH:    return "strength potion";
    case Type::POISON:      return "poison";

    case Type::MAX_TYPE:    return "";
    //default:
        //break;
    }
    return "";
}



// ## Create random potion
void Potion::createRandomPotion(int lvl)
{

    // ## Generate random potion type
    mb_type = static_cast<Type>(getRandomNumber(0, static_cast<unsigned int>(Type::MAX_TYPE) - 1));



    // ## Generate random potion effect depending on the potion type and... (monster lvl?)
    switch (mb_type) {
    case Type::HEALTH:
        mb_effect = getRandomNumber(1, lvl);
        break;
    case Type::STAMINA:
        mb_effect = getRandomNumber(1, lvl);
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
    case Type::MAX_TYPE:
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
