#ifndef SPELL_H
#define SPELL_H

#include "main.h"
#include "creature.h"


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



private:

    std::string     mb_name {};
    School          mb_school {School::UNDEF};
    int             mb_baseEffect {};
    int             mb_baseCost {};

    // ######## The aray of characteristics need to be passed into <Spell> constructor
    const std::array<int, static_cast<int>(Creature::Characteristics::TOTAL)>& mb_characteristics;

    // ######## The multiplier array is hard-binded with concrete spell
    const std::array<float, static_cast<int>(Creature::Characteristics::TOTAL)>& mb_multiplier;



public:

    //Spell() = default;
    Spell(std::string name, School school, int baseEffect, int baseCost,
          const std::array<int,static_cast<int>(Creature::Characteristics::TOTAL)>& characteristics,
          const std::array<float, static_cast<int>(Creature::Characteristics::TOTAL)>& multiplier);

    const std::string_view getName() const;
    int getCost(int level);
    int getEffect(int level);


};

#endif // SPELL_H
