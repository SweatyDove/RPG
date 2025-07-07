#include "menu.h"



//==================================================================================================
//         TYPE:    Constructor
//  DESCRIPTION:    ........
//   PARAMETERS:    ........
// RETURN VALUE:    ........
//     COMMENTS:    ........
//==================================================================================================
Menu::Menu(Type type, Creature* creature1, Creature* creature2) :
    mb_type {type},
    mb_subject {creature1},
    mb_object {creature2}
{
    // Nothing to do
}



//==================================================================================================
//         TYPE:    ........
//  DESCRIPTION:    Run exchange menu
//   PARAMETERS:    ........
// RETURN VALUE:    ........
//     COMMENTS:    ........
//==================================================================================================
void Menu::run()
{
    switch(mb_type) {
    case Type::EXCHANGE:
        this->exchange();
        break;
    case Type::UNDEF:
    case Type::TOTAL:
        assert(false && "Incorrect MENU's type! Abort.");
        break;
    }

}




//==================================================================================================
//         TYPE:    ........
//  DESCRIPTION:    ........
//   PARAMETERS:    ........
// RETURN VALUE:    ........
//     COMMENTS:    ........
//==================================================================================================
void Menu::exchange()
{
    bool mainLoop {true};
    enum Choice {
        QUIT,
        SELL,
        BUY,

        TOTAL
    };


    while (mainLoop) {
        std::cout << "\nEXCHANGE MENU"
                  << "\n-------------"
                  << "\n[1] - Sell"
                  << "\n[2] - Buy"
                  << "\n[0] - Quit"
                  << std::endl;


        int choice {};
        std::cout << "Your choice: ";
        std::cin >> choice;

        switch(choice) {
        case Choice::SELL:
            this->sell(mb_subject->getInventory(), mb_object->getInventory());
            break;
        case Choice::BUY:
            this->buy(mb_subject->getInventory(), mb_object->getInventory());
            break;
        case Choice::QUIT:
            mainLoop = false;
            break;
        default:
            std::cout << "Incorrect choice. Please, try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

}




//==================================================================================================
//         TYPE:    ........
//  DESCRIPTION:    ........
//   PARAMETERS:    ........
// RETURN VALUE:    ........
//     COMMENTS:    ........
//==================================================================================================
void Menu::buy(Container& subjectContainer, Container& objectContainer)
{
    objectContainer.display();

    bool mainLoop {true};
    enum Choice {
        QUIT,
        SELL,
        BUY,

        TOTAL
    };


    while (mainLoop) {
        std::cout << "\nWhat items do you want to buy?"
                     "\nEnter list of item's id, separated with commas or 'Q' to quit"
                  << "\n-------------------------------------------------------------"
                  << std::endl;

        my::DynamicArray<int> itemsToBuy {};

        my::String choice {};
        std::cout << "Your choice: ";
        std::cin >> choice;

        if (choice == "Q" || choice == "q") {
            return;
        }
        else {
            // #### Form the list of @itemId to buy
            try {
                itemsToBuy = my::DynamicArray<int> {choice.cStr()};
            }
            catch (const my::DynamicArrayException& exception) {
                std::cout << exception.what() << std::endl;
                continue;
            }

            // #### Buy each item
            for (auto itemId: itemsToBuy) {
                mb_subject->buy(itemId, mb_object);
            }
        }

    }

}



//==================================================================================================
//         TYPE:    ........
//  DESCRIPTION:    ........
//   PARAMETERS:    ........
// RETURN VALUE:    ........
//     COMMENTS:    ........
//==================================================================================================
void Menu::sell(Container& subjectContainer, Container& objectContainer)
{
    mb_subject->displayInventory();
}

