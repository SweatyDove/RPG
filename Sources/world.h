#ifndef WORLD_H
#define WORLD_H

#include "main.h"
#include "trader.h"
#include "monster.h"
#include "menu.h"


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
    Creature*   generateCreature();
    void        openMenu(Menu::Type type, Creature* creature1, Creature* creature2);

};

#endif // WORLD_H
