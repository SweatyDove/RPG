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
// #4 Нужно как-то реализовать НЕ копирование, а ПЕРЕМЕЩЕНИЕ базовой части класса Warrior (то есть Player&)
//    из player. То есть имеем объект класса Player. И в зависимости от выбранной специализации,
//    делаем этот объект частью наследуемого объекта. (Просто прсивоить адрес объекта player адресу базовой части warrior?)



#include "Headers/header.h"
#include "Headers/cls_monster.h"
#include "Headers/cls_player.h"
#include "Headers/cls_warrior.h"

#include "Headers/cls_item.h"
#include "Headers/cls_gold.h"
#include "Headers/cls_potion.h"

//void displayThread(int state);
//void displayRaceMenu(int state);
//Player::Race choosePlayerRace();
//Player::Spec choosePlayerSpec();

int main()
{
    //my::String playerName {"Stranger"};
    Player player {};
    Player* pl {&player};

//    Player::Race playerRace {Player::Race::HUMAN};
//    Player::Spec playerSpec {Player::Spec::WARRIOR};


    // ## Set seed for rand() and discard first value from it
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::rand();


    std::cout << "\n################################################################################"
              << "\n###########################      Role Play Game      ###########################"
              << "\n################################################################################"
              << "\n[CONTROL]:'W' - move up; 'S' - move down; 'E' - accept;\n"
              << std::endl;


    clearWorkScreen(WORK_SCREEN_LINES, WORK_SCREEN_COLUMNS);


    // У меня есть базовый класс Player. На его основе я хочу создать наследуемый класс Warrior/Mage/Hunter.
    // То есть идея такая, что я использую, по возможнотсти, объект базового класса Player. И в случае необходимости
    // уже использую методы интерфейсных классов Warrior/Mage/...

    // Но я не могу создать базовую сущность абстрактного класса...

    // Инициализирую базовую часть
    player.chooseRace();
    player.chooseSpec();
    player.chooseName();

    // Далее хочу, в зависимости от выбора игрока, инициализировать наследуемую часть,
    // но с использованием уже доступной базовой части.
    Warrior* warrior {nullptr};

    switch (player.getSpec()) {
    case Player::Spec::WARRIOR:
        warrior = new Warrior {player};
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



    std::cout << "Hello " << warrior->getName() << "! Welcome to the HELL...\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    std::cout << MOVE_CURSOR_ONE_LINE_UP;
    clearWorkScreen(1, WORK_SCREEN_COLUMNS);



    while (!player.isDead()) {
        player.newDay();

        // Create random monster
        Monster monster {};
        std::cout << "\nDay " << player.getTimeLived() << ": "
                  << "you have encountered a " << monster.getName() << " of level "
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
