#include "creature.h"





//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    Create specified creature
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
Creature::Creature(Creature::Type type, int level) :
    mb_type {type}, mb_level {level}
{
    // Nothing to do
}


//==================================================================================================
//         TYPE:    Destructor
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
Creature::~Creature()
{

}



//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
int Creature::getLevel() const
{
    return mb_level;
}




//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
//int Creature::getAttribute(Attribute::NameId name, Attribute::ValueType valueType)
//{
//    for (auto attr: mb_attribute) {
//        if (attr.getNameId() == name) {
//           return attr.getValue(valueType);
//        }
//        else {} // Nothing to do
//    }

//    std::cout << "WARNING: there isn't attribute with name '" << name << "'." << std::endl;
//    return -1;
//}


//==================================================================================================
//         TYPE:    Member function
//  DESCRIPTION:    Returns current value of the @name attribute of '-1' in the case of attribute
//                  absence.
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
int Creature::getCurAttr(Attr::NameId name)
{
    for (auto& attr: mb_attribute) {
        if (attr.getNameId() == name) {
           return attr.getValue(Attr::ValueType::CURRENT);
        }
        else {} // Nothing to do
    }

    output.debug("There isn't attribute with name: '%s'.", Attribute::getName(name).cStr());
    return -1;

}


//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
int Creature::getMaxAttr(Attr::NameId name)
{
    for (auto& attr: mb_attribute) {
        if (attr.getNameId() == name) {
           return attr.getValue(Attr::ValueType::MAX);
        }
        else {} // Nothing to do
    }

    output.debug("There isn't attribute with name: '%s'.", Attribute::getName(name).cStr());
    return -1;

}


//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
int Creature::getBaseAttr(Attr::NameId name)
{
    for (auto& attr: mb_attribute) {
        if (attr.getNameId() == name) {
           return attr.getValue(Attr::ValueType::BASE);
        }
        else {} // Nothing to do
    }
    output.debug("There isn't attribute with name: '%s'.", Attribute::getName(name).cStr());
    return -1;

}


//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
int Creature::setCurAttr(Attr::NameId name, int val)
{
    for (auto& attr: mb_attribute) {
        if (attr.getNameId() == name) {
           attr.setValue(Attr::ValueType::CURRENT, val);
           return 0;
        }
        else {} // Nothing to do
    }
    output.debug("There isn't attribute with name: '%s'.", Attribute::getName(name).cStr());
    return 1;
}


//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
int Creature::setMaxAttr(Attr::NameId name, int val)
{
    for (auto& attr: mb_attribute) {
        if (attr.getNameId() == name) {
           attr.setValue(Attr::ValueType::MAX, val);
           return 0;
        }
        else {} // Nothing to do
    }

    output.debug("There isn't attribute with name: '%s'.", Attribute::getName(name).cStr());
    return 1;

}


//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
int Creature::setBaseAttr(Attr::NameId name, int val)
{
    for (auto& attr: mb_attribute) {
        if (attr.getNameId() == name) {
           attr.setValue(Attr::ValueType::BASE, val);
           return 0;
        }
        else {} // Nothing to do
    }

    output.debug("There isn't attribute with name: '%s'.", Attribute::getName(name).cStr());
    return 1;

}



//==================================================================================================
//         TYPE:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//  DESCRIPTION:    Just a 3in1 function for setting attribute
//     COMMENTS:    --------
//==================================================================================================
void Creature::setAllAttr(Attr::NameId name, int baseVal, int maxVal, int curVal)
{
    this->setBaseAttr(name, baseVal);
    this->setMaxAttr(name, maxVal);
    this->setCurAttr(name, curVal);
}


//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
int Creature::modCurAttr(Attr::NameId name, int delta)
{
    for (auto& attr: mb_attribute) {
        if (attr.getNameId() == name) {
           attr.changeValue(Attr::ValueType::CURRENT, delta);
           return 0;
        }
        else {} // Nothing to do
    }

    output.debug("Current creature doesn't have attribute: '%s'. Abort.", Attribute::getName(name).cStr());
    return 1;
}


//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
int Creature::modMaxAttr(Attr::NameId name, int delta)
{
    for (auto& attr: mb_attribute) {
        if (attr.getNameId() == name) {
           attr.changeValue(Attr::ValueType::MAX, delta);
           return 0;
        }
        else {} // Nothing to do
    }

    output.debug("Current creature doesn't have attribute: '%s'. Abort.", Attribute::getName(name).cStr());
    return 1;

}

//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
int Creature::modBaseAttr(Attr::NameId name, int delta)
{
    for (auto& attr: mb_attribute) {
        if (attr.getNameId() == name) {
           attr.changeValue(Attr::ValueType::BASE, delta);
           return 0;
        }
        else {} // Nothing to do
    }

    output.warn("Current creature doesn't have attribute: '%s'. Abort.", Attribute::getName(name).cStr());
    return 1;

}





//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
bool Creature::isDead()
{
    return (this->getCurAttr(Attr::NameId::HEALTH) == 0);
}


//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
void Creature::commitSuicide()
{
    this->setCurAttr(Attr::NameId::HEALTH, 0);
    std::cout << "Creature commited suicide!" << std::endl;
}



//==================================================================================================
//          TYPE:    ........
//   DESCRIPTION:    Check if the @this creature has a specified attribute.
//    PARAMETERS:    ........
//  RETURN VALUE:    ........
// COMMENTS/BUGS:    ........
//==================================================================================================
bool Creature::hasAttr(const StringClass& attrName)
{
    bool retVal {false};

    for (const Attr& attr: mb_attribute) {
        if (attr.getName() == attrName) {
           retVal = true;
           break;
        }
        else {}
    }

    return retVal;

}




//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
const StringClass& Creature::getTypeName() const
{
    return TYPE_NAME[static_cast<int>(mb_type)];
}



//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
void Creature::printAttr()
{
    for (auto& attr: mb_attribute) {

        int curValue {attr.getValue(Attr::ValueType::CURRENT)};
        int maxValue {attr.getValue(Attr::ValueType::MAX)};

        if (curValue != -1 && maxValue != -1) {
            std::cout << std::setw(16) << attr.Attribute::getName(attr.getNameId()) << ":    " << curValue << '/' << maxValue << std::endl;
        }
//        else if (curValue == -1 || maxValue == -1) {
//            assert(false && "Creature can't have current or max attribute in inactive state, only both.");
//        }
        else {} // Nothing to do
    }

}
