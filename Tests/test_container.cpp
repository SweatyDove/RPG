#include "Core/main.h"
#include "Core/container.h"
#include "Core/Items/gold.h"




int main()
{
    Container box;
    box.display();

    my::SmartPtr<Item> gold {new Gold{100}};
    box.putItem(gold);
    box.display();


    return 0;
}
