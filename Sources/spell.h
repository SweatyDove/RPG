#ifndef SPELL_H
#define SPELL_H

#include "main.h"


class Spell {
public:
    enum class School {
        UNDEF,
        PHYSICAL,
        MAGIC,

        TOTAL
    };

private:

    std::string     mb_name {};
    School          mb_school {School::UNDEF};
    int             mb_effect {};
    int             mb_cost {};



public:
    Spell(std::string name, School school);

    /*
     * If cost and effect changes dinamically, maybe I need only getCost()/getEffect() functions,
     * that calculates values in place?
     */
    void setCost();
    void setEffect();
};

#endif // SPELL_H
