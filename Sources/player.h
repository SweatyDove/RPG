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
private:
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

    enum Skills {
        ALCHEMY,
        CHARISMA,
        LUCK,

        TOTAL
    };


private:
    // ######## GENERAL
    Race            mb_race         {Player::Race::ORC};
    std::string     mb_name         {player_default::NAME};

    Spec            mb_spec         {Player::Spec::WARRIOR};
    int             mb_curExp       {0};
    int             mb_nextLevelExp {1000};             // Const for now
    int             mb_timeLived    {player_default::DAY_LIVED};



    // ######## RAITINGS (CHANCE TO DO SMTH)
    int             mb_dodgeChance  {};
    int             mb_critChance   {};
    int             mb_escapeChance {player_default::ESCAPE_CHANCE};


    // ######## SKILLS
    std::array<int, Skills::TOTAL> mb_skillLevel;



    // ######## INVENTORY
    int             mb_gold         {};








public:

    // ########  Constructors and Destructors  ########
    Player(Race race, std::string name);


    // ########  Setters and Getters  ########
    const std::string&   getName() const;
    Spec                getSpec() const;
    int                 getTimeLived() const;


    //void              setHealth();
    void                setStamina();
    void                setMana();

    void                setName(std::string& name);
    void                setRace(Player::Race race);


    // ########  Virtual methods  #########
    virtual int         getAttackDamage() const = 0;
    virtual int         getSuperAttackDamage() const = 0;
    virtual int         getSuperAttackCost() const = 0;
    //virtual void        setDamage() = 0;
    virtual void        attack(Monster& monster) = 0;
    virtual bool        superAttack(Monster& monster) = 0;

    void                commitSuicide() override;


    // ########  Public Interface  ########

    void                newDay();
    void                fightWith(Monster& monster);
    void                addGold(int gold);
    void                drink(Potion& potion);
    void                getLootFrom(Monster& monster);
    void                addStrength(int strength);


    void                changeHealth(int health) override;
    void                changeStamina(int stamina) override;
    void                changeStrength(int strength) override;


    void                increaseExp(Monster& monster);
    void                levelUp();

    void                getPotion(int potionChance);
    void                getRest();


// System resources
//    my::Log         mb_log      {"battle_log.txt"};

private:
    FightOption                chooseFightOption(Monster& monster);

};


#endif  // CLS_PLAYER_H
