#ifndef CREATURE_H
#define CREATURE_H

#include "main.h"
#include "item.h"
#include "attribute.h"


class Creature {
public:

//    enum class AttributeType {
//        CURRENT,
//        MAX,

//        TOTAL
//    };

    enum class Type {
        PLAYER,
        MONSTER,                // Non-friendly NPC
        TRADER,                 // Friendly NPC

        TOTAL

    };

    // #### CHARACTERISTICS of the creature
    enum class Characteristic {
        STRENGTH,
        INTELLECT,
        AGILITY,

        TOTAL
    };

private:

    std::vector<std::unique_ptr<Item>> mb_inventory;

protected:
    // ######## GENERAL
    Type    mb_type {};
    int     mb_level {1};


    std::array<int, static_cast<unsigned int>(Characteristic::TOTAL)> mb_curCharacteristic {-1, -1, -1};
    std::array<int, static_cast<unsigned int>(Characteristic::TOTAL)> mb_maxCharacteristic {-1, -1, -1};


    // #### RESOURCES
    enum class Resource {
        HEALTH,
        STAMINA,
        MANA,
        CONCENTRATION,

        TOTAL
    };
    std::array<int, static_cast<unsigned int>(Resource::TOTAL)> mb_curResource {100, -1, -1, -1};
    std::array<int, static_cast<unsigned int>(Resource::TOTAL)> mb_maxResource {100, -1, -1, -1};


    std::vector<Attribute> mb_attribute = {
        {"HEALTH", Attribute::Type::RESOURCE, 100, 100},
        {"STAMINA", Attribute::Type::RESOURCE, -1, -1},
        {"MANA", Attribute::Type::RESOURCE, -1, -1},
        {"CONCENTRATION", Attribute::Type::RESOURCE, -1, -1},

        {"STRENGTH", Attribute::Type::CHARACTERISTIC, -1, -1},
        {"INTELLECT", Attribute::Type::CHARACTERISTIC, -1, -1},
        {"AGILITY", Attribute::Type::CHARACTERISTIC, -1, -1},
    };



    int getAttribute(std::string name, Attribute::ValueType valueType) const;
    void changeAttribute(std::string name, Attribute::ValueType valueType, int delta);

    /*
     * Creature constructor is protected 'cause I don't want smb to create <Creature> explicitly,
     * but at the same time this class is abstract ('cause contains pure virtual function) and can't
     * be created explicitly in any case.
     */
    explicit Creature(Type type, int level = 1);

public:

    virtual                     ~Creature();
    int                         getLevel() const;
    virtual bool                isDead() const;
    virtual void                commitSuicide() = 0;
    virtual const std::string&  getName() const = 0;


//    template <typename AttributeName>
//    void changeResource(int value, AttributeType type, AttributeName name);
//    template <typename AttributeName>
//    int getAttribute(AttributeType type, AttributeName name);
//    int                         getResource(AttributeType type, Resource name);
//    int                         getCurrentHealth() const;
//    int                         getCurrentStamina() const;
//    virtual void                changeHealth(int health);
//    virtual void                changeStamina(int stamina);
//    virtual void                changeStrength(int strength);


};

#endif // CREATURE_H
