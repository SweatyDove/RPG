#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include "main.h"

class Attribute {
public:

    enum class Name {
        HEALTH,
        STAMINA,
        MANA,
        CONCENTRATION,
        STRENGTH,
        INTELLECT,
        AGILITY,
        DODGE_CHANCE,
        ESCAPE_CHANCE,
        CRIT_CHANCE,
        ALCHEMY,
        ALCHEMY,
        CHARISMA,
        LUCK,

        TOTAL
    };
    inline static const std::array<const std::string, static_cast<int>(Name)> mb_attrName = {
        {
            "HEALTH",
            "STAMINA",
            "MANA",
            "CONCENTRATION",
            "STRENGTH",
            "INTELLECT",
            "AGILITY",
            "DODGE_CHANCE",
            "ESCAPE_CHANCE",
            "CRIT_CHANCE",
            "ALCHEMY",
            "ALCHEMY",
            "CHARISMA",
            "LUCK",
        }
    };

    enum class Type {
        RESOURCE,
        CHARACTERISTIC,
        RATING,
        SKILL,

        TOTAL
    };

    enum class ValueType {
//        BASE                  // Base value of attribute - need for level up
//        MIN,                  // Min value in order not to go into incredible low-values
        CURRENT,
        MAX,
        CUR_AND_MAX,                  // Current and max?

        TOTAL
    };

private:
    Name mb_name {};
    Type mb_type {};

//    int mb_minValue {};
    int mb_curValue {};
    int mb_maxValue {};



public:
    Attribute();


    Type getType() const;
    Name getName() const;
    void changeValue(ValueType valueType, int delta);
    int getValue(ValueType valueType) const;

    std::string_view getStringName() const;
};

#endif // ATTRIBUTE_H
