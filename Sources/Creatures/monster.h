
#ifndef MONSTER_H
#define MONSTER_H

#include "../main.h"
#include "player.h"
#include "../Items/item.h"
//#include "potion.h"
//#include "gold.h"
#include "creature.h"
#include "../spell.h"



/*
 * 1 - Maybe create a formula of monster's health and calculate current health with its usage (I mean
 *     specify this formula explixitly somewhere in the header)
 *
 * 2 - Add a function, that set baseHealth, maxHealth and current health altogether
 */

class Monster: public Creature {
public:
    enum class Type {
        SKELETON,
        ZOMBIE,
        GHOST,

        TOTAL
    };

    my::Array<int, static_cast<int>(Monster::Type::TOTAL)> mb_baseHealth {

            10,     // SKELETON
            30,     // ZOMBIE
            20      // GHOST

    };

    my::Array<my::String, static_cast<unsigned int>(Type::TOTAL)> mb_name {
        {
            {"SKELETON"},
            {"ZOMBIE"},
            {"GHOST"}
        }
    };

    struct MonsterBase {
        Type    type;
        int     health;
        int     damage;
    };

    my::Array<MonsterBase, static_cast<std::size_t>(Type::TOTAL)> base {
        {
            {Type::SKELETON, 10, 10},
            {Type::ZOMBIE, 5, 30},
            {Type::GHOST, 15, 20},
        }
    };

    // ######## BASE attack multipliers
    inline static my::Array<float, static_cast<int>(Attr::NameId::TOTAL)> mb_baseAttackMultiplier {0};

    //Monster::Type getRandomType();

private:

    // ## SKELETON
    //static const int SKELETON_CHANCE_APPEAR { 50 };
//    static const int SKELETON_BASE_HEALTH   { 10 };
//    static const int SKELETON_BASE_DAMAGE   { 10 };

//    // ## ZOMBIE
//    //static const int ZOMBIE_CHANCE_APPEAR   { 30 };
//    static const int ZOMBIE_BASE_HEALTH     { 30 };
//    static const int ZOMBIE_BASE_DAMAGE     { 5 };

//    // ## GHOST
//    //static const int GHOST_CHANCE_APPEAR   { 20 };
//    static const int GHOST_BASE_HEALTH     { 10 };
//    static const int GHOST_BASE_DAMAGE     { 20 };


private:
    Type                        mb_type {};
//    int                         mb_level {1};
//    int                         mb_currentHealth {};
//    int                         mb_damage {};
    Spell                       mb_baseAttack;

public:
    // I generate several things of different types, but all things have the same BASE type..
    // Can't use reference 'casue componets of std::vector (and other containers) must be ASSIGNABLE
    my::DynamicArray<my::SmartPtr<Item>>     mb_loot;

    // #########  Constructors and Destructors  #############

    // ######## Create random monster
    Monster();
    ~Monster() override;



    // ######## Create monster of the specific @type and @level
    //Monster(Type type, int level);


    //~Monster() = default;

    // ##########  Setters and Getters  #####################

//    int             setDamage(Type type, int level) const;
    void            setHealth(Type type, int level);

    int             getDamage() const;

    const my::String&     getName() const override;

    int             getLevel() const;
    Type            getType() const;
    int             getCurrentHealth() const;


    // ##########  Other Functions  ##########################
    //bool                    isDead() const override;
    void                    attack(Player& player) const;
    void                    reduceHealth(int health);
    void                    commitSuicide() override;
    void                    generateLoot();

    void                    printAttr() override;



    static int getRandomMonsterLevel();
    static Type getRandomMonsterType();
};


#endif  // CLS_MONSTER_H





//    struct BaseStats {
//        Type type;
//        int chance;
//        int health;
//        int damage;
//    };

//    Monster createRandomMonster() const
//    {
//        // ## Get random monster type
//        Type type { static_cast<Type>(getRandomNumber(0, static_cast<unsigned int>(Type::MAX_TYPE) - 1)) };
//        int health {};
//        int level {getRandomNumber(1, 10)};
//        int damage {};

//        // ## Get current monster stats
//        switch (type) {
//        case Type::SKELETON:
//            health = 50 + 10 * level;
//            damage = 10 + level * 2;
//            break;
//        case Type::ZOMBIE:
//            health = 100 + 20 * level;
//            damage = 10 + level;
//            break;
//        case Type::GHOST:
//            health = 10 * level;
//            damage = level * 2 + 20;
//            break;
//        case Type::MAX_TYPE:
//            assert("[Error]: invalid monster type");
//            break;
//        //default:
//            //break;
//        }

//        return {type, level, health, damage};

//    }


//    static const Monster& Monster::getDefaultMonster(Monster::Type type)
//    {

//        // #### Array of default monsters (with their stats)
//        static const my::Array<Monster, static_cast<std::size_t>(Type::MAX_TYPE)> defaultMonster {
//            {
//                      { Type::SKELETON, SKELETON_BASE_HEALTH, SKELETON_BASE_DAMAGE},
//                      { Type::ZOMBIE, ZOMBIE_BASE_HEALTH, ZOMBIE_BASE_DAMAGE},
//                      { Type::GHOST, GHOST_BASE_HEALTH, GHOST_BASE_DAMAGE},
//            }
//        };

//        return defaultMonster.at(static_cast<std::size_t>(type));
//    }
