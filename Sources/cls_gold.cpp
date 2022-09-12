
#include "Headers/header.h"
#include "Headers/cls_item.h"
#include "Headers/cls_gold.h"


// #### Constructor of the object of type Gold
// ################
Gold::Gold(int count) :
    Item (Item::Type::GOLD, count, 0)
{
    // Nothing to do;
}
