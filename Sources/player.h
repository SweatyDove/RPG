#ifndef PLAYER_H
#define PLAYER_H


#include "main.h"
#include "potion.h"
#include "creature.h"
#include "gold.h"


// ######## Why am I defining player's default values outside of class player? I don't remember...
namespace player_default {
    const int           LEVEL {1};
    const StringClass   NAME {"Stranger"};
    const int           HEALTH {100};
    const int           MANA {50};
    const int           STAMINA {50};
    const int           CONCENTRATION {50};
    const int           DAY_LIVED {0};
    const int           ESCAPE_CHANCE {66};
}


class Player: public Creature {
protected:
    enum class FightOption {
        FLEE,
        ATTACK,
        SUPER_ATTACK,
        COMMIT_SUICIDE,

        TOTAL
    };
public:
    enum class Race {
        ORC,
        HUMAN,
        ELF,

        MAX_RACE
    };
    enum class Spec {
        WARRIOR,
        MAGE,
        HUNTER,

        MAX_SPEC
    };


protected:

    // ######## RAITINGS (CHANCE TO DO SMTH)
//    enum class Ratings {
//        DODGE_CHANCE,
//        CRIT_CHANCE,
//        ESCAPE_CHANCE,

//        TOTAL
//    };
//    ArrayClass<int, static_cast<int>(Ratings::TOTAL)> mb_rating {0, 0, player_default::ESCAPE_CHANCE};


    ArrayClass<Attribute, 3> mb_ratings = {
        {
            {Attr::Name::DODGE_CHANCE, Attribute::Type::RATING, -1, -1, -1},
            {Attr::Name::CRIT_CHANCE, Attribute::Type::RATING, -1, -1, -1},
            {Attr::Name::ESCAPE_CHANCE, Attribute::Type::RATING, 66, 66, 66},
        }
    };


    ArrayClass<Attribute, 3> mb_skills = {
        {
            {Attr::Name::ALCHEMY, Attribute::Type::SKILL, -1, -1, -1},
            {Attr::Name::CHARISMA, Attribute::Type::SKILL, -1, -1, -1},
            {Attr::Name::LUCK, Attribute::Type::SKILL, -1, -1, -1},
        }
    };


    // ######## SKILLS
//    enum class Skills {
//        ALCHEMY,
//        CHARISMA,
//        LUCK,

//        TOTAL
//    };
//    ArrayClass<int, static_cast<int>(Skills::TOTAL)> mb_skill {0, 0, 0};


private:
    // ######## GENERAL
    Race            mb_race         {Player::Race::ORC};
    Spec            mb_spec         {Player::Spec::WARRIOR};                // Temporary
    StringClass     mb_name         {player_default::NAME};

    int             mb_curExp       {0};
    int             mb_nextLevelExp {1000};             // Const for now
    int             mb_timeLived    {player_default::DAY_LIVED};

    // ######## SKILLS
    //ArrayClass<int, static_cast<int>(Skills::TOTAL)> mb_skillLevel;

    // ######## INVENTORY
    int             mb_gold         {};


public:

    // ########  Constructors and Destructors  ########
    Player(Race race, Spec spec, StringClass name);
    virtual ~Player();


    const StringClass&      getName() const override;
    Spec                    getSpec() const;
    int                     getTimeLived() const;

    void                    setName(StringClass& name);
    void                    setRace(Player::Race race);
    virtual void            attack(Monster& monster) = 0;
    virtual bool            superAttack(Monster& monster) = 0;

    virtual FightOption     chooseFightOption(Monster& monster) = 0;

    void                    commitSuicide() override;
    bool                    metNewDay();
    void                    fightWith(Monster& monster);
    void                    addGold(int gold);
    void                    drink(const Potion& potion);
    void                    getLootFrom(Monster& monster);
    void                    increaseExp(Monster& monster);
    void                    levelUp();
    void                    getPotion(const Potion& potion);
    void                    getRest();

    int                     getCurExp() const;
    int                     getNextLvlExp() const;
    void                    printAttr() const override;





//    void              setHealth();
//    void                setStamina();
//    void                setMana();
//    virtual int         getAttackDamage() const = 0;
//    virtual int         getSuperAttackDamage() const = 0;
//    virtual int         getSuperAttackCost() const = 0;
//    virtual void        setDamage() = 0;
//    void                addStrength(int strength);
//    void                changeHealth(int health) override;
//    void                changeStamina(int stamina) override;
//    void                changeStrength(int strength) override;
// System resources
//    my::Log         mb_log      {"battle_log.txt"};

private:

};


#endif  // CLS_PLAYER_H
