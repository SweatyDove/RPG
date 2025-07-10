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
    Creature* creature {nullptr};

    int dice {my::getRandomNumber(0, 100)};
    if (dice < 0) {
        creature = new Monster {};
    }
    else {
        creature = new Trader {};
    }

    return creature;

}



//==================================================================================================
//         TYPE:    Member function
//  DESCRIPTION:    ........
//   PARAMETERS:    ........
// RETURN VALUE:    ........
//     COMMENTS:    ........
//==================================================================================================
void World::openMenu(Menu::Type type, Creature* creature1, Creature* creature2)
{

}



























