
// #### Item is a base class for any item in the game (e.g. gold, armor, weapon, potion and etc.)
// #########

#ifndef CLS_ITEM_H
#define CLS_ITEM_H

#include "header.h"


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
    my::String  getTypeName() const;


};

#endif  // CLS_ITEM_H
