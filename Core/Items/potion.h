
#ifndef POTION_H
#define POTION_H

#include "../main.h"
#include "item.h"



//==================================================================================================
//         TYPE:    Class
//  DESCRIPTION:    Describes different potions. Can affect attributes: 'Base', 'Resources'
//                  and 'Characteristics'.
//   PARAMETERS:    ........
// RETURN VALUE:    ........
//     COMMENTS:    1)  Remove EXHAUSTED and POISON potions and replace them with '0' or 'negative'
//                      effects.
//==================================================================================================
class Potion : public Item {
public:


    enum class Type {
        // ## Base
        HEALTH,

        // ## Resources
        STAMINA,
//        MANA,
//        CONCENTRATION,

        // ## Characteristics
        STRENGTH,
//        INTELLECT,
//        AGILITY,

        TOTAL
    };

    Type                mb_type {};
//    int                 mb_level {};
    static const int    mb_defaultPotionChance {100};                                               /* Move to other class/place? */

private:


protected:
    int                     mb_effect {};                                                           // Effect of a potion is a integer value, that influences the characteristic, defined the @mb_type of potion.
    static constexpr int    defaultWeight {10};                                                     /* Make it depending on @mb_effect */

public:
    explicit Potion(int level);
    Potion(Potion::Type type, int effect);
    ~Potion() = default;



    const my::String   getName() const override;


    int                     getEffect() const;

    void            generateRandomPotion(int lvl);                                                  // Generate random potion
    static int      generateRandomEffect(Potion::Type, int lvl);
    Potion::Type    generateRandomType();
    int             generateCost();


};

#endif  // CLS_ITEM_POTION_H
