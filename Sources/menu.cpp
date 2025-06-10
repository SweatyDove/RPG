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
    bool mainLoop {true};


    while (mainLoop) {
        std::cout << "\n[1] - Sell"
                  << "\n[2] - Buy"
                  << "\n[0] - Quit"
                  << std::endl;

        enum Choice {
            QUIT,
            SELL,
            BUY
        };

        int choice {};
        std::cout << "Your choice: ";
        std::cin >> choice;

        switch(choice) {
        case Choice::SELL:
            mb_subject->displayInventory();
            break;
        case Choice::BUY:
            mb_object->displayInventory();
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














