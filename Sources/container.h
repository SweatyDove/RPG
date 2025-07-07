#ifndef CONTAINER_H
#define CONTAINER_H

#include "main.h"

#include "Items/item.h"


//==================================================================================================
//         TYPE:    Class
//  DESCRIPTION:    Base class for different containers (inventory, bag, chests, barrels, etc.)
//   PARAMETERS:    ........
// RETURN VALUE:    ........
//     COMMENTS:    А нужен ли мне отдельный класс для контейнеров? Или же достаточно динамического
//                  массива для этих целей? Вопрос в том, кто ответственен за перемещение предметов
//                  между контейнерами? Владельцы этих контейнеров через свой интерфейс или через
//                  интерфейс, предоставляемый контейнером? Наверное, всё-таки владельцы...
//
//                  If I got a container - should I use array or dynamic array? Yes, I have limit,
//                  but creation 99/100 free cells is a waste of space in stack.
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

    my::DynamicArray<my::SmartPtr<Item>> mb_container;





// #################################################################################################
// ######################################  INTERFACE  ##############################################
// #################################################################################################

// ######################################  PUBLIC     ##############################################
public:
    Container() = default;
    Container(my::String name);
    Container(Type type, int spaceLimit, int weightLimit);


    const my::String& getName();


    void sort(Item::Type type);
    void display() const;

    OperationStatus             removeItem(int itemPosition, int count);
    OperationStatus             putItem(const my::SmartPtr<Item>& itemPtr);
    const my::SmartPtr<Item>&   extractItem(int itemPosition);
    int                         findItem(Item::Type type);
//    int                         countItem(Item::Type type);



// ######################################  PROTECTED   #############################################
protected:


// ######################################  PRIVATE    ##############################################
private:
};

#endif // CONTAINER_H
