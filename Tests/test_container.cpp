#include "Core/main.h"
#include "Core/container.h"
#include "Core/Items/gold.h"
#include "Core/Items/potion.h"




int main()
{
    Container box;
    box.display();

    my::SmartPtr<Item> gold {new Gold {100}};
    box.putItem(gold);
    my::SmartPtr<Item> potion {new Potion {3}};
    box.putItem(potion);
    box.display();

    my::SmartPtr<Item> item {box.extractItem(0)};
    box.display();
    box.removeItem(1);
    box.display();

//    my::SmartPtr<Item> potion {new Potion {1}};
//    box.putItem(potion);


//    for (int ii {0}; ii < 10; ++ii) {
//        my::SmartPtr<Item> potion {new Potion {ii}};
//        box.putItem(potion);
//    }

//    box.display();

//    for (int ii {0}; ii < 5; ++ii) {
//        my::SmartPtr<Item>& item {box.extractItem(ii)};
//    }

//    box.display();


    return 0;
}
