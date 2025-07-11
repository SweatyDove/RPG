#ifndef CONTAINER_H
#define CONTAINER_H

#include "main.h"

#include "Items/item.h"


//==================================================================================================
//         TYPE:    Class
//  DESCRIPTION:    Base class for different containers (inventory, bag, chests, barrels, etc.)
//   PARAMETERS:    ........
// RETURN VALUE:    ........
//     COMMENTS:    1) А нужен ли мне отдельный класс для контейнеров? Или же достаточно динамического
//                  массива для этих целей? Вопрос в том, кто ответственен за перемещение предметов
//                  между контейнерами? Владельцы этих контейнеров через свой интерфейс или через
//                  интерфейс, предоставляемый контейнером? Наверное, всё-таки владельцы...
//
//                  2) If I got a container - should I use array or dynamic array? Yes, I have limit,
//                  but creation 99/100 free cells is a waste of space in stack.
//                  On the other hand - smb says, that dynamic allocated space will cause a lot of
//                  delays, when there are a lot of containers and each of them take space, smeared
//                  on heap.
//==================================================================================================
class Container final {

// #################################################################################################
// ######################################  VARIABLES  ##############################################
// #################################################################################################

// ######################################  PUBLIC     ##############################################
public:
    enum class Type {
        UNIVERSAL,
        POTIONS,
        SCROLLS,

        TOTAL
    };

    enum OperationStatus {
        SUCCEED,
        ERR_REACHED_WEIGHT_LIMIT,
        ERR_REACHED_SPACE_LIMIT,
        ERR_INCORRECT_ITEM_TYPE,
        ERR_INVALID_ITEM_POSITION,
        ERR_CELL_IS_EMPTY,

        TOTAL
    };


// ######################################  PROTECTED   #############################################
protected:


// ######################################  PRIVATE    ##############################################
private:
    Type        mb_type             {Type::UNIVERSAL};
    my::String mb_name             {"Container"};

    int         mb_spaceOccupied    {0};
    int         mb_spaceLimit       {100};

    int         mb_weightOccupied   {0};
    int         mb_weightLimit      {100};

    /*
     * In the context of the container - mb_container.size() is amount of CELLS, allocated in the
     * dynamic memory, not items, placed in that container/cells.
     */
    my::DynamicArray<my::SmartPtr<Item>> mb_container;





// #################################################################################################
// ######################################  INTERFACE  ##############################################
// #################################################################################################

// ######################################  PUBLIC     ##############################################
public:
    Container() = default;
    Container(my::String name);
    Container(Type type, int spaceLimit, int weightLimit);


    const my::String& getName() const;


    void sort(Item::Type type);
    void display() const;

    int                         removeItem(int itemPosition, int count);
    int                         putItem(my::SmartPtr<Item>& itemPtr);
    my::SmartPtr<Item>&         extractItem(int itemPosition);
    int                         findItem(Item::Type type);
//    int                         countItem(Item::Type type);



// ######################################  PROTECTED   #############################################
protected:


// ######################################  PRIVATE    ##############################################
private:
};

#endif // CONTAINER_H
