#ifndef GOLD_H
#define GOLD_H

#include "main.h"
#include "item.h"

class Gold : public Item {
public:
    Gold(int count);

    ~Gold() override = default;

    const StringClass   getName() const override;
//    const int           getCost() const override;

};

#endif
