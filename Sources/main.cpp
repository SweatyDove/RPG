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
 * 13 - Think about balance between versality of class's methods and their readability/convinience.
 *      For example, if function is used a lot - better to make it shorter, split into parts
 *
 * 14 - Transfer spell's multipliers and other it's settings to <Spell> class from the <Creature>'s
 *      derived classes (or think about to store all <Spell> instances in one file/place)
 *
 * 15 - Add a formula of monster's health depending on player's health in such way... For example,
 *      monster's level is random number from 1-10. Its hp, accordingly, 10-100 hp (level * baseHealth for example).
 *      Then, average monster health will be 55 (taking into account the equal probavility of occurrence
 *      and monster's health = level * baseHealth). Then, I suppose, player's health should be about 55 hp.
 *
 * 16 - Pay more attention to random generation of ALL - monsters, caves, castles, trees and so on...
 *      And give to player a goal to explore the world (and trying to find treasures!). For example,
 *      in Skyrim there are fixed points of chests with treasure. But I want smth in the Skyrim settings,
 *      but with cave's autogeneration (like in DRG) and treasure random generation (like in Sea Of Thieves)
 *      and so on...
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


//Player::Race choosePlayerRace();
//Player::Spec choosePlayerSpec();
//StringClass   choosePlayerName();

#if defined(PREDEF_PLATFORM_WINDOWS)
    HANDLE hConsole;
#endif


//class Base {
//private:

//public:
//    int mb_a {};
//    int mb_b {};
//    Base(int a, int b) :
//        mb_a {a},
//        mb_b {b}
//    {
//        // Nothing to do
//    }

//};

//std::ostream& operator<<(std::ostream& out, const Base& base)
//{
//    out << '(' << base.mb_a << ", " << base.mb_b << ") " << std::endl;
//}


int main()
{

    //==============================================================================================
    //=============================>  START OF DEBUG SECTION  <=====================================
    //==============================================================================================





    //==============================================================================================
    //===============================>  END OF DEBUG SECTION  <=====================================
    //==============================================================================================

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

//    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


//    Player::Race    playerRace  {choosePlayerRace()};
//    Player::Spec    playerSpec  {choosePlayerSpec()};
//    StringClass      playerName  {choosePlayerName()};

    // #### DEBUG
    Player::Race    playerRace  {Player::Race::HUMAN};
    Player::Spec    playerSpec  {Player::Spec::WARRIOR};
    StringClass     playerName  {"Alex"};

    //Warrior* warrior {nullptr};


    Player* player {nullptr};
    switch (playerSpec) {
    case Player::Spec::WARRIOR:
        player = new Warrior {playerRace, playerSpec, playerName};
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
    while (player->metNewDay()) {

//        SetConsoleTextAttribute(hConsole, CLR_DARK_GOLDENROD);
        std::cout << "\n\n[Day " << player->getTimeLived() << "]\n"
                  << "***************************************************************" << std::endl;
        player->printAttr();
        std::cout << "***************************************************************" << std::endl;
//        SetConsoleTextAttribute(hConsole, CLR_VERY_LIGHT_GREY);

        // ## Create random monster (or NPC)
        //Creature creature {};         - create a creature (monster/trader or smb else)
        Monster monster{};

        // ## What happened at this day?
        std::cout << "You have encountered a "<< monster.getName() << " of "<< monster.getLevel()
                  << " level." << std::endl;
        monster.printAttr();
        std::cout << "***************************************************************" << std::endl;

        player->fightWith(monster);
//        monster.commitSuicide();

        // #### If the monster was killed - player can loot its corpse.
        if (monster.isDead()) {
            player->getLootFrom(monster);
        }
        else if (player->isDead()){
            break;
        }
        else {}// Nothing to do

    }

    std::cout << "You died at level " << player->getLevel() << ".\n\n";

    delete player;
    player = nullptr;

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
