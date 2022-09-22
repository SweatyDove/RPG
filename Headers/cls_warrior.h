

#include "header.h"
#include "cls_player.h"

namespace warrior_default {
    const int autoAttackDamage  {10};
    const int heavyBlowDamage   {25};
}

class Warrior : public Player {
private:
    int     mb_autoAttackDamage {};

    int     mb_heavyBlowDamage {};

public:
    // #############  Constructors and Destructors  ##############
    Warrior() = default;
    ~Warrior() override;


    // ##############  Setters and Getters  ################
    void setDamage() override;
    void attack(Monster& monster) const override;
    bool superAttack(Monster& monster) override;

    int getAttackDamage() const override;
    int getSuperAttackDamage() const override;




    // ##############  Other functions  ####################







};
