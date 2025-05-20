#ifndef SCROLL_H
#define SCROLL_H

#include "item.h"


//==================================================================================================
//         TYPE:    Class
//  DESCRIPTION:    Describes different scrolls
//   PARAMETERS:    ........
// RETURN VALUE:    ........
//     COMMENTS:    Can affect attributes: 'Ratings' and 'Skills'.
//==================================================================================================
class Scroll : public Item {
public:
    enum class Type {

        // ## Ratings
        DODGE_CHANCE,
        ESCAPE_CHANCE,
        CRIT_CHANCE,

        // ## Skills
        ALCHEMY,
        CHARISMA,
        LUCK,

        TOTAL
    };

private:
    Type mb_type;

public:
    explicit Scroll(Scroll::Type type);
};

#endif // SCROLL_H
