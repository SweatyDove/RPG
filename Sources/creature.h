#ifndef CREATURE_H
#define CREATURE_H

#include "main.h"


class Creature {
public:
    enum class Type {
        PLAYER,
        MONSTER,                // Non-friendly NPC
        TRADER,                 // Friendly NPC

        TOTAL

    };

    Type    mb_type {};
    int     mb_level {};

    explicit Creature(Type type, int level);
};

#endif // CREATURE_H
