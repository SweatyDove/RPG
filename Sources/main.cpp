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


int main()
{
    my::String playerName {"Stranger"};
    Player::Race playerRace {Player::Race::HUMAN};
    Player::Spec playerSpec {Player::Spec::WARRIOR};
    char choice {'\0'};

    bool inLoop {true};

    // ## Set seed for rand() and discard first value from it
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::rand();

    std::cout << "########  My RPG  ########\n\n";


    std::cout << "Who are you, stranger: ";
    std::cin >> playerName;
    std::cout << "Choose your race:\n"
              << " 1 - Human\n"
              << " 2 - Orc\n"
              << " 3 - Elf\n"
              << std::flush;
    while (inLoop) {
        std::cin >> choice;
        std::cout << "\033[F \b";
        inLoop = false;
        switch (choice) {
        case '1':
            playerRace = Player::Race::HUMAN;
            break;
        case '2':
            playerRace = Player::Race::ORC;
            break;
        case '3':
            playerRace = Player::Race::ELF;
            break;
        default:
            inLoop = true;
            break;
        }
    }

    std::cout << "Choose your specialization:\n"
              << " 1 - Warrior\n"
              << " 2 - Mage\n"
              << " 3 - Hunter\n"
              << std::flush;
    inLoop = true;
    while (inLoop) {
        std::cin >> choice;
        std::cout << "\033[F \b";
        inLoop = false;
        switch (choice) {
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


/*
void chooseRace(Player::Race& race)
{
    int state {0};
    std::cout << "Choose your race:\n\n";


    while(true) {

        // ## Display states
        switch(state) {
        case 0:
            std::cout << "\n########  ORC  ########";
            std::cout << "\n          HUMAN        ";
            std::cout << "\n          ELF          ";
            break;
        case 1:
            std::cout << "\n          ORC          ";
            std::cout << "\n########  HUMAN  ######";
            std::cout << "\n          ELF          ";
            break;
        case 2:
            std::cout << "\n          ORC          ";
            std::cout << "\n          HUMAN        ";
            std::cout << "\n########  ELF  ########";
            break;
        default:
            break;
        }


    }


}
*/
