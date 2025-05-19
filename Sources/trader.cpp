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

    for (int iType {0}; iType < static_cast<int>(Item::Type::TOTAL); ++iType) {

        switch (static_cast<Item::Type>(iType)) {
        case Item::Type::GOLD:
        {
            UniquePtrClass<Item> gold {new Gold(my::getRandomNumber(0, mb_level * 100))};
            mb_inventory.push_back(my::move(gold));
        }
        break;
        case Item::Type::POTION:
        {
            // #### Iterate each potion's type
            for (int pType {0}; pType < static_cast<int>(Potion::Type::TOTAL); ++pType) {

                for (int potionNum {my::getRandomNumber(0, 3)}; potionNum > 0; --potionNum) {
                    UniquePtrClass<Item> potion {new Potion(static_cast<Potion::Type>(pType))};
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













