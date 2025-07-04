
#include "item.h"



//==================================================================================================
//         TYPE:    Constructor
//  DESCRIPTION:    ........
//   PARAMETERS:    ........
// RETURN VALUE:    ........
//     COMMENTS:    ........
//==================================================================================================
Item::Item(Item::Type type, bool stackable, int count, int weight, int cost) :
    mb_type {type}, mb_stackable {stackable}, mb_count {count}, mb_weight {weight}, mb_cost {cost}
{
    // Nothing to do;
}


//==================================================================================================
//         TYPE:    ........
//  DESCRIPTION:    ........
//   PARAMETERS:    ........
// RETURN VALUE:    ........
//     COMMENTS:    ........
//==================================================================================================
int Item::getCount() const
{
    return mb_count;
}


//==================================================================================================
//         TYPE:    ........
//  DESCRIPTION:    ........
//   PARAMETERS:    ........
// RETURN VALUE:    ........
//     COMMENTS:    Is it weight of single Item or stack of items?
//==================================================================================================
int Item::getWeight() const
{
    return mb_weight;
}



//==================================================================================================
//         TYPE:    ........
//  DESCRIPTION:    ........
//   PARAMETERS:    ........
// RETURN VALUE:    ........
//     COMMENTS:    ........
//==================================================================================================
Item::Type Item::getType() const
{
    return mb_type;
}


//==================================================================================================
//         TYPE:    ........
//  DESCRIPTION:    ........
//   PARAMETERS:    ........
// RETURN VALUE:    ........
//     COMMENTS:    ........
//==================================================================================================
int Item::getCost() const
{
    return mb_cost;
}


//==================================================================================================
//         TYPE:    ........
//  DESCRIPTION:    ........
//   PARAMETERS:    ........
// RETURN VALUE:    ........
//     COMMENTS:    ........
//==================================================================================================
bool Item::isStackable() const
{
    return mb_stackable;
}



//==================================================================================================
//         TYPE:    ........
//  DESCRIPTION:    ........
//   PARAMETERS:    ........
// RETURN VALUE:    ........
//     COMMENTS:    Make this function virtual, because I need firstly to check the max size of
//                  stack (1000 for <Gold> for example, 20 for <Potion> and etc.)
//==================================================================================================
void Item::setCount(int newCount)
{
    mb_count = newCount;
}



// #### Function returns type of the item
// #############
//StringClass Item::getName() const
//{
//    StringClass retString {};

//    switch(mb_type) {
//    case Item::Type::TRASH:
//        retString = "trash";
//        break;
//    case Item::Type::GOLD:
//        retString = "gold";
//        break;
//    case Item::Type::POTION:
//        retString = "potion";
//        break;
////    case Item::Type::SCROLL:
////        retString = "scroll";
////        break;
//    case Item::Type::TOTAL:
//        break;
//    // ## Do not need 'default' in order to get 'warning' if we add a new Item::Type, but
//    // ## forget to use it.
//    // default:
//    //     break;
//    }

//    return retString;

//}
