
#ifndef POTION_H
#define POTION_H

#include "main.h"
#include "item.h"



class Potion : public Item {
public:
    enum class Type {
        HEALTH,
        STAMINA,
        STRENGTH,
        EXHAUSTED,
        POISON,
//        MAGIC_RESISTANCE,

        TOTAL
    };

    Type    mb_type {};
    static const int mb_defaultPotionChance {100};

private:


protected:
    static constexpr int     defaultWeight {10};

    // ######## Effect of a potion is a integer value, that influences the characteristic, defined
    // ######## by the @mb_type of potion
    int     mb_effect {};
public:
    explicit Potion(int level);
    Potion(Type type, int effect);

    ~Potion() = default;

    StringClass      getName() const;
    int             getEffect() const;

    // ## Create random potion
    void generateRandomPotion(int lvl);
};

#endif  // CLS_ITEM_POTION_H
