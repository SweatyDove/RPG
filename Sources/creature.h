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
    // ######## GENERAL
    Type    mb_type {};
    int     mb_level {1};

    // #### RESOURCES
    int     mb_currentHealth        {100};
    int     mb_maxHealth            {100};
    int     mb_currentStamina       {-1};
    int     mb_maxStamina           {-1};
//    int     mb_currentMana          {-1};
//    int     mb_maxMana              {-1};
//    int     mb_currentConcentration {-1};
//    int     mb_maxConcentration     {-1};

    std::vector<std::unique_ptr<Item>> mb_inventory;

protected:

    explicit Creature(Type type, int level = 1);                        // Protected 'cause I don't want smb to create <Creature> explicitly

public:
    int                 getLevel() const;
    int                 getCurrentHealth() const;
    int                 getCurrentStamina() const;

    virtual void        changeHealth(int health);
    void                changeStamina(int stamina);

    virtual bool        isDead() const;
    virtual void        commitSuicide();

};

#endif // CREATURE_H
