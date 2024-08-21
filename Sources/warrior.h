

#include "main.h"
#include "player.h"
#include "spell.h"

namespace warrior_default {
    const int autoAttackDamage  {10};
    const int heavyBlowDamage   {25};
    const int heavyBlowStaminaCost {30};
}



class Warrior : public Player {
private:

    Spell       mb_baseAttack       {"blow", Spell::School::PHYSICAL};
    Spell       mb_specialAttack    {"heavyBlow", Spell::School::PHYSICAL};


//    int     mb_autoAttackDamage         {warrior_default::autoAttackDamage};
    //int     mb_specialAttackDamage      {warrior_default::heavyBlowDamage};
//    int     mb_heavyBlowDamage          {warrior_default::heavyBlowDamage};
//    int     mb_heavyBlowStaminaCost     {warrior_default::heavyBlowStaminaCost};

public:
    // #############  Constructors and Destructors  ##############
    Warrior(Player::Race race, std::string name);
    ~Warrior() override;


    // ##############  Setters and Getters  ################


    void cast(Spell& spell, Creature& target);
//    void setDamage() override;
//    void attack(Monster& monster) override;
//    bool superAttack(Monster& monster) override;
//    int getAttackDamage() const override;
//    int getSuperAttackDamage() const override;
//    int getSuperAttackCost() const override;

    void                        commitSuicide() override;
    Player::FightOption         chooseFightOption(Monster& monster) override;





    // ##############  Other functions  ####################


};
