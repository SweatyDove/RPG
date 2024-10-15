
// #### Item is a base class for any item in the game (e.g. gold, armor, weapon, potion and etc.)
// #########

#ifndef ITEM_H
#define ITEM_H

#include "main.h"
#include "item.h"


class Item {
public:
    enum class Type {
        TRASH,
        GOLD,
        POTION,
//        SCROLL,

        TOTAL
    };
private:
    Type    mb_type;
protected:
    int     mb_count;
    int     mb_weight;

    // ######## Made it protected 'cause I don't want smb to explicitly construct <Item> object.
    Item(Type type, int count, int weight);

public:

    // ##########################  Constructors and Destructors  #######################
    // #################################################################################

    //Item(Type type, int count, int weight);

    ~Item() = default;

    // ##########################  Setters/Getters  ####################################
    // #################################################################################

    int getCount() const;
    int getWeight() const;

    Type        getType() const;
    StringClass  getTypeName() const;


};

#endif  // ITEM_H
