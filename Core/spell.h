#ifndef SPELL_H
#define SPELL_H

#include "main.h"
#include "Creatures/creature.h"
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

    const my::DynamicArray<Attribute>&                                     mb_attributes;           // The aray of characteristics need to be passed into <Spell> constructor
    const my::Array<float, static_cast<int>(Attr::NameId::TOTAL)>&     mb_multipliers;          // The multiplier array is hard-binded with concrete spell

    my::String                                                 mb_name {};
    School                                                      mb_school {School::UNDEF};
    int                                                         mb_baseEffect {};
    int                                                         mb_baseCost {};






public:

    /*
     * Can't create default constructor because the presence of const member variables/references
     * - they are need to be initialized!
     */
    //Spell() = default;

    Spell(const my::DynamicArray<Attribute>& attributes,
          const my::Array<float, static_cast<int>(Attr::NameId::TOTAL)>& multipliers,
          my::String name = "",
          School school = School::UNDEF,
          int baseEffect = 0,
          int baseCost = 0
        );


    //Spell& operator=(Spell&& spell) noexcept;



    const my::String& getName() const;
    int getCost(int level);
    int getEffect(int level) const;

    void setName(my::String name);
    void setSchool(School school);
    void setBaseEffect(int effect);
    void setBaseCost(int cost);



};

#endif // SPELL_H
