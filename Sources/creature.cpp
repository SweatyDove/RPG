#include "creature.h"


//==================================================================================================
//         NAME:    --------
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
//         NAME:    --------
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
//         NAME:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
int Creature::getAttribute(Attribute::Name name, Attribute::ValueType valueType)
{
    for (auto attr: mb_attribute) {
        if (attr.getName() == name) {
           return attr.getValue(valueType);
        }
        else {} // Nothing to do
    }

    std::cout << "WARNING: there isn't attribute with name '" << name << "'." << std::endl;
    return -1;
}




//==================================================================================================
//         NAME:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
void Creature::changeAttribute(Attribute::Name name, Attribute::ValueType valueType, int delta)
{
    for (auto attr: mb_attribute) {
        if (attr.getName() == name) {
           attr.changeValue(valueType, delta);
        }
        else {} // Nothing to do
    }

    std::cout << "WARNING: current creature doesn't have attribute '" << Attribute::getStringName(name) << "'. Abort." << std::endl;
}


//==================================================================================================
//         NAME:    --------
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
//         NAME:    --------
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
//         NAME:    --------
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
//         NAME:    --------
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
//         NAME:    --------
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
//         NAME:    --------
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
//         NAME:    --------
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
//         NAME:    --------
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
//         NAME:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
bool Creature::isDead() const
{
    return (this->getAttribute("HEALTH", Attribute::ValueType::CURRENT) == 0);
}


//==================================================================================================
//         NAME:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
void Creature::commitSuicide()
{
    int curHealth {this->getAttribute("HEALTH", Attribute::ValueType::CURRENT)};

    this->changeAttribute("HEALTH", Attribute::ValueType::CURRENT, curHealth);
    std::cout << "Creature commited suicide!" << std::endl;
}



