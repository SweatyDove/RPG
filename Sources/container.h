#ifndef CONTAINER_H
#define CONTAINER_H

#include "main.h"

#include "item.h"


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

    enum ErrorCode {
        OPERATION_SUCCEED,
        REACHED_WEIGHT_LIMIT,
        REACHED_SPACE_LIMIT,
        INCORRECT_ITEM_TYPE,
        INVALID_ITEM_POSITION,
        CELL_IS_EMPTY,

        TOTAL
    };


// ######################################  PROTECTED   #############################################
protected:


// ######################################  PRIVATE    ##############################################
private:
    Type        mb_type             {Type::UNIVERSAL};
    StringClass mb_name             {"Container"};

    int         mb_spaceOccupied    {0};
    int         mb_spaceLimit       {100};

    int         mb_weightOccupied   {0};
    int         mb_weightLimit      {100};

    VectorClass<UniquePtrClass<Item>> mb_container;





// #################################################################################################
// ######################################  INTERFACE  ##############################################
// #################################################################################################

// ######################################  PUBLIC     ##############################################
public:
    Container() = default;
    Container(StringClass name);
    Container(Type type, int spaceLimit, int weightLimit);


    const StringClass& getName();


    void sort(Item::Type type);
    void display() const;

    ErrorCode removeItem(int itemPosition, int count);
    ErrorCode putItem(const UniquePtrClass<Item>& itemPtr);
    const UniquePtrClass<Item>& extractItem(int itemPosition);



// ######################################  PROTECTED   #############################################
protected:


// ######################################  PRIVATE    ##############################################
private:
};

#endif // CONTAINER_H
