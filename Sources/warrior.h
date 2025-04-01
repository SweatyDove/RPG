

#include "main.h"
#include "player.h"
#include "spell.h"
#include "monster.h"

namespace warrior_default {
    const int autoAttackDamage  {10};
    const int heavyBlowDamage   {25};
    const int heavyBlowStaminaCost {30};
}



class Warrior : public Player {
private:

    // ######## BASE attack
    inline static ArrayClass<float, static_cast<int>(Attr::NameId::TOTAL)> mb_baseAttackMultiplier {
        {
            0.0,    // HEALTH
            0.0,    // STAMINA
            0.0,    // MANA
            0.0,    // CONCENTRATION

            2.0,    // STRENGTH
            0.0,    // INTELLECT
            0.0,    // AGILITY

            0.0,    // DODGE_CHANCE
            0.0,    // ESCAPE_CHANCE
            0.0,    // CRIT_CHANCE

            0.0,    // ALCHEMY
            0.0,    // CHARISMA
            0.0,    // LUCK
        }
    };
    Spell       mb_baseAttack       {mb_attribute, mb_baseAttackMultiplier, "BASE STRIKE", Spell::School::PHYSICAL, 10, 0};

    // ######## SPECIAL attack
    inline static ArrayClass<float, static_cast<int>(Attr::NameId::TOTAL)> mb_specialAttackMultiplier {
        {
            0.0,    // HEALTH
            0.0,    // STAMINA
            0.0,    // MANA
            0.0,    // CONCENTRATION

            5.0,    // STRENGTH
            0.0,    // INTELLECT
            0.0,    // AGILITY

            0.0,    // DODGE_CHANCE
            0.0,    // ESCAPE_CHANCE
            0.0,    // CRIT_CHANCE

            0.0,    // ALCHEMY
            0.0,    // CHARISMA
            0.0,    // LUCK
        }
    };
    Spell       mb_specialAttack    {mb_attribute, mb_specialAttackMultiplier, "HEAVY BLOW", Spell::School::PHYSICAL, 30, 30};

public:
    // #############  Constructors and Destructors  ##############
    Warrior(Player::Race race, Player::Spec spec, StringClass name);
    ~Warrior() override;

    void                        commitSuicide() override;
    Player::FightOption         chooseFightOption(Monster& monster) override;
    void                        attack(Monster& monster) override;
    bool                        superAttack(Monster& monster) override;
    void                        cast(Spell& spell, Creature& target);


//    void setDamage() override;
//    int getAttackDamage() const override;
//    int getSuperAttackDamage() const override;
//    int getSuperAttackCost() const override;

};
