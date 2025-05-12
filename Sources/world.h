#ifndef WORLD_H
#define WORLD_H

#include "trader.h"
#include "monster.h"
#include "my_utilities.h"



//==================================================================================================
//         TYPE:    Class
//  DESCRIPTION:    Responsible for creating the world and generating events.
//   PARAMETERS:    ........
// RETURN VALUE:    ........
//     COMMENTS:    ........
//==================================================================================================
class World {
private:

public:
    World();
    Creature* generateCreature();

};

#endif // WORLD_H
