#ifndef MENU_H
#define MENU_H


#include "Creatures/creature.h"

//==================================================================================================
//         TYPE:    Class
//  DESCRIPTION:    Responsible for the managing of the different kinds of menu (dialog windows)
//   PARAMETERS:    ........
// RETURN VALUE:    ........
//     COMMENTS:    Что такое меню? Это способ взаимодейстчия между сущностями (игрок и контейнер),
//                  (игрок и торговец), (игрок и он сам). То есть в данном случае взаимодействие
//                  должно происходить как бы статически (бой тоже взаимодействие, но с другим...
//                  ...интерфейсом). Но в данном случае, под меню я, наверное, подразумеваю всплывающее
//                  диалоговое окно, которое може ставит игру на паузу, а может и нет...
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

    // # Может я могу объединить в одну обе функции в будущем (т.к. покупка/продажа - это просто
    // # обмен на золото)
    void sell(Container& subjectContainer, Container& objectContainer);
    void buy(Container& subjectContainer, Container& objectContainer);



public:
    Menu(Type type, Creature* creature1, Creature* creature2 = nullptr);

    void run();

};











#endif // MENU_H











