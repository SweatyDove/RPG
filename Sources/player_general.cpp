#include "header.h"
#include "cls_player.h"

static void displayRaceMenu(int state);
static void displaySpecMenu(int state);



//==============================================================================
// WHAT: Global function
//  WHY: Choose the player's race.
//==============================================================================
Player::Race choosePlayerRace()
{
    bool inLoop {true};
    int  state {0};
    int  lastState {0};
    bool firstIn {true};
    int  keystroke {};
    char ch {'\0'};
    Player::Race race {};

    //linuxTerminalMode(!CANONICAL);

    inLoop = true;
    while (inLoop) {
        // ## Have to display menu only if in the first time or last state is not equal to the current
        if (state != lastState || firstIn) {
            displayRaceMenu(state);
            firstIn = false;
        }
        else {} // Nothing to do

        lastState = state;
        //keystroke = linux_kbhit();
        if (keystroke) {
            ch = std::cin.get();

            switch (ch) {
            case 'e': case 'E':
                race = static_cast<Player::Race>(state);
                inLoop = false;
                break;
            case 's': case 'S':
                state = (state == static_cast<int>(Player::Race::MAX_RACE) - 1) ? 0 : state + 1;
                break;
            case 'w': case 'W':
                state = (state == 0) ? static_cast<int>(Player::Race::MAX_RACE) - 1 : state - 1;
                break;
            default:
                break;
            }
        }
        else {} // Nothing to do
    }

    //linuxTerminalMode(CANONICAL);
    //clearWorkScreen(WORK_SCREEN_LINES, WORK_SCREEN_COLUMNS);

    return race;
}

//==============================================================================
// WHAT: Global function
//  WHY: Choose the player's specialization
//==============================================================================
Player::Spec choosePlayerSpec()
{
    bool inLoop {true};
    int  state {0};
    int  lastState {0};
    bool firstIn {true};
    int keystroke {};
    char ch {'\0'};
    Player::Spec spec {};

    //linuxTerminalMode(!CANONICAL);
    while (inLoop) {
        if (state != lastState || firstIn) {
            displaySpecMenu(state);
            firstIn = false;
        }
        else {} // Nothing to do

        lastState = state;
        //keystroke = linux_kbhit();
        if (keystroke) {
            ch = std::cin.get();
            switch (ch) {
            case 'e': case 'E':
                spec = static_cast<Player::Spec>(state);
                inLoop = false;
                break;
            case 's': case 'S':
                state = (state == static_cast<int>(Player::Spec::MAX_SPEC) - 1) ? 0 : state + 1;
                break;
            case 'w': case 'W':
                state = (state == 0) ? static_cast<int>(Player::Spec::MAX_SPEC) - 1 : state - 1;
                break;
            default:
                break;
            }
        }
        else {} // Nothing to do

    }
    //linuxTerminalMode(CANONICAL);
    //clearWorkScreen(WORK_SCREEN_LINES, WORK_SCREEN_COLUMNS);


    return spec;
}

my::String choosePlayerName()
{
    my::String name {""};

    std::cout << "#### What is your name: ";
    std::cin >> name;

    //std::cout << MOVE_CURSOR_ONE_LINE_UP;
    //clearWorkScreen(1, WORK_SCREEN_COLUMNS);

    return name;
}



// #### Display the race menu
// ####
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
                  << "\n[NOTE]: DIDN'T RELEASE YET!                        "
                  << "\n                                                   "
                  << std::endl;
        break;
    case Player::Race::HUMAN:
        std::cout << "\n           Orc           "
                  << "\n########## Human ########"
                  << "\n           Elf           "
                  << "\n                         "
                  << "\n                         "
                  << "\n                         "
                  << "\n[NOTE]: Just a simple human being                  "
                  << "\n                                                   "
                  << std::endl;
        break;
    case Player::Race::ELF:
        std::cout << "\n           Orc           "
                  << "\n           Human         "
                  << "\n########## Elf ##########"
                  << "\n                         "
                  << "\n                         "
                  << "\n                         "
                  << "\n[NOTE]: DIDN'T RELEASE YET!                           "
                  << "\n                                                      "
                  << std::endl;
        break;
    case Player::Race::MAX_RACE:
        break;
    //default:
        //break;
    }

//    while (raceMenuSize-- > 0) {
//        std::cout << MOVE_CURSOR_ONE_LINE_UP;
//    }

    return;
}


// #### Display the specialization menu
// ####
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
                  << "\n[NOTE]: Strong melee fighter, who is not distinguished"
                  << "\n        neither intelligence nor dexterity.           "
                  << std::endl;
        break;
    case Player::Spec::MAGE:
        std::cout << "\n           Warrior           "
                  << "\n########## Mage #############"
                  << "\n           Hunter            "
                  << "\n                             "
                  << "\n                             "
                  << "\n                             "
                  << "\n[NOTE]: DIDN'T RELEASE YET!                           "
                  << "\n                                                      "
                  << std::endl;
        break;
    case Player::Spec::HUNTER:
        std::cout << "\n           Warrior           "
                  << "\n           Mage              "
                  << "\n########## Hunter ###########"
                  << "\n                             "
                  << "\n                             "
                  << "\n                             "
                  << "\n[NOTE]: DIDN'T RELEASE YET!                           "
                  << "\n                                                      "
                  << std::endl;
        break;
    case Player::Spec::MAX_SPEC:
        break;
    //default:
        //break;
    }

//    while (specMenuSize-- > 0) {
//        std::cout << MOVE_CURSOR_ONE_LINE_UP;
//    }

    return;
}


