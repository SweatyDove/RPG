#include "header.h"


int getRandomNumber(int min, int max)
{
    static constexpr double fraction {1.0 / (RAND_MAX + 1.0)};

    return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}

void clearWorkScreen(int lines, int columns)
{
    // ## Clear the work screen
    for (int ii {0}; ii < lines; ++ii) {
        for (int jj {0}; jj < columns; ++jj) {
           std::cout << ' ';
        }
        std::cout << std::endl;
    }

    // ## Return cursor to the start position
    for (int ii {0}; ii < lines; ++ii) {
        std::cout << MOVE_CURSOR_ONE_LINE_UP;
    }

    return;
}
