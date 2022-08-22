#ifndef CLS_CREATURE_H
#define CLS_CREATURE_H

#include "header.h"

namespace CreatureDefault {
    const int HEALTH {1};
    const int LEVEL {1};

}


class Creature {
public:
    enum class Type {
            CREATURE,
            PLAYER,
            MONSTER,

            MAX_TYPE
        };

// ########  Member Variables ########
private:
    Type    mb_type {Type::CREATURE};
protected:
    int     mb_level {CreatureDefault::LEVEL};

    int     mb_health {CreatureDefault::HEALTH};
    //int     mb_stamina;
    //int     mb_mana;

    //int mb_strength;
    //int mb_intellect;
    //int mb_agility;

    // ######## Constructors and Destructors  ########
public:
    Creature() = default;
    Creature(Type type);
    Creature(Type type, int level);
    Creature(Type type, int level, int health);

    ~Creature() = default;

    // ########  Other member functions  ##########

    bool    isDead() const;
    void    reduceHealth(int health);
    int     getLevel() const;

    int     getCurrentHealth() const;


};

#endif // CLS_CREATURE_H
