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
            this->sell();
            break;
        case Choice::BUY:
            this->buy();
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
void Menu::buy()
{
    mb_object->displayInventory();

    bool mainLoop {true};
    enum Choice {
        QUIT,
        SELL,
        BUY,

        TOTAL
    };


    while (mainLoop) {
        std::cout << "\nWhat item do you want to buy? Enter an number or 'Q' to quit"
                  << "\n------------------------------------------------------------"
                  << std::endl;


        StringClass choice {};
        std::cout << "Your choice: ";
        std::cin >> choice;

        if (choice == 'Q') {
            return;
        }
        else {
            /*
             * Тут надо бы что-то придумать. Или добавить в динамический массив конструктор, который
             * формирует массив <типов> из строки. Но тогда придётся включать заголовочный файл
             * "my_string.h" - а это circular dependency. То ли отдельную функцию где-то написать.
             */
            my::DynamicArray<int> itemsToBuy {choice};
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
void Menu::sell()
{
    mb_subject->displayInventory();
}

