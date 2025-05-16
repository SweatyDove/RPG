#ifndef MENU_H
#define MENU_H


#include "creature.h"

//==================================================================================================
//         TYPE:    Class
//  DESCRIPTION:    Responsible for the managing of the different kinds of menu
//   PARAMETERS:    ........
// RETURN VALUE:    ........
//     COMMENTS:    ........
//==================================================================================================
class Menu {
public:
    enum class Type {
        EXCHANGE,
        TOTAL
    };

    Menu(Type type, Creature* creature1, Creature* creature2 = nullptr);
};

#endif // MENU_H
