#ifndef SPELL_H
#define SPELL_H

#include "main.h"


class Spell {
public:
    enum class School {
        UNDEF,
        PHYSICAL,
        PHYSICAL_NATURE,                    // Temporary for several spell schools
        PHYSICAL_DARKNESS,
        MAGIC,

        TOTAL
    };

    // ######## There are list of parameters below from which spell depends
    enum Param {
        BASE,
        STAMINA,
        MANA,
        CONCENTRATION,

        TOTAL
    };

    // ######## The multiplier array is hard-binded with concrete spell
    std::array<float, Spell::Param::TOTAL> mb_multiplier {
        1.0,                    // BASE
        2.0,                    // STAMINA
        0.0,                    // MANA
        0.0                     // CONCENTRATION
    };

    //std::array<int, Spell::Param::TOTAL> mb_characteristics {10, 50, 0, 0};


private:

    std::string     mb_name {};
    School          mb_school {School::UNDEF};
    int             mb_effect {};
    int             mb_cost {};

    // ######## The aray of characteristics need to be passed into <Spell> constructor
    std::array<int, Param::TOTAL>& mb_characteristics;



public:
    /*
     * STAND HERE: need to handle with const qualifier
     */
    //Spell() = default;
    Spell(std::string name, School school, const std::array<int, Param::TOTAL>& characteristics);

    const std::string_view getName() const;
    int getCost();
    int getEffect();

    void setCharacteristics(const std::array<int, Param::TOTAL>& newCharacteristics);
};

#endif // SPELL_H
