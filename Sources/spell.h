#ifndef SPELL_H
#define SPELL_H

#include "main.h"
#include "creature.h"
#include "attribute.h"


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


    const std::vector<Attribute>& mb_attributes;                        // The aray of characteristics need to be passed into <Spell> constructor
    const std::array<float, static_cast<int>(Attr::Name::TOTAL)>& mb_multipliers;          // The multiplier array is hard-binded with concrete spell



public:

    //Spell() = default;
    Spell(std::string name, School school, int baseEffect, int baseCost,
         const std::vector<Attribute>& attributes,
         const std::array<float, static_cast<int>(Attr::Name::TOTAL)>& multipliers);

    const std::string_view getName() const;
    int getCost(int level);
    int getEffect(int level);


};

#endif // SPELL_H
