#ifndef PLAYER_H
#define PLAYER_H


#include "main.h"
#include "potion.h"
#include "creature.h"


// ######## Why am I defining player's default values outside of class player? I don't remember...
namespace player_default {
    const int           LEVEL {1};
    const std::string   NAME {"Stranger"};
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
//    std::array<int, static_cast<int>(Ratings::TOTAL)> mb_rating {0, 0, player_default::ESCAPE_CHANCE};


    std::array<Attribute, 3> mb_ratings = {
        {
            {Attr::Name::DODGE_CHANCE, Attribute::Type::RATING, -1, -1, -1},
            {Attr::Name::CRIT_CHANCE, Attribute::Type::RATING, -1, -1, -1},
            {Attr::Name::ESCAPE_CHANCE, Attribute::Type::RATING, 66, 66, 66}
        }
    };


    std::array<Attribute, 3> mb_skills = {
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
//    std::array<int, static_cast<int>(Skills::TOTAL)> mb_skill {0, 0, 0};


private:
    // ######## GENERAL
    Race            mb_race         {Player::Race::ORC};
    std::string     mb_name         {player_default::NAME};

    Spec            mb_spec         {Player::Spec::WARRIOR};
    int             mb_curExp       {0};
    int             mb_nextLevelExp {1000};             // Const for now
    int             mb_timeLived    {player_default::DAY_LIVED};





    // ######## SKILLS
    //std::array<int, static_cast<int>(Skills::TOTAL)> mb_skillLevel;



    // ######## INVENTORY
    int             mb_gold         {};








public:

    // ########  Constructors and Destructors  ########
    Player(Race race, std::string name);


    // ########  Setters and Getters  ########
    const std::string&  getName() const override;
    Spec                getSpec() const;
    int                 getTimeLived() const;


    //void              setHealth();
//    void                setStamina();
//    void                setMana();

    void                setName(std::string& name);
    void                setRace(Player::Race race);


    // ########  Virtual methods  #########
    virtual int         getAttackDamage() const = 0;


    virtual int         getSuperAttackDamage() const = 0;
    virtual int         getSuperAttackCost() const = 0;
    //virtual void        setDamage() = 0;
    virtual void        attack(Monster& monster) = 0;
    virtual bool        superAttack(Monster& monster) = 0;

    virtual FightOption         chooseFightOption(Monster& monster) = 0;



    // ########  Public Interface  ########
    void                commitSuicide() override;
    void                newDay();
    void                fightWith(Monster& monster);
    void                addGold(int gold);
    void                drink(Potion& potion);
    void                getLootFrom(Monster& monster);
    void                increaseExp(Monster& monster);
    void                levelUp();
    void                getPotion(int potionChance);
    void                getRest();


//    void                addStrength(int strength);
//    void                changeHealth(int health) override;
//    void                changeStamina(int stamina) override;
//    void                changeStrength(int strength) override;




// System resources
//    my::Log         mb_log      {"battle_log.txt"};

private:

};


#endif  // CLS_PLAYER_H
