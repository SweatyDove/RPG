#ifndef CLS_PLAYER_H
#define CLS_PLAYER_H


#include "header.h"
#include "cls_creature.h"
#include "cls_potion.h"


namespace PlayerDefault {
    const int           LEVEL {1};
    const my::String    NAME {"Stranger"};
//    const Player::Race  RACE {Player::Race::HUMAN};
//    const Player::Spec  SPEC {Player::Spec::WARRIOR};
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
    };
private:
    int             mb_level {PlayerDefault::LEVEL};
    int             mb_currentExp {0};
    int             mb_nextLevelExp {1000};             // Const for now

    my::String      mb_name {PlayerDefault::NAME};
    Race            mb_race {Player::Race::HUMAN};
    Spec            mb_spec {Player::Spec::WARRIOR};

    int             mb_health {PlayerDefault::HEALTH};
    int             mb_stamina {PlayerDefault::STAMINA};
    int             mb_mana {PlayerDefault::MANA};

    int             mb_strength {};
    int             mb_intellect {};
    int             mb_agility {};

    int             mb_damage {10};
    int             mb_timeLived {PlayerDefault::DAY_LIVED};
    int             mb_gold {};
public:

    // ########  Constructors and Destructors  ########
    Player(const my::String& name, Race race, Spec spec);
    ~Player() = default;


    // ########  Setters and Getters  ########
    const my::String&   getName() const;
    int                 getDamage() const;
    int                 getTimeLived() const;
    int                 getLevel() const;
    int                 getCurrentHealth() const;

    //void                setHealth();
    void                setStamina();
    void                setMana();


    // ########  Public Interface  ########
    void                newDay();
    void                attack(Monster& monster) const;
    void                fightWith(Monster& monster);
    int                 addGold(int gold);
    void                drink(Potion& potion);
    void                getLootFrom(Monster& monster);
    void                addHealth(int health);
    void                addStrength(int strength);
    bool                isDead() const;
    void                reduceHealth(int health);

    void                increaseExp(Monster& monster);
    void                levelUp();


};


#endif  // CLS_PLAYER_H
