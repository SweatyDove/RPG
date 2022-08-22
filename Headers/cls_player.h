#ifndef CLS_PLAYER_H
#define CLS_PLAYER_H


#include "header.h"
#include "cls_creature.h"
#include "cls_potion.h"


class Player : public Creature {
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
    my::String     mb_name {};
    Race            mb_race {};
    Spec            mb_spec {};

    int             mb_damage {};
    int             mb_timeLived {};
    int             mb_gold {};
public:

    // ########  Constructors and Destructors  ########
    Player(my::String name, Race race, Spec spec);
    ~Player() = default;


    // ########  Setters and Getters  ########
    const my::String&  getName() const;
    int                 getDamage() const;
    int                 getTimeLived() const;


    // ########  Public Interface  ########
    void                newDay();
    void                attack(Monster& monster) const;
    void                fightWith(Monster& monster);
    int                 addGold(int gold);
    void                drink(Potion& potion);
    void                getLootFrom(Monster& monster);
    void                addHealth(int health);
    void                addStrength(int strength);


};


#endif  // CLS_PLAYER_H
