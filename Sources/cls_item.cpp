
#include "header.h"
#include "cls_item.h"



// ************************ Constructors and Destructors  ************************ //

Item::Item(Item::Type type = Item::Type::TRASH, int count = 1, int weight = 1) :
    mb_type {type}, mb_count {count}, mb_weight {weight}
{
    // Nothing to do;
}

// ****************************  Setters and Getters  **************************** //

int Item::getCount() const              { return mb_count; }
int Item::getWeight() const             { return mb_weight; }
Item::Type Item::getType() const        { return mb_type; }


// ******************************  Other Functions  ******************************* //



// #### Function returns type of the item
// #############
my::String Item::getTypeName() const
{
    my::String retString {};

    switch(mb_type) {
    case Item::Type::TRASH:
        retString = "trash";
        break;
    case Item::Type::GOLD:
        retString = "gold";
        break;
    case Item::Type::POTION:
        retString = "potion";
        break;
//    case Item::Type::SCROLL:
//        retString = "scroll";
//        break;
    case Item::Type::TOTAL:
        break;
    // ## Do not need 'default' in order to get 'warning' if we add a new Item::Type, but
    // ## forget to use it.
    // default:
    //     break;
    }

    return retString;

}
