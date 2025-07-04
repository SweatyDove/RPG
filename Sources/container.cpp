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
//                  1) There is a problem with item's weight, because I need to decide if getWeight()
//                      returns weight of stack or item in stack.
//                  2) Simplify logic
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
    else {}


    // # Firstly - try to stack item if it is stackable
    if (itemPtr->isStackable()) {

        Item::Type itemType {itemPtr->getType()};

        // # Go through each cell of the container
        for (auto& cell: this->mb_container) {

            // ## Check if there is something in the container cell
            if (cell.isFree()) {
                continue;
            }
            else if (cell->getType() != itemType) {
                continue;
            }
            else {
                /*
                 * If I can't stack item cause of stack limit: or skip this step and go further
                 * or stack partially.
                 */
                cell->setCount(cell->getCount() + itemPtr->getCount());
                return ErrorCode::OPERATION_SUCCEED;
            }
        } // for-loop
    }
    else {}


    // # If item is NOT stackable OR couldn't find it in container - check space limit and then put
    // # item in the first free cell
    if (mb_spaceOccupied >= mb_spaceLimit) {
        std::cout << "Can't put item in the " << this->getName() << ": reached the space limit." << std::endl;
        return ErrorCode::REACHED_SPACE_LIMIT;
    }
    else {
        // # Go through each cell of the container
        for (auto& cell: this->mb_container) {

            // ## Check if there is something in the container cell
            if (cell.isFree()) {
                cell = itemPtr;
//                cell = my::move(itemPtr);
                mb_spaceOccupied += 1;
                mb_weightOccupied += itemPtr->getWeight();
                return ErrorCode::OPERATION_SUCCEED;
            }
            else {}
        } // for-loop
    }

}


//==================================================================================================
//         TYPE:    Public member function
//  DESCRIPTION:    ........
//   PARAMETERS:    ........
// RETURN VALUE:    ........
//     COMMENTS:    ........
//==================================================================================================
const UniquePtrClass<Item>& Container::extractItem(int itemPosition)
{
    // # Invalid position (May be I have to use assert() here? Who is responsible for the checking
    // # of the position validity: <Container> or caller?)
    if (itemPosition < 0 || itemPosition >= mb_spaceLimit) {
//        return ErrorCode::INVALID_ITEM_POSITION;
    }
    else {}

    try {
        UniquePtrClass<Item> cell {mb_container[itemPosition]};
//        UniquePtrClass<Item> extractedItem {my::move(mb_container[itemPosition])};
        if (cell.isFree()) {
//            return ErrorCode::CELL_IS_EMPTY ;
        }
        else {
            return cell;
        }
    }
    // # Here catch an exception, when position is valid, but @mb_container.size() < position
    catch (const DynamicArrayException<Item>& exception) {
//        return ErrorCode::CELL_IS_EMPTY;
    }

}












