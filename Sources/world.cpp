#include "world.h"




//==================================================================================================
//         TYPE:    Constructor
//  DESCRIPTION:    Default constructor
//   PARAMETERS:    ........
// RETURN VALUE:    ........
//     COMMENTS:    ........
//==================================================================================================
World::World()
{

}




//==================================================================================================
//         TYPE:    ........
//  DESCRIPTION:    ........
//   PARAMETERS:    ........
// RETURN VALUE:    ........
//     COMMENTS:    ........
//==================================================================================================
Creature& World::generateCreature(Creature::Type type)
{
    // # Generate random type
    if (type == Creature::Type::RANDOM) {
        type = static_cast<Creature::Type>(getRandomNumber(1, static_cast<int>(Creature::Type::TOTAL) - 1));
    }
    else {}

}





