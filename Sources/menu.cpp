#include "menu.h"



//==================================================================================================
//         TYPE:    Constructor
//  DESCRIPTION:    ........
//   PARAMETERS:    ........
// RETURN VALUE:    ........
//     COMMENTS:    ........
//==================================================================================================
Menu::Menu(Type type, Creature* creature1, Creature* creature2)
{
    switch (type) {
    case Type::EXCHANGE:
        this->exchange(creature1, creature2);
        break;
    case Type::TOTAL:
        break;
    }

}
