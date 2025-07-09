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
Container::Container(my::String name) :
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
const my::String& Container::getName()
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
int Container::putItem(const my::SmartPtr<Item>& itemPtr)
{
    // # Compare item and container types
    if (mb_type != Container::Type::UNIVERSAL) {
        assert(false && "Do not release special types of containers yet. Abort.");
    }
    else {}


    // # Check weight and space limits
    if (mb_weightOccupied + itemPtr->getWeight() > mb_weightLimit) {
        std::cout << "Can't put item in the " << this->getName() << ": reached the weight limit." << std::endl;
        return OperationStatus::ERR_REACHED_WEIGHT_LIMIT;
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
                return OperationStatus::SUCCEED;
            }
        } // for-loop
    }
    else {}


    // # If item is NOT stackable OR couldn't find it in container - check space limit and then put
    // # item in the first free cell
    if (mb_spaceOccupied >= mb_spaceLimit) {
        std::cout << "Can't put item in the " << this->getName() << ": reached the space limit." << std::endl;
        return OperationStatus::ERR_REACHED_SPACE_LIMIT;
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
                return OperationStatus::SUCCEED;
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
//     COMMENTS:    I'm not sure, that returning nullptr is correct...
//==================================================================================================
const my::SmartPtr<Item>& Container::extractItem(int itemPosition)
{

    // # Invalid position (May be I have to use assert() here? Who is responsible for the checking
    // # of the position validity: <Container> or caller?)
    if (itemPosition < 0 || itemPosition >= mb_spaceLimit) {
        std::cout << "Invalid item position!" << std::endl;
        return nullptr;
//        throw my::Exception("Container: invalid item position!");
    }
    else {}


    try {
        my::SmartPtr<Item> cell {mb_container[itemPosition]};
        //my::SmartPtr<Item> extractedItem {my::move(mb_container[itemPosition])};
        if (cell.isFree()) {
            std::cout << "Cell is empty" << std::endl;
            return nullptr;
//            throw my::Exception("Container: cell is empty!");
        }
        else {
            return cell;
        }
    }
    // # Here catch an exception, when position is valid, but @mb_container.size() < position
    catch (const my::DynamicArrayException<Item>& exception) {
        std::cout << "Cell is empty" << std::endl;
        return nullptr;
    }

}


//==================================================================================================
//         TYPE:    Public member function
//  DESCRIPTION:    Find item in container
//   PARAMETERS:    ........
// RETURN VALUE:    Item position, if it was found. Otherwise returns '-1'.
//     COMMENTS:    What to do with multiple instances of items?
//==================================================================================================
int Container::findItem(Item::Type type)
{
    for (int ii {0}; ii < mb_container.size(); ++ii) {

        const my::SmartPtr<Item>& cell = mb_container[ii];

        if (cell->getType() == type) {
            return ii;
        }
        else {}
    }

    return -1;
}



//==================================================================================================
//         TYPE:    ........
//  DESCRIPTION:    Display container's content
//   PARAMETERS:    ........
// RETURN VALUE:    ........
//     COMMENTS:    ........
//==================================================================================================
void Container::display()
{
    my::String titleId     {"ID"};
    my::String titleName   {"NAME"};
    my::String titleCount  {"COUNT"};
    my::String titleCost   {"COST"};

    std::cout << "\nInventory of " << this->getName()
              << "\n-------------------------------------------------------------------------------\n"
              << titleId      << " | "
              << std::setw(32)  << titleName    << " | "
              << std::setw(8)   << titleCount   << " | "
              << std::setw(8)   << titleCost
              << "\n-------------------------------------------------------------------------------\n"
              << std::endl;

    for (int ii {0}; ii < mb_inventory.size(); ++ii) {
        std::cout << std::setw(2)   << ii               << " | "
                  << std::setw(32)  << mb_inventory[ii]->getName()  << " | "
                  << std::setw(8)   << mb_inventory[ii]->getCount() << " | "
                  << std::setw(8)   << mb_inventory[ii]->getCost() << std::endl;
    }

    std::cout << "-------------------------------------------------------------------------------" << std::endl;

}







