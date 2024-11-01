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
    ArrayClass<StringClass, static_cast<int>(Type::TOTAL)> TYPE_NAME = {
        {
            "PLAYER",
            "MONSTER",
            "TRADER"
        }
    };

    // #### CHARACTERISTICS of the creature
//    enum class Characteristic {
//        STRENGTH,
//        INTELLECT,
//        AGILITY,

//        TOTAL
//    };

private:

    VectorClass<std::unique_ptr<Item>> mb_inventory;

protected:
    // ######## GENERAL
    Type    mb_type {};
    int     mb_level {1};


//    ArrayClass<int, static_cast<unsigned int>(Characteristic::TOTAL)> mb_curCharacteristic {-1, -1, -1};
//    ArrayClass<int, static_cast<unsigned int>(Characteristic::TOTAL)> mb_maxCharacteristic {-1, -1, -1};


//    // #### RESOURCES
//    enum class Resource {
//        HEALTH,
//        STAMINA,
//        MANA,
//        CONCENTRATION,

//        TOTAL
//    };
//    ArrayClass<int, static_cast<unsigned int>(Resource::TOTAL)> mb_curResource {100, -1, -1, -1};
//    ArrayClass<int, static_cast<unsigned int>(Resource::TOTAL)> mb_maxResource {100, -1, -1, -1};


    VectorClass<Attribute> mb_attribute = {
            {Attr::Name::HEALTH, Attr::Type::RESOURCE, 100, 100, 100},
            {Attr::Name::STAMINA, Attr::Type::RESOURCE, -1, -1, -1},
            {Attr::Name::MANA, Attr::Type::RESOURCE, -1, -1, -1},
            {Attr::Name::CONCENTRATION, Attr::Type::RESOURCE, -1, -1, -1},

            {Attr::Name::STRENGTH, Attr::Type::CHARACTERISTIC, -1, -1, -1},
            {Attr::Name::INTELLECT, Attr::Type::CHARACTERISTIC, -1, -1, -1},
            {Attr::Name::AGILITY, Attr::Type::CHARACTERISTIC, -1, -1, -1},
    };





    //int getAttribute(StringClass name, Attribute::ValueType valueType) const;
    //void changeAttribute(StringClass name, Attribute::ValueType valueType, int delta);

    /*
     * Creature constructor is protected 'cause I don't want smb to create <Creature> explicitly,
     * but at the same time this class is abstract ('cause contains pure virtual function) and can't
     * be created explicitly in any case.
     */
    explicit Creature(Type type, int level = 1);

public:
    /***********************************************************************************************
     * Here I have a lot of similar functions. I could join them into a single one, but in the code
     * I need to set/get/mod attributes very often - and code becomes messy with long-universal
     * functions.
     **********************************************************************************************/
    int getCurAttr(Attr::Name name);
    int getMaxAttr(Attr::Name name);
    int getBaseAttr(Attr::Name name);

    void setCurAttr(Attr::Name name, int val);
    void setMaxAttr(Attr::Name name, int val);
    void setBaseAttr(Attr::Name name, int val);
    void setAllAttr(Attr::Name name, int baseVal, int maxVal, int curVal);


    void modCurAttr(Attr::Name name, int delta);
    void modMaxAttr(Attr::Name name, int delta);
    void modBaseAttr(Attr::Name name, int delta);

    virtual                     ~Creature();
    int                         getLevel() const;
    virtual bool                isDead();
    virtual void                commitSuicide() = 0;
    virtual const StringClass&  getName() const = 0;

    const StringClass&        getTypeName() const;

    virtual void            printAttr();



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
