
#ifndef CLS_POTION_H
#define CLS_POTION_H

#include "header.h"
#include "cls_item.h"


class Potion : public Item {
public:
    enum class Type {
        HEALTH,
        STRENGTH,
        EXHAUSTED,
        POISON,
//        MAGIC_RESISTANCE,

        MAX_TYPE
    };

    Type    mb_type {};
protected:
    static constexpr int     defaultWeight {10};
    int     mb_effect {};
public:
    Potion();
    Potion(Type type, int effect);
    ~Potion() = default;

    my::String getName() const;
    int         getEffect() const;

    // ## Create random potion
    void createRandomPotion(int lvl);
};

#endif  // CLS_ITEM_POTION_H
