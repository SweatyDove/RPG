// #########################################################################################
// ############################  My Role-play Game  ########################################
// #########################################################################################


// ######## Comments:
//
// #1 Add class Mage, Warrior and Hunter, derived from player class with different
//    attack-type and damage. And with different skillset.
//
// #2 Console GUI
//
// #3



#include "header.h"

#include "cls_monster.h"
#include "cls_player.h"
#include "cls_warrior.h"

#include "cls_item.h"
#include "cls_gold.h"
#include "cls_potion.h"


void displayRaceMenu(int state);

int main()
{
    my::String playerName {"Stranger"};
    Player::Race playerRace {Player::Race::HUMAN};
    Player::Spec playerSpec {Player::Spec::WARRIOR};
    char ch {'\0'};

    bool inLoop {true};
    int keystroke {0};

    // ## Set seed for rand() and discard first value from it
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::rand();

    std::cout << "########  My RPG  ########\n\n";


    std::cout << "Who are you, stranger: ";
    std::cin >> playerName;

    // ## Choosing player's race
    linuxTerminalMode(!CANONICAL);
    int state {0};
    int lastState {1};

    inLoop = true;
    while (inLoop) {
        if (state != lastState) {
            displayRaceMenu(state);
        }
        else { /* Nothing to do */ }

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

    std::cout << "Choose your specialization:\n"
              << " 1 - Warrior\n"
              << " 2 - Mage\n"
              << " 3 - Hunter\n"
              << std::flush;
    inLoop = true;
    while (inLoop) {
        std::cin >> ch;
        std::cout << "\033[F \b";
        inLoop = false;
        switch (ch) {
        case '1':
            playerSpec = Player::Spec::WARRIOR;
            //Warrior player {playerName, playerRace};
            break;
        case '2':
            playerSpec = Player::Spec::MAGE;
            //Mage player {playerName, playerRace};
            break;
        case '3':
            playerSpec = Player::Spec::HUNTER;
            //Hunter player {playerName, playerRace};
            break;
        default:
            inLoop = true;
            break;
        }
    }

    Warrior player {playerName, playerRace};
    std::cout << "Hello " << player.getName() << "! Welcome to the HELL...\n";



    while (!player.isDead()) {
        player.newDay();
        std::cout << "\n#### Day " << player.getTimeLived() << " ####\n\n";

        // Create random monster
        Monster monster {};

        std::cout << "You have encountered a " << monster.getName() << " of level "
                  << monster.getLevel() << ".\n";
        player.fightWith(monster);
        if (monster.isDead()) {
            player.getLootFrom(monster);
        }
        else { /* Nothing to do */ }
    }

    std::cout << "You died at level " << player.getLevel() << ".\n\n";
    std::cout << "########  Game Over ########\n\n" << std::endl;


    return 0;            

}



void displayRaceMenu(int state)
{
    int raceMenuSize {6};
    Player::Race race {static_cast<Player::Race>(state)};

    std::cout << "Choose your race:\n\n";

    // ## Display race menu
    switch(race) {
    case Player::Race::ORC:
        std::cout << "\n########## Orc ##########"
                  << "\n           Human         "
                  << "\n           Elf           "
                  << std::endl;
        break;
    case Player::Race::HUMAN:
        std::cout << "\n           Orc           "
                  << "\n########## Human ########"
                  << "\n           Elf           "
                  << std::endl;
        break;
    case Player::Race::ELF:
        std::cout << "\n           Orc           "
                  << "\n           Human         "
                  << "\n########## Elf ##########"
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
