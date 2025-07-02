#include "container.h"


//==================================================================================================
//         TYPE:    Constructor
//  DESCRIPTION:    ........
//   PARAMETERS:    ........
// RETURN VALUE:    ........
//     COMMENTS:    ........
//==================================================================================================
Container::Container(Type type, int spaceLimit, int weightLimit) :
    mb_type {type},
    mb_spaceLimit {spaceLimit},
    mb_weightLimit {weightLimit}
{
    // Nothing to do
}




//==================================================================================================
//         TYPE:    Constructor
//  DESCRIPTION:    ........
//   PARAMETERS:    ........
// RETURN VALUE:    ........
//     COMMENTS:    ........
//==================================================================================================
Container::Container(StringClass name) :
    mb_name {name}
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
const StringClass& Container::getName()
{
    return mb_name;
}



//==================================================================================================
//         TYPE:    Public member function
//  DESCRIPTION:    ........
//   PARAMETERS:    ........
// RETURN VALUE:    ........
//     COMMENTS:    What should I keep in mind
//                  1)  If <Item> is stackable, then I can ignore situations, when occupied == limit,
//                      otherwise I need firstly to ckeck if there are some free cells.
//                  2)
//==================================================================================================
int Container::putItem(const UniquePtrClass<Item>& itemPtr)
{
    // # Compare item and container types
    if (mb_type != Container::Type::UNIVERSAL) {
        assert(false && "Do not release special types of containers yet. Abort.");
    }
    else {}


    // # Check weight and space limits
    if (mb_weightOccupied + itemPtr->getWeight() > mb_weightLimit) {
        std::cout << "Can't put item in the " << this->getName() << ": reached the weight limit." << std::endl;
        return ErrorCode::REACHED_WEIGHT_LIMIT;
    }
    else if (itemPtr->isStackable() == false && mb_spaceOccupied == mb_spaceLimit) {
        std::cout << "Can't put item in the " << this->getName() << ": reached the space limit." << std::endl;
        return ErrorCode::REACHED_SPACE_LIMIT;
    }
    else {}


    if (itemPtr->isStackable()) {

        // # Go through each cell of the container
        for (auto& cell: this->mb_container) {

            // ## Check if there is something in the container cell
            if (cell.isFree()) {
                continue;
            }
            else {}

            //
            if (inventoryItemPtr->getType() == Item::Type::GOLD) {
                inventoryItemPtr->setCount(inventoryItemPtr->getCount() + itemPtr->getCount());
                return 0;
            }
            else {}
        }
        // ## Didn't find 'gold'
        this->mb_inventory.pushBack(itemPtr);




    // # Special case for <Gold>
    if (itemPtr->getType() == Item::Type::GOLD) {
        for (const auto& inventoryItemPtr: this->mb_container) {
            if (inventoryItemPtr->getType() == Item::Type::GOLD) {
                inventoryItemPtr->setCount(inventoryItemPtr->getCount() + itemPtr->getCount());
                return 0;
            }
            else {}
        }
        // ## Didn't find 'gold'
        this->mb_inventory.pushBack(itemPtr);
    //        this->mb_inventory.pushBack(my::move(itemPtr));



    }
    // # Add item in the first free cell of @mb_inventory
    else {
        for (auto& inventoryItemPtr: this->mb_inventory) {
            if (*inventoryItemPtr == nullptr) {
                inventoryItemPtr = itemPtr;
                return;
            }
            else {}
        }
        // ## Didn't find free cell in @mb_inventory
        this->mb_inventory.pushBack(itemPtr);
    }

    return;

}
