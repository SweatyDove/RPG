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
    int dice {my::getRandomNumber(0, 100)};
    Creature* creature {nullptr};

    if (dice < 20) {
        creature = new Monster {};
    }
    else {
        creature = new Monster {};
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



























