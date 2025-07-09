#include "trader.h"


//==================================================================================================
//         TYPE:    ........
//  DESCRIPTION:    ........
//   PARAMETERS:    ........
// RETURN VALUE:    ........
//     COMMENTS:    ........
//==================================================================================================
Trader::Trader() :
    Creature(Creature::Type::TRADER, my::getRandomNumber(1, 10))
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
Trader::~Trader()
{
    // Nothing to do
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
            my::SmartPtr<Item> gold {new Gold(my::getRandomNumber(0, mb_level * 100))};
            mb_inventory.putItem(my::move(gold));
        }
        break;
        case Item::Type::POTION:
        {
            // #### Iterate each potion's type
            for (int pType {0}; pType < static_cast<int>(Potion::Type::TOTAL); ++pType) {

                for (int potionNum {my::getRandomNumber(0, 3)}; potionNum > 0; --potionNum) {
                    my::SmartPtr<Item> potion {new Potion(static_cast<Potion::Type>(pType), Potion::generateRandomEffect(static_cast<Potion::Type>(pType), this->mb_level))};
                    mb_inventory.putItem(my::move(potion));
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


//==================================================================================================
//         TYPE:    ........
//  DESCRIPTION:    ........
//   PARAMETERS:    ........
// RETURN VALUE:    ........
//     COMMENTS:    ........
//==================================================================================================
void Trader::commitSuicide()
{
    this->setCurAttr(Attr::NameId::HEALTH, 0);
    std::cout << "Trader was scared to death of you and died of a heart attack..." << std::endl;
}



//==================================================================================================
//         TYPE:    ........
//  DESCRIPTION:    ........
//   PARAMETERS:    ........
// RETURN VALUE:    ........
//     COMMENTS:    ........
//==================================================================================================
const my::String&  Trader::getName() const
{
    return mb_name;
}









