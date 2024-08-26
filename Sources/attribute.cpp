#include "attribute.h"





//==================================================================================================
//         NAME:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
Attribute::Attribute(std::string name, Type type, int curValue, int maxValue):
    mb_name {name},
    mb_type {type},
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
string_view Attribute::getName() const
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
void Attribute::changeValue(ValueType valueType, int delta)
{
    int newValue {};

    switch(valueType) {
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







