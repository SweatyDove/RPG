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
        UNDEF,
        EXCHANGE,

        TOTAL
    };

    enum class Exchange {
        QUIT,
        SELL,
        BUY,

        TOTAL
    };

private:

    Type        mb_type     {Type::UNDEF};
    Creature*   mb_subject  {nullptr};
    Creature*   mb_object   {nullptr};                  // Can be an <Item> as well



    void exchange();
    void sell();
    void buy();



public:
    Menu(Type type, Creature* creature1, Creature* creature2 = nullptr);

    void run();

};











#endif // MENU_H











