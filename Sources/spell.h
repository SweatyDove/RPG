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

    const VectorClass<Attribute>&                                     mb_attributes;           // The aray of characteristics need to be passed into <Spell> constructor
    const ArrayClass<float, static_cast<int>(Attr::Name::TOTAL)>&     mb_multipliers;          // The multiplier array is hard-binded with concrete spell

    StringClass                                                 mb_name {};
    School                                                      mb_school {School::UNDEF};
    int                                                         mb_baseEffect {};
    int                                                         mb_baseCost {};






public:

    /*
     * Can't create default constructor because the presence of const member variables/references
     * - they are need to be initialized!
     */
    //Spell() = default;

    Spell(const VectorClass<Attribute>& attributes,
          const ArrayClass<float, static_cast<int>(Attr::Name::TOTAL)>& multipliers,
          StringClass name = "",
          School school = School::UNDEF,
          int baseEffect = 0,
          int baseCost = 0
        );


    //Spell& operator=(Spell&& spell) noexcept;



    const StringClass& getName() const;
    int getCost(int level);
    int getEffect(int level) const;

    void setName(StringClass name);
    void setSchool(School school);
    void setBaseEffect(int effect);
    void setBaseCost(int cost);



};

#endif // SPELL_H
