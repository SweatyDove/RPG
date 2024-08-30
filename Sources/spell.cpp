#include "spell.h"


//==================================================================================================
//         TYPE:    Constructor
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
Spell::Spell(std::string name, School school, int baseEffect, int baseCost,
             const std::vector<Attribute>& attributes,
             const std::array<float, static_cast<int>(Attr::Name::TOTAL)>& multipliers) :
    mb_name {name},
    mb_school {school},
    mb_baseEffect {baseEffect},
    mb_baseCost {baseCost},
    mb_attributes {attributes},
    mb_multipliers {multipliers}
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
Spell& Spell::operator=(Spell&& spell) noexcept
{

    // ######## Если НЕ самоприсваивание, то сперва освобождаем ресурсы, которыми владеем.
    // ######## В данном случае в явном виде ресурсами не владеем, а стандартные контейнеры сами
    // ######## передадут то, чем владеют... наверное.
    if (&spell != this) {

        // #### Переменные ниже можно просто скопировать
        mb_name = spell.mb_name;
        mb_school = spell.mb_school;
        mb_baseEffect = spell.mb_baseEffect;
        mb_baseCost = spell.mb_baseCost;
        mb_attributes = spell.mb_attributes;
        mb_multipliers = spell.mb_multipliers;
    }
    else {} // Nothing to do

   return *this;
}




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
    for (int ii {0}; ii < static_cast<int>(Attr::Name::TOTAL); ++ii) {
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
const std::string_view Spell::getName() const
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
//void Spell::setCharacteristics(const std::array<int, Param::TOTAL>& newCharacteristics)
//{
//    mb_characteristics = newCharacteristics;
//}
