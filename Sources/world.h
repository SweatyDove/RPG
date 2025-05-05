#ifndef WORLD_H
#define WORLD_H

#include "trader.h"
#include "monster.h"



//==================================================================================================
//         TYPE:    Class
//  DESCRIPTION:    Responsible for creating the world and generating events.
//   PARAMETERS:    ........
// RETURN VALUE:    ........
//     COMMENTS:    ........
//==================================================================================================
class World {
public:
    World();
    Creature& generateCreature(Creature::Type type = Creature::Type::RANDOM);

};

#endif // WORLD_H
