#ifndef CREATURE_H
#define CREATURE_H

#include "main.h"
#include "item.h"


class Creature {
public:
    enum class Type {
        PLAYER,
        MONSTER,                // Non-friendly NPC
        TRADER,                 // Friendly NPC

        TOTAL

    };

private:

    std::vector<std::unique_ptr<Item>> mb_inventory;

protected:
    // ######## GENERAL
    Type    mb_type {};
    int     mb_level {1};

    // #### CHARACTERISTICS
        int             mb_curStrength    {-1};
        int             mb_maxStrength    {-1};
    //    int             mb_intellect    {-1};
    //    int             mb_agility      {-1};



    // #### RESOURCES
    int     mb_curHealth        {100};
    int     mb_maxHealth        {100};
    int     mb_curStamina       {-1};
    int     mb_maxStamina       {-1};
//    int     mb_curMana          {-1};
//    int     mb_maxMana              {-1};
//    int     mb_curConcentration {-1};
//    int     mb_maxConcentration     {-1};



    /*
     * Creature constructor is protected 'cause I don't want smb to create <Creature> explicitly,
     * but at the same time this class is abstract ('cause contains pure virtual function) and can't
     * be created explicitly in any case.
     */
    explicit Creature(Type type, int level = 1);

public:

    virtual             ~Creature();

    int                 getLevel() const;
    int                 getCurrentHealth() const;
    int                 getCurrentStamina() const;

    virtual void        changeHealth(int health);
    virtual void        changeStamina(int stamina);

    virtual void        changeStrength(int strength);

    virtual bool        isDead() const;
    virtual void        commitSuicide() = 0;

};

#endif // CREATURE_H
