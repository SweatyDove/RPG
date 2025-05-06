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
//         TYPE:    Member function
//  DESCRIPTION:    Generate random creature
//   PARAMETERS:    ........
// RETURN VALUE:    ........
//     COMMENTS:    ........
//==================================================================================================
Creature* World::generateCreature()
{
    int dice {getRandomNumber(0, 100)};
    Creature* creature {nullptr};

    if (dice < 20) {
        creature = new Monster {};
    }
    else {
        creature = new Trader {};
    }

    return creature;

}




























