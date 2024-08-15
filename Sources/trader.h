//##################################################################################################
// DESCRIPTION:     This class describes traders (generally - friendly npc)
//##################################################################################################

#ifndef TRADER_H
#define TRADER_H

#include "main.h"
#include "creature.h"

class Trader: public Creature {
public:
    Trader(int level);
};

#endif // TRADER_H
