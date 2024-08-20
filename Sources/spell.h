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

private:

    std::string     mb_name {};
    School          mb_school {School::UNDEF};
    int             mb_effect {};
    int             mb_cost {};



public:
    Spell() = default;
    Spell(std::string name, School school);

    const std::string_view getName() const;
    int getCost();
    int getEffect();
};

#endif // SPELL_H
