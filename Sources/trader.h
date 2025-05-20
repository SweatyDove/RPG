#ifndef TRADER_H
#define TRADER_H


#include "main.h"
#include "creature.h"
#include "item.h"
#include "gold.h"
#include "potion.h"



//==================================================================================================
//         TYPE:    Class
//  DESCRIPTION:    Describes a trader - NPC, that can buy/sell some usefull stuff
//   PARAMETERS:    ........
// RETURN VALUE:    ........
//     COMMENTS:    ........
//==================================================================================================
class Trader: public Creature {
private:
    VectorClass<UniquePtrClass<Item>> mb_inventory {};
    StringClass mb_name {"Trader"};


    void generateInventory();
public:
    Trader();
    ~Trader() override;

    void                commitSuicide() override;
    const StringClass&  getName() const override;

};






#endif // TRADER_H




