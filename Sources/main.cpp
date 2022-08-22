// #########################################################################################
// ############################  My Role-play Game  ########################################
// #########################################################################################

#include "header.h"

#include "cls_creature.h"
#include "cls_monster.h"
#include "cls_player.h"

#include "cls_item.h"
#include "cls_gold.h"
#include "cls_potion.h"

// #1 Видимо, есть проблема в конструкторе класса Player. То есть где-то my::String удаляется лишняяю
//    Попробовать либо добавить copy assignment (в String), либо изменить оператор>> в String


int main()
{
    my::String playerName {"Stranger"};
    Player::Race playerRace {Player::Race::HUMAN};
    Player::Spec playerSpec {Player::Spec::MAGE};

    // ## Set seed for rand() and discard first value from it
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::rand();

    std::cout << "########  My RPG  ########\n\n";


    std::cout << "What's your name, stranger: ";
    std::cin >> playerName;
    Player player {playerName, playerRace, playerSpec};

    std::cout << "Hello " << player.getName() << "! Welcome to the HELL...\n";

    while (!player.isDead()) {
        player.newDay();
        std::cout << "\n#### Day " << player.getTimeLived() << " ####\n\n";

        // Create random monster
        Monster monster {};
        //Monster m1 {Monster::Type::SKELETON};

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
