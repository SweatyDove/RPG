#ifndef TRASH_H
#define TRASH_H

#include "main.h"
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
    Type mb_type;
    my::String mb_description {""};



public:
    Trash(Type type, int count, int weight);

    const StringClass getName() const override;


    void setDescription();
    const my::String& getDescription() const;
};



























#endif // TRASH_H
