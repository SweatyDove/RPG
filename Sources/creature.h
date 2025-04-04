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

    VectorClass<UniquePtrClass<Item>> mb_inventory;

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
            {Attr::NameId::HEALTH, Attr::Type::RESOURCE, 100, 100, 100},
            {Attr::NameId::STAMINA, Attr::Type::RESOURCE, -1, -1, -1},
            {Attr::NameId::MANA, Attr::Type::RESOURCE, -1, -1, -1},
            {Attr::NameId::CONCENTRATION, Attr::Type::RESOURCE, -1, -1, -1},

            {Attr::NameId::STRENGTH, Attr::Type::CHARACTERISTIC, -1, -1, -1},
            {Attr::NameId::INTELLECT, Attr::Type::CHARACTERISTIC, -1, -1, -1},
            {Attr::NameId::AGILITY, Attr::Type::CHARACTERISTIC, -1, -1, -1},
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
     * I need to set/get/mod attributes very often - and code becomes messy with long and universal
     * functions.
     **********************************************************************************************/
    int getCurAttr(Attr::NameId name);
    int getMaxAttr(Attr::NameId name);
    int getBaseAttr(Attr::NameId name);

    void setCurAttr(Attr::NameId name, int val);
    void setMaxAttr(Attr::NameId name, int val);
    void setBaseAttr(Attr::NameId name, int val);
    void setAllAttr(Attr::NameId name, int baseVal, int maxVal, int curVal);


    void modCurAttr(Attr::NameId name, int delta);
    void modMaxAttr(Attr::NameId name, int delta);
    void modBaseAttr(Attr::NameId name, int delta);

    virtual                     ~Creature();
    int                         getLevel() const;
    virtual bool                isDead();
    virtual void                commitSuicide() = 0;
    virtual const StringClass&  getName() const = 0;

    bool hasAttr(const StringClass& attrName);

    const StringClass&        getTypeName() const;

    virtual void            printAttr();


    friend void printAttrTable(Creature& firstCreature, Creature& secondCreature);



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


}; // <Creature>


//==================================================================================================
//          TYPE:    ........
//   DESCRIPTION:    Function prints table of attributes of @firstCreature and @secondCreature
//    PARAMETERS:    ........
//  RETURN VALUE:    ........
// COMMENTS/BUGS:    ........
//==================================================================================================
inline void printAttrTable(Creature& firstCreature, Creature& secondCreature)
{
    // # Прохожу по списку возможных аттрибутов. ПРоверяю, имеется ли он у 1-ого или 2-ого существа.
    // # Если имеется хотя бы у одного, вывожу его параметры.
    for (int ii {0}; ii < static_cast<int>(Attr::NameId::TOTAL); ++ii) {
        Attr::NameId nameId {ii};

        const StringClass& attrName {Attr::mb_attrName[ii]};

        // ## Check if some of the creatures has attribute with @attrName
        if (firstCreature.hasAttr(attrName) || secondCreature.hasAttr(attrName)) {

            int             firstCurVal         {firstCreature.getCurAttr(nameId)};
            int             firstMaxVal         {firstCreature.getMaxAttr(nameId)};
            int             secondCurVal         {secondCreature.getCurAttr(nameId)};
            int             secondMaxVal         {secondCreature.getMaxAttr(nameId)};

            bool            firstAttrHasValue   {(firstCurVal != -1) && (firstMaxVal != -1)};
            bool            secondAttrHasValue  {(secondCurVal != -1) && (secondMaxVal != -1)};

            // #### If one or both creatures have enabled attribute (!= -1), then print it for both
            if (firstAttrHasValue == true || secondAttrHasValue == true) {

                StringClass     firstAttrOut        {};
                StringClass     secondAttrOut       {};

                // ######## Output for 1-st creature's attr
                if (firstAttrHasValue) {
                    firstAttrOut << firstCurVal << '/' << firstMaxVal;
                }
                else {
                    firstAttrOut << "--/--";
                }

                // ######## Output for the 2-nd creature's attr
                if (secondAttrHasValue) {
                    secondAttrOut << secondCurVal << '/' << secondMaxVal;
                }
                else {
                    secondAttrOut << "--/--";
                }

                std::cout << attrName << ":    " << firstAttrOut << "    |    " << secondAttrOut << std::endl;
            }
            else {} // Nothing to do
        }
        else {} // Nothing to do

    } // for-loop

}

#endif // CREATURE_H
