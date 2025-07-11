#ifndef CREATURE_H
#define CREATURE_H

#include "../main.h"
#include "../Items/item.h"
#include "../attribute.h"
#include "../menu.h"
#include "../container.h"


//==================================================================================================
//         TYPE:    Abstract class
//  DESCRIPTION:    Class, that represents some creatures (monsters, traders, players and
//                  etc. It is 'abstract' because has some 'pure virtual functions' and can't be
//                  instantiated.
//   PARAMETERS:    ........
// RETURN VALUE:    ........
//     COMMENTS:    ........
//==================================================================================================
class Creature {

// ######################################  PUBLIC variables  #######################################
// #################################################################################################
public:

//    enum class AttributeType {
//        CURRENT,
//        MAX,

//        TOTAL
//    };

    enum class Type {
        RANDOM,                 // Always = 0

        PLAYER,
        MONSTER,                // Non-friendly NPC
        TRADER,                 // Friendly NPC

        TOTAL

    };
    my::Array<my::String, static_cast<int>(Type::TOTAL)> TYPE_NAME = {
        {
            "RANDOM",
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


// ######################################  PROTECTED variables  ####################################
// #################################################################################################
protected:
    Type    mb_type {};
    int     mb_level {1};


    Container mb_inventory;


//    my::Array<int, static_cast<unsigned int>(Characteristic::TOTAL)> mb_curCharacteristic {-1, -1, -1};
//    my::Array<int, static_cast<unsigned int>(Characteristic::TOTAL)> mb_maxCharacteristic {-1, -1, -1};


//    // #### RESOURCES
//    enum class Resource {
//        HEALTH,
//        STAMINA,
//        MANA,
//        CONCENTRATION,

//        TOTAL
//    };
//    my::Array<int, static_cast<unsigned int>(Resource::TOTAL)> mb_curResource {100, -1, -1, -1};
//    my::Array<int, static_cast<unsigned int>(Resource::TOTAL)> mb_maxResource {100, -1, -1, -1};


    my::DynamicArray<Attribute> mb_attribute = {
            {Attr::NameId::HEALTH, Attr::Type::RESOURCE, 100, 100, 100},

            {Attr::NameId::STAMINA, Attr::Type::RESOURCE, -1, -1, -1},
            {Attr::NameId::MANA, Attr::Type::RESOURCE, -1, -1, -1},
            {Attr::NameId::CONCENTRATION, Attr::Type::RESOURCE, -1, -1, -1},

            {Attr::NameId::STRENGTH, Attr::Type::CHARACTERISTIC, -1, -1, -1},
            {Attr::NameId::INTELLECT, Attr::Type::CHARACTERISTIC, -1, -1, -1},
            {Attr::NameId::AGILITY, Attr::Type::CHARACTERISTIC, -1, -1, -1},
    };





    //int getAttribute(my::String name, Attribute::ValueType valueType) const;
    //void changeAttribute(my::String name, Attribute::ValueType valueType, int delta);

    /*
     * Creature constructor is protected 'cause I don't want smb to create <Creature> explicitly,
     * but at the same time this class is abstract ('cause contains pure virtual function) and can't
     * be created explicitly in any case.
     */
    explicit Creature(Type type, int level = 1);
//    explicit Creature();                              // Delete



// ######################################  PRIVATE variables  ######################################
// #################################################################################################
private:

// ###################################   PUBLIC Interface   ########################################
// #################################################################################################
public:

    /***********************************************************************************************
     * Here I have a lot of similar functions. I could join them into a single one, but in the code
     * I need to set/get/mod attributes very often - and code becomes messy with long and universal
     * functions.
     **********************************************************************************************/
    int     getCurAttr(Attr::NameId name);
    int     getMaxAttr(Attr::NameId name);
    int     getBaseAttr(Attr::NameId name);

    int     setCurAttr(Attr::NameId name, int val);
    int     setMaxAttr(Attr::NameId name, int val);
    int     setBaseAttr(Attr::NameId name, int val);
    void    setAllAttr(Attr::NameId name, int baseVal, int maxVal, int curVal);

    int     modCurAttr(Attr::NameId name, int delta);
    int     modMaxAttr(Attr::NameId name, int delta);
    int     modBaseAttr(Attr::NameId name, int delta);

    bool    hasAttr(const my::String& attrName);


    int                                     getLevel() const;
    const my::String&                      getTypeName() const;
    Type                                    getType() const;


    Container&                              getInventory();

    void    buy(int itemId, Creature& trader);





    virtual                     ~Creature();
    virtual bool                isDead();
    virtual bool                isAlive();
    virtual void                commitSuicide() = 0;            // Pure virtual function
    virtual const my::String&  getName() const = 0;            // Pure virtual function
    virtual void                printAttr();



    friend void printAttrTable(Creature& firstCreature, Creature& secondCreature);

// ###################################   PROTECTED Interface   #####################################
// #################################################################################################
protected:

// ###################################   PRIVATE Interface   #######################################
// #################################################################################################
private:
    int                         putToInventory(const my::SmartPtr<Item>& itemPtr);
    const my::SmartPtr<Item>&   takeFromInventory(int itemPos);
//    int                         findInInventory();

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
    std::cout << "********************************************************************************\n"
              << std::setw(16) << "Attribute"
              << std::setw(16) << "Player"
              << std::setw(16) << "Creature\n" << std::endl;

    for (int ii {0}; ii < static_cast<int>(Attr::NameId::TOTAL); ++ii) {
        Attr::NameId nameId {ii};

        const my::String& attrName {Attr::mb_attrName[ii]};

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

                my::String     firstAttrOut        {};
                my::String     secondAttrOut       {};

                // ######## Output for 1-st creature's attr
                if (firstAttrHasValue) {
                    firstAttrOut << firstCurVal << '/' << firstMaxVal;
                }
                else {
                    firstAttrOut << "........";
                }

                // ######## Output for the 2-nd creature's attr
                if (secondAttrHasValue) {
                    secondAttrOut << secondCurVal << '/' << secondMaxVal;
                }
                else {
                    secondAttrOut << "........";
                }

                std::cout << std::setw(15) << attrName << ':'
                          << std::setw(16) << firstAttrOut
                          << std::setw(16) << secondAttrOut << std::endl;
            }
            else {} // Nothing to do
        }
        else {} // Nothing to do

    } // for-loop

    std::cout << "********************************************************************************"
              << std::endl;

}

#endif // CREATURE_H
