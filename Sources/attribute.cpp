#include "attribute.h"





//==================================================================================================
//         TYPE:    Constructor
//  DESCRIPTION:    ........
//   PARAMETERS:    ........
// RETURN VALUE:    ........
//     COMMENTS:    ........
//==================================================================================================
Attribute::Attribute(Attribute::NameId nameId, Type type, int baseValue, int curValue, int maxValue):
    mb_nameId {nameId},
    mb_type {type},
    mb_baseValue {baseValue},
    mb_curValue {curValue},
    mb_maxValue {maxValue}
{
    // Nothing to do

}

//==================================================================================================
//         TYPE:    Getter
//  DESCRIPTION:    Returns the <Type> of the @this attribute
//   PARAMETERS:    ........
// RETURN VALUE:    ........
//     COMMENTS:    ........
//==================================================================================================
Attribute::Type Attribute::getType() const
{
    return mb_type;
}

//==================================================================================================
//         TYPE:    Getter
//  DESCRIPTION:    Returns the name of the attribute as a string.
//   PARAMETERS:    ........
// RETURN VALUE:    ........
//     COMMENTS:    ........
//==================================================================================================
const StringClass& Attribute::getName() const
{
    const StringClass& debug = mb_attrName[static_cast<unsigned int>(mb_nameId)];
    return mb_attrName[static_cast<unsigned int>(mb_nameId)];
}



//==================================================================================================
//         TYPE:    Static function
//  DESCRIPTION:    Returns the name of the attribute as a string, depending on attribute's @nameId
//   PARAMETERS:    ........
// RETURN VALUE:    ........
//     COMMENTS:    ........
//==================================================================================================
const StringClass& Attr::getName(NameId nameId)
{
    return Attr::mb_attrName[static_cast<int>(nameId)];

}





//==================================================================================================
//         TYPE:    Getter
//  DESCRIPTION:    Returns the identifier of the attribute
//   PARAMETERS:    ........
// RETURN VALUE:    ........
//     COMMENTS:    ........
//==================================================================================================
Attribute::NameId Attribute::getNameId() const
{
    return mb_nameId;
}



//==================================================================================================
//         TYPE:    ........
//  DESCRIPTION:    Change the attribute's value depending on the value's type.
//   PARAMETERS:    ........
// RETURN VALUE:    ........
//     COMMENTS:    BASE value can be 0 or higher;
//                  CURRENT value lies in the range from 0 to MAX value;
//                  MAX value can be 0 or higher;
//==================================================================================================
void Attribute::changeValue(ValueType valueType, int delta)
{
    int newValue {};

    switch(valueType) {
    case ValueType::BASE:
        newValue = mb_baseValue + delta;
        mb_baseValue = (newValue < 0) ? 0 : newValue;
        break;
    case ValueType::CURRENT:
        newValue = mb_curValue + delta;
        mb_curValue = (newValue > mb_maxValue) ? mb_maxValue : ((newValue > 0) ? newValue : 0);
        break;
    case ValueType::MAX:
        newValue = mb_maxValue + delta;
        mb_maxValue = (newValue < 0) ? 0 : newValue;
        break;
    case ValueType::TOTAL:
        assert(false && "Incorrect Value Type");
        break;
    }


}



//==================================================================================================
//         TYPE:    ........
//  DESCRIPTION:    Return attribute's value depending on the value's type.
//   PARAMETERS:    ........
// RETURN VALUE:    ........
//     COMMENTS:    ........
//==================================================================================================
int Attribute::getValue(ValueType valueType) const
{
    int value {};

    switch(valueType) {
    case ValueType::BASE:
        value = mb_baseValue;
        break;
    case ValueType::CURRENT:
        value = mb_curValue;
        break;
    case ValueType::MAX:
        value = mb_maxValue;
        break;
    case ValueType::TOTAL:
        assert(false && "Incorrect Value Type");
        break;
    }

    return value;
}



//==================================================================================================
//         TYPE:    ........
//  DESCRIPTION:    Set the value depending on its type.
//   PARAMETERS:    ........
// RETURN VALUE:    ........
//     COMMENTS:    ........
//==================================================================================================
void Attribute::setValue(ValueType valueType, int value)
{
    switch(valueType) {
    case ValueType::BASE:
        mb_baseValue = value;
        break;
    case ValueType::CURRENT:
        assert(value <= mb_maxValue && "Can't set current value higher than it's max value. Abort.");
        mb_curValue = value;
        break;
    case ValueType::MAX:
        mb_maxValue = value;
        break;
    case ValueType::TOTAL:
        assert(false && "Incorrect Value Type");
        break;
    }

}






