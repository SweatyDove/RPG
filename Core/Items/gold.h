#ifndef GOLD_H
#define GOLD_H

#include "../main.h"
#include "item.h"

class Gold : public Item {
public:
    explicit Gold(int count);

    ~Gold() override = default;

    const my::String   getName() const override;
//    const int           getCost() const override;

};

#endif
