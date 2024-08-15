#include "creature.h"


//==================================================================================================
//         NAME:    --------
//  DESCRIPTION:    Create specified creature
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
Creature::Creature(Creature::Type type, int level) :
    mb_type {type}, mb_level {level}
{
    // Nothing to do
}
