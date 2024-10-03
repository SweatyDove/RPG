#include "attribute.h"





//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
Attribute::Attribute(Attribute::Name name, Type type, int baseValue, int curValue, int maxValue):
    mb_name {name},
    mb_type {type},
    mb_baseValue {baseValue},
    mb_curValue {curValue},
    mb_maxValue {maxValue}
{
    // Nothing to do

}

//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
Attribute::Type Attribute::getType() const
{
    return mb_type;
}

//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
Attribute::Name Attribute::getName() const
{
    return mb_name;
}


//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
const StringClass& Attribute::getStringName(Attribute::Name name)
{
    return mb_attrName[static_cast<unsigned int>(name)];
}



//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
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
    case ValueType::CUR_AND_MAX:
        newValue = mb_maxValue + delta;
        mb_curValue = mb_maxValue = (newValue < 0) ? 0 : newValue;
    case ValueType::TOTAL:
        assert(false && "Incorrect Value Type");
        break;
    }

}



//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
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
//         TYPE:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
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






