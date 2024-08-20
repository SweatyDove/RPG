// #################################################################################################
// ############################  My Role-play Game  ################################################
// #################################################################################################


/***************************************************************************************************
 * COMMENTS:
 * 1 - Add classes Mage, Warrior and Hunter, derived from player class with different
 *     attack-type and damage. And with different skillset.
 *
 * 2 - Add a thread to exit the game when press exit
 *
 * 3 - Add funny race/spec descriptions
 *
 * 4 - Initialize a RANDOM monster explicitly
 *
 * 5 - Add a separate function for displaying information (with dif colors and etc)
 *
 * 6 - Add an opportunity to meet not only a monster, but also a TRADER or smb else...
 *
 * 7 - Add a <Creature> class and derive player/monster/friendly-npc
 *
 * 8 - Good potion effect depends on lucky
 *
 * 9 - Work with inheritance more accurately (including class and member inheritance) - you have to
 * know why each member is not private
 *
 * 10 - Add static unsigned long variable to store id. Maybe it is worth to create vector, that
 * stores ALL instances addresses and iterate them by id...
 *
 * 11 - Realize situations, when characteristics could be higher, than it's max value
 *
 * 12 - Maybe need to add template for functions (changeHealth(), changeMana() and etc)
 *
 *
 *
 *
 * QUESTIONS:
 *
 * 1 - Do I need to use list-initialization of class member variables if I initialize them in
 * constructor?
 *
 **************************************************************************************************/



#include "main.h"
#include "monster.h"
#include "player.h"
#include "warrior.h"

#include "item.h"
#include "gold.h"
#include "potion.h"


#include <string>

Player::Race choosePlayerRace();
Player::Spec choosePlayerSpec();
my::String   choosePlayerName();

HANDLE hConsole;

int main()
{

    //    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    //    // you can loop k higher to see more color choices
    //    for(int k = 1; k < 16; k++) {
    //        // pick the colorattribute k you want
    //        SetConsoleTextAttribute(hConsole, k);
    //        std::cout << k << " I want to be nice today!" << std::endl;
    //    }
    //    return 0;

//    SetConsoleTextAttribute(hConsole, CLR_DARK_GOLDENROD);
//    SetConsoleTextAttribute(hConsole, CLR_VERY_LIGHT_GREY);


    // #### Set a seed for rand() and discard first value from it.
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::rand();


    std::cout << "\n################################################################################"
              << "\n###########################      Role Play Game      ###########################"
              << "\n################################################################################"
              << std::endl;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


//    Player::Race    playerRace  {choosePlayerRace()};
//    Player::Spec    playerSpec  {choosePlayerSpec()};
//    my::String      playerName  {choosePlayerName()};

    // #### DEBUG
    Player::Race    playerRace  {Player::Race::HUMAN};
    Player::Spec    playerSpec  {Player::Spec::WARRIOR};
    my::String      playerName  {"Alex"};

    //Warrior* warrior {nullptr};


    Player* player {nullptr};
    switch (playerSpec) {
    case Player::Spec::WARRIOR:
        player = new Warrior;
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



    std::cout << "Hello " << player->getName() << "! Welcome to the game...\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    // #### Main cycle
    while (!player->isDead()) {
        player->newDay();

        SetConsoleTextAttribute(hConsole, CLR_DARK_GOLDENROD);
        std::cout << "\n\n[Day " << player->getTimeLived() << "]\n"
                  << "********************************************************************************"
                  << std::endl;
        SetConsoleTextAttribute(hConsole, CLR_VERY_LIGHT_GREY);
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));       // Just a time gap for convinience

        // ## Create random monster (or NPC)
        //Creature creature {};         - create a creature (monster/trader or smb else)
        Monster monster{};

        // ## What happened at this day?
        std::cout << "You have encountered a ("<< monster.getName() << ") of ("<< monster.getLevel()
                  << ") level." << std::endl;

        player->fightWith(monster);
        monster.commitSuicide();

        if (monster.isDead()) {
            player->getLootFrom(monster);
        }
        else {} // Nothing to do

        // #### Player getting rest
        player->getRest();
    }

    std::cout << "You died at level " << player->getLevel() << ".\n\n";

    delete warrior;
    player = warrior = nullptr;

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
