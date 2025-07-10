#include "trash.h"


//==================================================================================================
//         TYPE:    Constructor
//  DESCRIPTION:    ........
//   PARAMETERS:    ........
// RETURN VALUE:    ........
//     COMMENTS:    ........
//==================================================================================================
Trash::Trash(Trash::Type trashType, int count, int weight, int cost) :
    Item(Item::Type::TRASH, false, count, weight, cost),
    mb_type {trashType}
{
//    this->setDescription();

}



//==================================================================================================
//         TYPE:    ........
//  DESCRIPTION:    ........
//   PARAMETERS:    ........
// RETURN VALUE:    ........
//     COMMENTS:    ........
//==================================================================================================
const my::String Trash::getName() const
{
    return "trash";
}




////==================================================================================================
////         TYPE:    ........
////  DESCRIPTION:    ........
////   PARAMETERS:    ........
//// RETURN VALUE:    ........
////     COMMENTS:    ........
////==================================================================================================
//const int Trash::getCost() const
//{
//    return mb_cost;
//}



//==================================================================================================
//         TYPE:    Member function
//  DESCRIPTION:    ........
//   PARAMETERS:    ........
// RETURN VALUE:    ........
//     COMMENTS:    Зачем тролю старый носок? Причём один... Лучше этого не знать...
//==================================================================================================
//void Trash::setDescription()
//{
//    if (mb_type == Trash::Type::SOCKS && mb_count == 1) {
//        mb_description = "Why whould a troll need an old sock? Single sock... It is better not to know...";
//    }
//    else {}

//}


//==================================================================================================
//         TYPE:    Member function
//  DESCRIPTION:    ........
//   PARAMETERS:    ........
// RETURN VALUE:    ........
//     COMMENTS:    ........
//==================================================================================================
//const my::String& Trash::getDescription() const
//{
//    return mb_description;
//}








