
#ifndef GOLD_H
#define GOLD_H

#include "main.h"
#include "item.h"

class Gold : public Item {
public:
    Gold(int count);

    ~Gold() = default;
};

#endif
