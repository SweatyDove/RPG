#include "attribute.h"





//==================================================================================================
//         NAME:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
Attribute::Attribute(std::string name, Type type, int baseValue, int curValue, int maxValue):
    mb_name {name},
    mb_type {type},
    mb_baseValue {baseValue},
    mb_curValue {curValue},
    mb_maxValue {maxValue}
{
    // Nothing to do

}

//==================================================================================================
//         NAME:    --------
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
//         NAME:    --------
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
//         NAME:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
std::string_view Attribute::getStringName(Name name) const
{
    return mb_attrName[static_cast<int>(name)];
}



//==================================================================================================
//         NAME:    --------
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
//         NAME:    --------
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
//         NAME:    --------
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






