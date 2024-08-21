#include "spell.h"


//==================================================================================================
//         TYPE:    Constructor
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
Spell::Spell(std::string name, School school,  const std::array<int, Param::TOTAL>& characteristics) :
    mb_name {name},
    mb_school {school},
    mb_characteristics {characteristics}
{
    // Nothing to do
}




//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
int Spell::getCost()
{

}


//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    Calculate effect of the spell, depending on creature's characteristics and they
//                  multipliers
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
int Spell::getEffect()
{
    int effect {0};

    // Here we have parameters and their multipliers
    for (int ii {0}; ii < static_cast<int>(Param::TOTAL); ++ii) {
        effect += mb_characteristics[ii] * mb_multiplier[ii];
    }

    return effect;
}


//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
const std::string_view Spell::getName() const
{
    return mb_name;
}



//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    Update array with creature's characteristics
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
void Spell::setCharacteristics(const std::array<int, Param::TOTAL>& newCharacteristics)
{
    mb_characteristics = newCharacteristics;
}
