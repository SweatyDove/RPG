#include "spell.h"


//==================================================================================================
//         TYPE:    Constructor
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
Spell::Spell(const VectorClass<Attribute>& attributes,
             const ArrayClass<float, static_cast<int>(Attr::NameId::TOTAL)>& multipliers,
             StringClass name,
             School school,
             int baseEffect,
             int baseCost
             ):
    mb_attributes {attributes},
    mb_multipliers {multipliers},
    mb_name {name},
    mb_school {school},
    mb_baseEffect {baseEffect},
    mb_baseCost {baseCost}
{
    // Nothing to do
}


//==================================================================================================
//         TYPE:    Move assignment operator
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    В отличии от move constructor, здесь нужно освобождать ресурс, которым владеет
//                  левый операнд. Однако, наверное, не обязательно вызывать деструктор для правого
//                  операнда...
//==================================================================================================
//Spell& Spell::operator=(Spell&& spell) noexcept
//{
//    /*
//     * There is an compile issue while trying to assign spell.mb_attribute to mb_attribute,
//     * because this member variable has const qualifier. And there is several solutions:
//     * 1 - REMOVE const qualifier (not sure that this is good idea, 'cause it breaks semantics)
//     * 2 - DESTROY *this object and construct new object with spell's member vatiables (may cost a
//     *     lot of system resources in a future and need to allocate memory in the heap)
//     * 3 - Use std::move to move "unmovable" (doesn't work)
//     */
//    if (&spell != this) {
//        mb_name = spell.mb_name;
//        mb_school = spell.mb_school;
//        mb_baseEffect = spell.mb_baseEffect;
//        mb_baseCost = spell.mb_baseCost;
//        mb_attributes = spell.mb_attributes;
//        mb_multipliers = spell.mb_multipliers;
//    }
//    else {} // Nothing to do

//   return *this;
//}




//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
int Spell::getCost(int level)
{

    return (mb_baseCost == 0) ? 0 : mb_baseCost + (level - 1) * 5;
}


//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    Calculate effect of the spell, depending on creature's characteristics and they
//                  multipliers. Because @mb_characteristics is a const reference - no need to always
//                  update it
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
int Spell::getEffect(int level) const
{
    // ######## 0-th step
    int effect {mb_baseEffect * level};

    // ######## 1-st step, where a spell effect is calculated via multiplication creature's
    // ######## @characteristics and spell's @multipliers
    for (int ii {0}; ii < mb_attributes.size(); ++ii) {
        effect += mb_attributes[ii].getValue(Attr::ValueType::CURRENT) * mb_multipliers[ii];
    }

    return effect;
}


//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
const StringClass& Spell::getName() const
{
    return mb_name;
}

//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    Update array with creature's characteristics
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
void Spell::setName(StringClass name)
{
    mb_name = name;
}



//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    Update array with creature's characteristics
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
void Spell::setSchool(School school)
{
    mb_school = school;
}



//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    Update array with creature's characteristics
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
void Spell::setBaseEffect(int effect)
{
    mb_baseEffect = effect;
}



//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    Update array with creature's characteristics
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
void Spell::setBaseCost(int cost)
{
    mb_baseCost = cost;
}



//==================================================================================================
//         TYPE:    --------
//  DESCRIPTION:    Update array with creature's characteristics
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
//void Spell::setCharacteristics(const ArrayClass<int, Param::TOTAL>& newCharacteristics)
//{
//    mb_characteristics = newCharacteristics;
//}
