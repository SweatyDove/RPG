
// #### Item is a base class for any item in the game (e.g. gold, armor, weapon, potion and etc.)
// #########

#ifndef ITEM_H
#define ITEM_H

#include "../main.h"
#include "item.h"

//
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
    Type    mb_type {Type::TRASH};
protected:
    bool    mb_stackable {false};
    int     mb_count {1};
    int     mb_weight {1};
    int     mb_cost {0};

    // ######## Made it protected 'cause I don't want smb to explicitly construct <Item> object.
    Item() = default;
    explicit Item(Type type, bool stackable = false, int count = 1, int weight = 0, int cost = 0);

public:

    // ##########################  Constructors and Destructors  #######################
    // #################################################################################

    //Item(Type type, int count, int weight);

    virtual ~Item() = default;

    // ##########################  Setters/Getters  ####################################
    // #################################################################################

    Type      getType() const;
    int       getCount() const;
    int       getWeight() const;
    int       getCost() const;

    bool      isStackable() const;

    void    setCount(int newCount);                             // Need to make virtual


    virtual const my::String   getName() const = 0;


};

#endif  // ITEM_H
