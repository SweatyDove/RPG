#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include "main.h"


//==================================================================================================
//         TYPE:    Class
//  DESCRIPTION:    Describes creature's attribute.
//   PARAMETERS:    ........
// RETURN VALUE:    ........
//     COMMENTS:    1) Add an 'empty' NameID/Name to fill different arrays with if it is needed, 'cause
//                  the usage of HEALTH as filler confuses a little.
//==================================================================================================
class Attribute {
public:


    // # Enumeration of all various attributes for their convenient usage in arrays
    enum class NameId {

        // ## Base
        HEALTH,

        // ## Resources
        STAMINA,
        MANA,
        CONCENTRATION,

        // ## Characteristics
        STRENGTH,
        INTELLECT,
        AGILITY,

        // ## Ratings
        DODGE_CHANCE,
        ESCAPE_CHANCE,
        CRIT_CHANCE,

        // ## Skills
        ALCHEMY,
        CHARISMA,
        LUCK,

        TOTAL
    };
    // # Names of all attributes presented as strings to use them while printing
    inline static const my::Array<my::String, static_cast<unsigned int>(NameId::TOTAL)> mb_attrName = {
        {
            // # Base
            "HEALTH",

            // # Resources
            "STAMINA",
            "MANA",
            "CONCENTRATION",

            // # Characteristics
            "STRENGTH",
            "INTELLECT",
            "AGILITY",

            // # Ratings
            "DODGE_CHANCE",
            "ESCAPE_CHANCE",
            "CRIT_CHANCE",

            // # Skills
            "ALCHEMY",
            "CHARISMA",
            "LUCK",
        }
    };

    // # Types of attributes
    enum class Type {
        RESOURCE,
        CHARACTERISTIC,
        RATING,
        SKILL,

        TOTAL
    };

    // # Types of values of attributes
    enum class ValueType {
        BASE,                   // Base value - need for level up
        CURRENT,                // Current value of attribute - 'current HEALTH' for example
        MAX,                    // Max value of attribute - 'max HEALTH' for example

        TOTAL
    };


private:


    NameId mb_nameId {};                // Name (identifier) of the attribute
    Type mb_type {};                    // Attribute type (or class)

    int mb_baseValue {};
    int mb_curValue {};
    int mb_maxValue {};



public:
    // # Constructors and destructors
    Attribute() = default;
    Attribute(NameId nameId, Type type, int baseValue, int curValue, int maxValue);

    // # Overloaded operators



    // # Interface
    NameId                      getNameId() const;
    Type                        getType() const;
    void                        changeValue(ValueType valueType, int delta);
    int                         getValue(ValueType valueType) const;
    void                        setValue(ValueType valueType, int value);


    const my::String&          getName() const;

    static const my::String&   getName(NameId);

};

std::ostream& operator<<(std::ostream& out, Attribute& attr);
std::ostream& operator<<(std::ostream& out, const Attribute& attr);


// # Alias for the convenient usage
using Attr = Attribute;

#endif // ATTRIBUTE_H
