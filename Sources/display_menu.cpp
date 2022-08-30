#include "header.h"
#include "cls_player.h"

void displayRaceMenu(int currentState)
{
    int raceMenuSize {11};
    Player::Race race {static_cast<Player::Race>(currentState)};

    std::cout << "#### Choose your race:\n\n";

    // ## Display race menu
    switch(race) {
    case Player::Race::ORC:
        std::cout << "\n########## Orc ##########"
                  << "\n           Human         "
                  << "\n           Elf           "
                  << "\n                         "
                  << "\n                         "
                  << "\n                         "
                  << "\n[NOTE]: * Orc race description *                   "
                  << "\n        * Orc race description *                   "
                  << std::endl;
        break;
    case Player::Race::HUMAN:
        std::cout << "\n           Orc           "
                  << "\n########## Human ########"
                  << "\n           Elf           "
                  << "\n                         "
                  << "\n                         "
                  << "\n                         "
                  << "\n[NOTE]: * Human race description *                 "
                  << "\n        * Human race description *                 "
                  << std::endl;
        break;
    case Player::Race::ELF:
        std::cout << "\n           Orc           "
                  << "\n           Human         "
                  << "\n########## Elf ##########"
                  << "\n                         "
                  << "\n                         "
                  << "\n                         "
                  << "\n[NOTE]: * Elf race description *                   "
                  << "\n        * Elf race description *                   "
                  << std::endl;
        break;
    case Player::Race::MAX_RACE:
        break;
    //default:
        //break;
    }

    while (raceMenuSize-- > 0) {
        std::cout << MOVE_CURSOR_ONE_LINE_UP;
    }

    return;
}


void displaySpecMenu(int state)
{
    int specMenuSize {11};
    Player::Spec spec {static_cast<Player::Spec>(state)};

    std::cout << "#### Choose your specialization:\n\n";

    // ## Display spec menu
    switch(spec) {
    case Player::Spec::WARRIOR:
        std::cout << "\n########## Warrior ##########"
                  << "\n           Mage              "
                  << "\n           Hunter            "
                  << "\n                             "
                  << "\n                             "
                  << "\n                             "
                  << "\n[NOTE]: * Warrior spec description *               "
                  << "\n        * Warrior spec description *               "
                  << std::endl;
        break;
    case Player::Spec::MAGE:
        std::cout << "\n           Warrior           "
                  << "\n########## Mage #############"
                  << "\n           Hunter            "
                  << "\n                             "
                  << "\n                             "
                  << "\n                             "
                  << "\n[NOTE]: * Mage spec description *                  "
                  << "\n        * Mage spec description *                  "
                  << std::endl;
        break;
    case Player::Spec::HUNTER:
        std::cout << "\n           Warrior           "
                  << "\n           Mage              "
                  << "\n########## Hunter ###########"
                  << "\n                             "
                  << "\n                             "
                  << "\n                             "
                  << "\n[NOTE]: * Hunter spec description *                "
                  << "\n        * Hunter spec description *                "
                  << std::endl;
        break;
    case Player::Spec::MAX_SPEC:
        break;
    //default:
        //break;
    }

    while (specMenuSize-- > 0) {
        std::cout << MOVE_CURSOR_ONE_LINE_UP;
    }

    return;
}
