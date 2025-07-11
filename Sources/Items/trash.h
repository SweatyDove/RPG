#ifndef TRASH_H
#define TRASH_H

#include "../main.h"
#include "item.h"
#include "my_string.h"


//==================================================================================================
//         TYPE:    Class
//  DESCRIPTION:    Class, that desribes 'different' useless things.
//   PARAMETERS:    ........
// RETURN VALUE:    ........
//     COMMENTS:    ........
//==================================================================================================
class Trash: public Item {
public:
    enum class Type {
        SOCKS,

        TOTAL
    };


private:
    Type            mb_type;
    my::String      mb_description {""};



public:
    Trash(Type type, int count, int weight, int cost);



    void                setDescription();
    const my::String&   getDescription() const;

    const my::String   getName() const override;
//    const int           getCost() const override;

};



























#endif // TRASH_H
