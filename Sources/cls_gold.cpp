
#include "header.h"
#include "cls_item.h"
#include "cls_gold.h"


// #### Constructor of the object of type Gold
// ################
Gold::Gold(int count) :
    Item (Item::Type::GOLD, count, 0)
{
    // Nothing to do;
}
