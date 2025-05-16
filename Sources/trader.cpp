#include "trader.h"


//==================================================================================================
//         TYPE:    ........
//  DESCRIPTION:    ........
//   PARAMETERS:    ........
// RETURN VALUE:    ........
//     COMMENTS:    ........
//==================================================================================================
Trader::Trader(int level) :
    Creature(Creature::Type::TRADER, level)
{
    this->generateInventory();
}



//==================================================================================================
//         TYPE:    ........
//  DESCRIPTION:    ........
//   PARAMETERS:    ........
// RETURN VALUE:    ........
//     COMMENTS:    ........
//==================================================================================================
void Trader::generateInventory()
{
    // # Iterate each type of <Item>
    for (Item::Type iType {static_cast<Item::Type>(0)}; iType < Item::Type::TOTAL; ++iType) {

        switch (iType) {
        case Item::Type::GOLD:
        {
            UniquePtrClass<Item> gold {new Gold(my::getRandomNumber(0, mb_level * 100))};
            mb_inventory.push_back(my::move(gold));
        }
        break;
        case Item::Type::POTION:
        {
            // #### Iterate each potion's type
            for (Potion::Type pType {static_cast<Potion::Type>(0)}; pType < Potion::Type::TOTAL; pType++) {
                for (int potionNum {my::getRandomNumber(0, 3)}; potionNum > 0; --potionNum) {
                    UniquePtrClass<Item> potion {new Potion(pType)};
                    mb_inventory.pushBack(my::move(potion));
                }
            }
        }
        break;
        case Item::Type::TRASH:
        case Item::Type::TOTAL:
            break;
        }
    }

}













