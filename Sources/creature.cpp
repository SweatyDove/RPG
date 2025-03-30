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
//int Creature::getAttribute(Attribute::Name name, Attribute::ValueType valueType)
//{
//    for (auto attr: mb_attribute) {
//        if (attr.getName() == name) {
//           return attr.getValue(valueType);
//        }
//        else {} // Nothing to do
//    }

//    std::cout << "WARNING: there isn't attribute with name '" << name << "'." << std::endl;
//    return -1;
//}


//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
int Creature::getCurAttr(Attr::Name name)
{
    for (auto& attr: mb_attribute) {
        if (attr.getName() == name) {
           return attr.getValue(Attr::ValueType::CURRENT);
        }
        else {} // Nothing to do
    }

    std::cout << "WARNING: there isn't attribute with name '" << Attribute::getStringName(name)
              << "'." << std::endl;
    return -1;

}


//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
int Creature::getMaxAttr(Attr::Name name)
{
    for (auto& attr: mb_attribute) {
        if (attr.getName() == name) {
           return attr.getValue(Attr::ValueType::MAX);
        }
        else {} // Nothing to do
    }

    std::cout << "WARNING: there isn't attribute with name '" << Attribute::getStringName(name)
              << "'." << std::endl;
    return -1;

}


//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
int Creature::getBaseAttr(Attr::Name name)
{
    for (auto& attr: mb_attribute) {
        if (attr.getName() == name) {
           return attr.getValue(Attr::ValueType::BASE);
        }
        else {} // Nothing to do
    }

    std::cout << "WARNING: there isn't attribute with name '" << Attribute::getStringName(name)
              << "'." << std::endl;
    return -1;

}


//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
void Creature::setCurAttr(Attr::Name name, int val)
{
    for (auto& attr: mb_attribute) {
        if (attr.getName() == name) {
           attr.setValue(Attr::ValueType::CURRENT, val);
           return;
        }
        else {} // Nothing to do
    }

    std::cout << "WARNING: there isn't attribute with name '" << Attribute::getStringName(name)
              << "'." << std::endl;
}


//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
void Creature::setMaxAttr(Attr::Name name, int val)
{
    for (auto& attr: mb_attribute) {
        if (attr.getName() == name) {
           attr.setValue(Attr::ValueType::MAX, val);
           return;
        }
        else {} // Nothing to do
    }

    std::cout << "WARNING: there isn't attribute with name '" << Attribute::getStringName(name)
              << "'." << std::endl;
}


//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
void Creature::setBaseAttr(Attr::Name name, int val)
{
    for (auto& attr: mb_attribute) {
        if (attr.getName() == name) {
           attr.setValue(Attr::ValueType::BASE, val);
           return;
        }
        else {} // Nothing to do
    }

    std::cout << "WARNING: there isn't attribute with name '" << Attribute::getStringName(name)
              << "'." << std::endl;
}



//==================================================================================================
//         TYPE:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//  DESCRIPTION:    Just a 3in1 function for setting attribute
//     COMMENTS:    --------
//==================================================================================================
void Creature::setAllAttr(Attr::Name name, int baseVal, int maxVal, int curVal)
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
void Creature::modCurAttr(Attr::Name name, int delta)
{
    for (auto& attr: mb_attribute) {
        if (attr.getName() == name) {
           attr.changeValue(Attr::ValueType::CURRENT, delta);
           return;
        }
        else {} // Nothing to do
    }

    std::cout << "WARNING: current creature doesn't have attribute '" << Attribute::getStringName(name) << "'. Abort." << std::endl;

}


//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
void Creature::modMaxAttr(Attr::Name name, int delta)
{
    for (auto& attr: mb_attribute) {
        if (attr.getName() == name) {
           attr.changeValue(Attr::ValueType::MAX, delta);
           return;
        }
        else {} // Nothing to do
    }

    std::cout << "WARNING: current creature doesn't have attribute '" << Attribute::getStringName(name) << "'. Abort." << std::endl;


}

//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
void Creature::modBaseAttr(Attr::Name name, int delta)
{
    for (auto& attr: mb_attribute) {
        if (attr.getName() == name) {
           attr.changeValue(Attr::ValueType::BASE, delta);
           return;
        }
        else {} // Nothing to do
    }

    std::cout << "WARNING: current creature doesn't have attribute '" << Attribute::getStringName(name) << "'. Abort." << std::endl;


}



//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
//void Creature::changeAttribute(Attribute::Name name, Attribute::ValueType valueType, int delta)
//{
//    for (auto attr: mb_attribute) {
//        if (attr.getName() == name) {
//           attr.changeValue(valueType, delta);
//        }
//        else {} // Nothing to do
//    }

//    std::cout << "WARNING: current creature doesn't have attribute '" << Attribute::getStringName(name) << "'. Abort." << std::endl;
//}


//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
//int Creature::getResource(AttributeType type, Resource name)
//{
//    int resName {static_cast<int>(name)};

//    switch(type) {
//    case AttributeType::MAX:
//        return mb_maxResource[resName];
//    case AttributeType::CURRENT:
//        return mb_curResource[resName];
//    case AttributeType::TOTAL:
//        assert("Invalid resource type!");
//        return -1;
//    }
//}


//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    Function returns attribute value (resource/characteristic and etc)
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
//template <typename AttributeName>
//int Creature::getAttribute(AttributeType type, AttributeName name)
//{
//    // ######## Name of attribute (just a handy iterator)
//    int attributeName {static_cast<int>(name)};

//    // ######## Here we act with different arrays (Resources or Characteristics) depending on the
//    // ######## "type" of <AttributeName>
//    if (std::is_same<AttributeName, Resource>::value == true) {
//        switch(type) {
//        case AttributeType::MAX:
//            return mb_maxResource[attributeName];
//        case AttributeType::CURRENT:
//            return mb_curResource[attributeName];
//        case AttributeType::TOTAL:
//            assert(false && "Invalid attribute type!");
//            return -1;
//        }
//    }
//    else if (std::is_same<AttributeName, Characteristic>::value == true) {
//        switch(type) {
//        case AttributeType::MAX:
//            return mb_maxCharacteristic[attributeName];
//        case AttributeType::CURRENT:
//            return mb_curCharacteristic[attributeName];
//        case AttributeType::TOTAL:
//            assert(false && "Invalid attribute type!");
//            return -1;
//        }
//    }
//    else {
//        assert(false && "Invalid attribute!");
//        return -1;
//    }

//}



//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    This function changes resource in dependence on sign and magnitude of @value
//                  (increaseor or decrease), @type of resource (current or max) and it's @name
//                  (HEALTH, STAMINA, MANA, CONCENTRATION)
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
//template <typename AttributeName>
//void Creature::changeResource(int value, AttributeType type, AttributeName name)
//{
//    int resName {static_cast<int>(name)};
//    int resValue {-1};


//    // ######## Determine resource value depending on it's type
//    switch(type) {
//    case AttributeType::MAX:
//        resValue = mb_maxResource[resName];
//        break;
//    case AttributeType::CURRENT:
//        resValue = mb_curResource[resName];
//        break;
//    case AttributeType::TOTAL:
//        assert("Invalid resource type!");
//        break;
//    }

//    // ######## Do not allow to change value of incative resource
//    if (resValue < 0) {
//        std::cout << "Resourse has a negative value - that means it is inactive and it is not make sense to change it. Abort."
//                  << std::endl;
//        return;
//    }
//    // ######## Set new resource value depending on it's type
//    else {
//        int newResValue {resValue + value};
//        switch(type) {
//        case AttributeType::MAX:
//            if (newResValue < 0) {
//                mb_maxResource[resName] = 0;            // Perhaps it's better to limit min-value of max-resource with value that > 0
//            }
//            else {
//                mb_maxResource[resName] = newResValue;
//            }
//            break;
//        case AttributeType::CURRENT:
//            if (newResValue > mb_maxResource[resName]) {
//                mb_curResource[resName] = mb_maxResource[resName];
//            }
//            else if (newResValue < 0) {
//                mb_curResource[resName] = 0;
//            }
//            else {
//                mb_curResource[resName] = newResValue;
//            }
//            break;
//        case AttributeType::TOTAL:
//            assert("Invalid resource type!");
//            break;
//        }
//    }
//}



//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
//void Creature::changeStrength(int value, Creature::AttributeType type, Creature::Characteristics name)
//{
//    int resName {static_cast<int>(name)};
//    int resValue {-1};


//    // ######## Determine resource value depending on it's type
//    switch(type) {
//    case AttributeType::MAX:
//        resValue = mb_maxCharacteristic[resName];
//        break;
//    case AttributeType::CURRENT:
//        resValue = mb_curCharacteristic[resName];
//        break;
//    case AttributeType::TOTAL:
//        assert("Invalid resource type!");
//        break;
//    }

//    // ######## Do not allow to change value of incative resource
//    if (resValue < 0) {
//        std::cout << "Resourse has a negative value - that means it is inactive and it is not make sense to change it. Abort."
//                  << std::endl;
//        return;
//    }
//    // ######## Set new resource value depending on it's type
//    else {
//        int newResValue {resValue + value};
//        switch(type) {
//        case AttributeType::MAX:
//            if (newResValue < 0) {
//                mb_maxCharacteristic[resName] = 0;            // Perhaps it's better to limit min-value of max-resource with value that > 0
//            }
//            else {
//                mb_maxCharacteristic[resName] = newResValue;
//            }
//            break;
//        case AttributeType::CURRENT:
//            if (newResValue > mb_maxResource[resName]) {
//                mb_curCharacteristic[resName] = mb_maxCharacteristic[resName];
//            }
//            else if (newResValue < 0) {
//                mb_curCharacteristic[resName] = 0;
//            }
//            else {
//                mb_curCharacteristic[resName] = newResValue;
//            }
//            break;
//        case AttributeType::TOTAL:
//            assert("Invalid resource type!");
//            break;
//        }
//    }
//}






//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
//int Creature::getCurrentHealth() const
//{
//    return mb_curHealth;
//}


//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
//int Creature::getCurrentStamina() const
//{
//    return mb_curStamina;
//}


//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    Function changes health of creature by specified value @health. This value can
//                  be negative!
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    Virtual function - it has a little more options in derived classes
//==================================================================================================
//void Creature::changeHealth(int health)
//{
//    assert(mb_curHealth >= 0 && "Negative health means inactive characteristic, but creatures always have hp!");

//    int newHealth = mb_curHealth + health;
//    if (newHealth > mb_maxHealth) {
//        mb_curHealth = mb_maxHealth;
//    }
//    else if (newHealth < 0) {
//        mb_curHealth = 0;
//    }
//    else {
//        mb_curHealth = newHealth;
//    }

//}


//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    Function changes stamina of creature by specified value @stamina. If creature's
//                  @mb_curStamina == -1, it means that this characteristic is inactive for
//                  instance of the class, derived from <Creature>
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
//void Creature::changeStamina(int stamina)
//{
//    if (mb_curStamina == -1) {
//        std::cout << "Stamina is inactive for this creature. Nothing to do" << std::endl;
//        return;
//    }
//    else {} // Nothing to do


//    int newStamina = mb_curStamina + stamina;
//    if (newStamina > mb_maxStamina) {
//        mb_curStamina = mb_maxStamina;
//    }
//    else if (newStamina < 0) {
//        mb_curStamina = 0;
//    }
//    else {
//        mb_curStamina = newStamina;
//    }
//}








//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
bool Creature::isDead()
{
    return (this->getCurAttr(Attr::Name::HEALTH) == 0);
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
    this->setCurAttr(Attr::Name::HEALTH, 0);
    std::cout << "Creature commited suicide!" << std::endl;
}



//==================================================================================================
//          TYPE:    ........
//   DESCRIPTION:    Check if the @this creature has a specified attribute.
//    PARAMETERS:    ........
//  RETURN VALUE:    ........
// COMMENTS/BUGS:    ........
//==================================================================================================
bool Creature::hasAttr(const StringClass& attrName) const
{
    bool retVal {false};

    int size {mb_attribute.size()};
    for (int ii {0}; ii < size; ++ii) {
        if (mb_attribute[ii].)
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
            std::cout << std::setw(16) << attr.Attribute::getStringName(attr.getName()) << ":    " << curValue << '/' << maxValue << std::endl;
        }
//        else if (curValue == -1 || maxValue == -1) {
//            assert(false && "Creature can't have current or max attribute in inactive state, only both.");
//        }
        else {} // Nothing to do
    }

}
