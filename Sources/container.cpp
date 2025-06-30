#include "container.h"


//==================================================================================================
//         TYPE:    Constructor
//  DESCRIPTION:    ........
//   PARAMETERS:    ........
// RETURN VALUE:    ........
//     COMMENTS:    ........
//==================================================================================================
Container::Container(Container::Type type, int limit) :
    mb_type {type},
    mb_limit {limit}
{
    // Nothing to do
}


//==================================================================================================
//         TYPE:    Public member function
//  DESCRIPTION:    ........
//   PARAMETERS:    ........
// RETURN VALUE:    ........
//     COMMENTS:    ........
//==================================================================================================
int Container::putItem(const UniquePtrClass<Item>& itemPtr)
{

}
