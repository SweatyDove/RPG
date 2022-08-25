

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
    Warrior(my::String& playerName, Player::Race playerRace) :
        Player(playerName, playerRace, Player::Spec::WARRIOR)
    {
        mb_autoAttackDamage = warrior_default::autoAttackDamage + mb_strength * 2;
    }


    // ##############  Setters and Getters  ################
    void setDamage() override;
    void attack(Monster& monster) const override;
    void superAttack(Monster& monster) const override;




    // ##############  Other functions  ####################







};
