#ifndef PLAYER_H
#define PLAYER_H


#include "main.h"
#include "potion.h"


// ######## Why am I defining player's default values outside of class player? I don't remember...
namespace player_default {
    const int           LEVEL {1};
    const my::String    NAME {"Stranger"};
    const int           HEALTH {100};
    const int           MANA {50};
    const int           STAMINA {50};
    const int           CONCENTRATION {50};
    const int           DAY_LIVED {0};
    const int           ESCAPE_CHANCE {66};
}


class Player {
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

protected:
    int             mb_currentHealth    {player_default::HEALTH};


private:
    // ######## GENERAL
    my::String      mb_name         {player_default::NAME};
    Race            mb_race         {Player::Race::ORC};
    Spec            mb_spec         {Player::Spec::WARRIOR};
    int             mb_level        {player_default::LEVEL};
    int             mb_currentExp   {0};
    int             mb_nextLevelExp {1000};             // Const for now
    int             mb_timeLived    {player_default::DAY_LIVED};


    // #### RESOURCES
    int             mb_maxHealth            {player_default::HEALTH};
    int             mb_currentStamina       {player_default::STAMINA};
    int             mb_maxStamina           {player_default::STAMINA};
    int             mb_currentMana          {player_default::MANA};
    int             mb_maxMana              {player_default::MANA};
    int             mb_currentConcentration {player_default::CONCENTRATION};
    int             mb_maxConcentration     {player_default::CONCENTRATION};


    // ######## RAITINGS (CHANCE TO DO SMTH)
    int             mb_dodgeChance  {};
    int             mb_critChance   {};
    int             mb_escapeChance {player_default::ESCAPE_CHANCE};


    // ######## SKILLS
    std::array<int, Skills::TOTAL> mb_skillLevel;



    // ######## INVENTORY
    int             mb_gold         {};






protected:
    // #### General characteristics
    int             mb_intellect    {};
    int             mb_agility      {};
    int             mb_strength     {};

public:
    // System resources
    my::Log         mb_log      {"battle_log.txt"};



    // ########  Constructors and Destructors  ########
    Player() = default;
    virtual ~Player();


    // ########  Setters and Getters  ########
    const my::String&   getName() const;
    Spec                getSpec() const;
    int                 getTimeLived() const;
    int                 getLevel() const;
    int                 getCurrentHealth() const;
    int                 getCurrentStamina() const;

    //void                setHealth();
    void                setStamina();
    void                setMana();

    void                setName(my::String& name);
    void                setRace(Player::Race race);


    // ########  Virtual methods  #########
    virtual int         getAttackDamage() const = 0;
    virtual int         getSuperAttackDamage() const = 0;
    virtual int         getSuperAttackCost() const = 0;
    virtual void        setDamage() = 0;
    virtual void        attack(Monster& monster) = 0;
    virtual bool        superAttack(Monster& monster) = 0;
    virtual void        commitSuicide();


    // ########  Public Interface  ########

    void                newDay();
    void                fightWith(Monster& monster);
    void                 addGold(int gold);
    void                drink(Potion& potion);
    void                getLootFrom(Monster& monster);
    void                addHealth(int health);
    void                addStamina(int stamina);
    void                addStrength(int strength);
    bool                isDead() const;
    void                reduceHealth(int health);

    void                increaseExp(Monster& monster);
    void                levelUp();

    void                reduceStamina(int stamina);
    void                getPotion(int potionChance);



private:
    FightOption                chooseFightOption(Monster& monster);

};


#endif  // CLS_PLAYER_H
