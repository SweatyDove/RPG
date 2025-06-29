
// #### Item is a base class for any item in the game (e.g. gold, armor, weapon, potion and etc.)
// #########

#ifndef ITEM_H
#define ITEM_H

#include "main.h"
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
    Type    mb_type;
protected:
    int     mb_count;
    int     mb_weight;
    int     mb_cost;

    // ######## Made it protected 'cause I don't want smb to explicitly construct <Item> object.
    Item(Type type = Type::TRASH, int count = 1, int weight = 0, int cost = 0);

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


    void    setCount(int newCount);


    virtual const StringClass   getName() const = 0;


};

#endif  // ITEM_H
