#ifndef CLS_PLAYER_H
#define CLS_PLAYER_H


#include "header.h"
#include "cls_potion.h"

namespace player_default {
    const int           LEVEL {1};
    const my::String    NAME {"Stranger"};
    const int           HEALTH {100};
    const int           MANA {50};
    const int           STAMINA {50};
    const int           DAY_LIVED {0};
}


class Player {
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
private:
    int             mb_level        {player_default::LEVEL};
    int             mb_currentExp   {0};
    int             mb_nextLevelExp {1000};             // Const for now

    my::String      mb_name         {player_default::NAME};
    Race            mb_race         {Player::Race::ORC};
    Spec            mb_spec         {Player::Spec::WARRIOR};

    // #### Player's resourses

    int             mb_currentHealth    {player_default::HEALTH};
    int             mb_maxHealth        {};
    int             mb_currentStamina   {player_default::STAMINA};
    int             mb_maxStamina       {};
    int             mb_currentMana      {player_default::MANA};
    int             mb_maxMana          {};

    // #### General characteristics

    int             mb_intellect    {};
    int             mb_agility      {};

    // #### Raintings (chances to do smth)

    int             mb_dodgeChance  {};
    int             mb_critChance   {};

    int             mb_timeLived    {player_default::DAY_LIVED};
    int             mb_gold         {};

protected:
    int             mb_strength {};

public:

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
    virtual void        setDamage() = 0;
    virtual void        attack(Monster& monster) const = 0;
    virtual bool        superAttack(Monster& monster) = 0;


    // ########  Public Interface  ########

    void                newDay();
    void                fightWith(Monster& monster);
    int                 addGold(int gold);
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



private:
    void                displayFightMenu(int state, Monster& monster);

};


#endif  // CLS_PLAYER_H
