#ifndef TRADER_H
#define TRADER_H


#include "../main.h"
#include "creature.h"
#include "../Items/item.h"
#include "../Items/gold.h"
#include "../Items/potion.h"



//==================================================================================================
//         TYPE:    Class
//  DESCRIPTION:    Describes a trader - NPC, that can buy/sell some usefull stuff
//   PARAMETERS:    ........
// RETURN VALUE:    ........
//     COMMENTS:    ........
//==================================================================================================
class Trader: public Creature {
private:
//    my::DynamicArray<my::SmartPtr<Item>> mb_inventory {};
    my::String mb_name {"Trader"};


    void generateInventory();
public:
    Trader();
    ~Trader() override;

    void                commitSuicide() override;
    const my::String&  getName() const override;

};






#endif // TRADER_H




