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
        std::cout << "\n[1] - Display yours inventory;"
                  << "\n[2] - Display target inventory;"
                  << "\n[0] - Quit;"
                  << std::endl;

        char choice {};
        std::cout << "Your choice: ";
        std::cin >> choice;

        switch(choice) {
        case '1':
            for (auto& itemPtr: mb_subject->getInventory()) {
                std::cout << itemPtr->getTypeName() << "    " << itemPtr->getCount() << std::endl;
            }
            break;
        case '2':
            for (auto& itemPtr: mb_object->getInventory()) {
                std::cout << itemPtr->getTypeName() << "    " << itemPtr->getCount() << std::endl;
            }
            break;
        case '0':
            mainLoop = false;
            break;
        default:
            std::cout << "Incorrect choice. Please, try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

}














