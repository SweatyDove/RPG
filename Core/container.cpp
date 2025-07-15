#include "container.h"





//==================================================================================================
//         TYPE:    Default constructor
//  DESCRIPTION:    ........
//   PARAMETERS:    ........
// RETURN VALUE:    ........
//     COMMENTS:    ........
//==================================================================================================
Container::Container() :
    mb_container(st_defaultCellIncrement)                // Direct-initialization
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
Container::Container(Type type, int spaceLimit, int weightLimit) :
    mb_type {type},
    mb_spaceLimit {spaceLimit},
    mb_weightLimit {weightLimit},
    mb_container(st_defaultCellIncrement)                        // Direct-initialization
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
    mb_name {name},
    mb_container(st_defaultCellIncrement)                        // Direct-initialization
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
const my::String& Container::getName() const
{
    return mb_name;
}



//==================================================================================================
//         TYPE:    [Draft] Public member function
//  DESCRIPTION:    ........
//   PARAMETERS:    ........
// RETURN VALUE:    ........
//     COMMENTS:    What should I keep in mind
//                  1) There is a problem with item's weight, because I need to decide if getWeight()
//                      returns weight of stack or item in stack.
//                  2) Simplify logic
//==================================================================================================
int Container::putItem(my::SmartPtr<Item>& itemPtr)
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




    // # If item is NOT stackable OR couldn't find it in the container - check space limit and then put
    // # item in the first free cell
    assert(mb_spaceOccupied <= mb_spaceLimit && "This condition should always be true!");

    if (mb_spaceOccupied == mb_spaceLimit) {
        std::cout << "Can't put item in the " << this->getName() << ": reached the space limit." << std::endl;
        return OperationStatus::ERR_REACHED_SPACE_LIMIT;
    }
    // # If amount of cells, allocated in the container (heap), is equal to the number of items, placed in
    // # these cells (@mb_spaceOccupied) - then need to allocate more cells (but no more than @mb_spaceLimit)
    else if (mb_spaceOccupied == mb_container.size()) {

            int moreCells {mb_container.size() + st_defaultCellIncrement};
            moreCells = (moreCells > mb_spaceLimit) ? mb_spaceLimit : moreCells;
            mb_container.resize(moreCells);
    }
    else {}


    // # Go through each cell of the container to find the first free cell
//    for (int ii {0}; ii < mb_container.size(); ++ii) {
    for (auto& cell: mb_container) {

        // ## Check if there is something in the container cell
        if (cell.isFree()) {
            cell = my::move(itemPtr);
            mb_spaceOccupied += 1;
            mb_weightOccupied += cell->getWeight();
            return OperationStatus::SUCCEED;
        }
        else {}

    } // for-loop

    assert(false && "Shouldn't reach that point.");

}


//==================================================================================================
//         TYPE:    Public member function
//  DESCRIPTION:    Extract item on @itemPosition from the container
//   PARAMETERS:    ........
// RETURN VALUE:    ........
//     COMMENTS:    I'm not sure, that returning nullptr is correct...
//==================================================================================================
const my::SmartPtr<Item>& Container::extractItem(int itemPosition)
{

    // # Invalid position (May be I have to use assert() here? Who is responsible for the checking
    // # of the position validity: <Container> or caller?)
    if (itemPosition < 0 || itemPosition >= mb_spaceLimit) {
        throw my::Exception("Container: invalid item position!");
    }
    else if (itemPosition > mb_container.size()) {
        throw my::Exception("Container: cell is empty!");
    }


    //  my::SmartPtr<Item> cell {mb_container[itemPosition]};
    /*
     * 1) У меня есть контейнер с умными указателями (то есть с ресурсами, выделенными в дин. памяти)
     * 2) Я хочу забрать ресурс. Для этого вызываю move-семантику, иначе my::SmartPtr не даст этого
     * сделать, так как он запрещает копирование - только перемещение можно.
     * 3) Однако, просто l-reference нельзя инициализировать с помощью r-ref, поэтому нужен const l-ref
     */
    const my::SmartPtr<Item>& cell {my::move(mb_container[itemPosition])};

    /*
     * Во-вторых, если cell - l-value-reference, то после того, как данная функция отработает и попробует
     * вернуть cell, она вернёт локальную копию - то есть получим dangling-reference. В таком случае надо возвращать
     * по значению
     */


    if (cell.isFree()) {
        throw my::Exception("Container: cell is empty!");
    }
    else {
        return cell;
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
void Container::display() const
{
    my::String titleId     {"ID"};
    my::String titleName   {"NAME"};
    my::String titleCount  {"COUNT"};
    my::String titleCost   {"COST"};

    std::cout << "\nContent of (" << this->getName() << ")"
              << "\n-------------------------------------------------------------------------------\n"
              << titleId      << " | "
              << std::setw(32)  << titleName    << " | "
              << std::setw(8)   << titleCount   << " | "
              << std::setw(8)   << titleCost
              << "\n-------------------------------------------------------------------------------\n"
              << std::endl;

    for (int ii {0}; ii < mb_container.size(); ++ii) {

        const my::SmartPtr<Item>& item {mb_container[ii]};
        if (item == false) {
            continue;
        }
        else {
            std::cout << std::setw(2)   << ii               << " | "
                      << std::setw(32)  << item->getName()  << " | "
                      << std::setw(8)   << item->getCount() << " | "
                      << std::setw(8)   << item->getCost() << std::endl;
        }
    }

    std::cout << "-------------------------------------------------------------------------------" << std::endl;

}







