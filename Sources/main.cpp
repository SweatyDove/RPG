// #########################################################################################
// ############################  My Role-play Game  ########################################
// #########################################################################################


// ######## Comments:
//
// #1 Add class Mage, Warrior and Hunter, derived from player class with different
//    attack-type and damage. And with different skillset.
//
// #2 Add a thread to exit the game when press exit
//
// #3 Add funny race/spec descriptions
//
// #4 Log-class that will receive log-information and write it in a file when ready


#include "header.h"
#include "cls_monster.h"
#include "cls_player.h"
#include "cls_warrior.h"

#include "cls_item.h"
#include "cls_gold.h"
#include "cls_potion.h"


Player::Race choosePlayerRace();
Player::Spec choosePlayerSpec();
my::String   choosePlayerName();

int main()
{
    // #### Set a seed for rand() and discard first value from it.
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::rand();


    std::cout << "\n################################################################################"
              << "\n###########################      Role Play Game      ###########################"
              << "\n################################################################################"
              << "\n[CONTROL]:'W' - move up; 'S' - move down; 'E' - accept;\n"
              << std::endl;


    clearWorkScreen(WORK_SCREEN_LINES, WORK_SCREEN_COLUMNS);

    Player::Race    playerRace  {choosePlayerRace()};
    Player::Spec    playerSpec  {choosePlayerSpec()};
    my::String      playerName  {choosePlayerName()};

    Warrior* warrior {nullptr};
    Player*  player {nullptr};


    switch (playerSpec) {
    case Player::Spec::WARRIOR:
        warrior = new Warrior;
        player = warrior;
        break;
//    case Player::Spec::MAGE:
//        //Mage mage {player};
//        break;
//    case Player::Spec::HUNTER:
//        //Hunter hunter {player};
//        break;
    default:
        std::cout << "Error, incorrect specialization";
        return 0;
        break;
    }

    player->setRace(playerRace);
    player->setName(playerName);



    std::cout << "Hello " << warrior->getName() << "! Welcome to the HELL...\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << MOVE_CURSOR_ONE_LINE_UP;
    clearWorkScreen(1, WORK_SCREEN_COLUMNS);


    // #### Main cycle
    while (!player->isDead()) {
        player->newDay();

        // ## Create random monster
        Monster monster{};
        std::cout << "\nDay " << player->getTimeLived() << ": "
                  << "you have encountered a " << monster.getName()
                  << " of level "
                  << monster.getLevel() << ".\n";

        player->fightWith(monster);
        if (monster.isDead()) {
            player->getLootFrom(monster);
        }
        else {} // Nothing to do
    }

    std::cout << "You died at level " << player->getLevel() << ".\n\n";
    std::cout << "########  Game Over ########\n\n" << std::endl;


    return 0;            
}










/*
    linuxTerminalMode(!CANONICAL);
    bool inLoop {true};
    int  state {0};
    int  lastState {0};
    bool firstIn {true};

    inLoop = true;
    while (inLoop) {
        if (state != lastState || firstIn) {
            displayRaceMenu(state);
            firstIn = false;
        }
        else {} // Nothing to do

        lastState = state;
        keystroke = linux_kbhit();
        if (keystroke) {
            ch = std::cin.get();
            switch (ch) {
            case 'e': case 'E':
                playerRace = static_cast<Player::Race>(state);
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
    }
    linuxTerminalMode(CANONICAL);


    linuxTerminalMode(!CANONICAL);
    state = lastState = 0;
    firstIn = inLoop = true;

    while (inLoop) {
        if (state != lastState || firstIn) {
            displaySpecMenu(state);
            firstIn = false;
        }
        else {} // Nothing to do

        lastState = state;
        keystroke = linux_kbhit();
        if (keystroke) {
            ch = std::cin.get();
            switch (ch) {
            case 'e': case 'E':
                playerSpec = static_cast<Player::Spec>(state);
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
    }
    linuxTerminalMode(CANONICAL);

 */
