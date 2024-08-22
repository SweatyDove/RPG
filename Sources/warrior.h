

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

    // ######## BASE attack
    inline const static std::array<float, static_cast<int>(Creature::Characteristics::TOTAL)> mb_baseAttackMultiplier {
        2.0,    // STRENGTH
        0.0,    // INTELLECT
        0.0     // AGILITY
    };
    Spell       mb_baseAttack       {"BASE STRIKE", Spell::School::PHYSICAL, 10, 0, mb_curCharacteristic, mb_baseAttackMultiplier};

    // ######## SPECIAL attack
    inline const static std::array<float, static_cast<int>(Creature::Characteristics::TOTAL)> mb_specialAttackMultiplier {
        5.0,    // STRENGTH
        0.0,    // INTELLECT
        0.0     // AGILITY
    };
    Spell       mb_specialAttack    {"HEAVY BLOW", Spell::School::PHYSICAL, 30, 30, mb_curCharacteristic, mb_specialAttackMultiplier};



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
