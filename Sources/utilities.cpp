#include "Headers/header.h"


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

// Move cursor in the specified position (@@relative_line > 0, then move forward; @@relative_line < 0 - move backward; @@relative_line == 0 - stay at the same line)
void moveCursor(int relative_line, unsigned int column)
{
    //int mask = 0;
    //unsigned char* forward  = "\n";                                     // New line
    //unsigned char* backward = "\033[F";                                 // Previous line
    const char* shift    = nullptr;                                  // Set the direction of the cursor movement

    shift = (relative_line > 0) ? NEW_LINE : MOVE_CURSOR_ONE_LINE_UP;
    //mask = relative_line >> 31;
    //relative_line = (relative_line + mask) ^ mask;				// Take modulo (if <int> has 32 bits!)

    relative_line = (relative_line >= 0) ? relative_line : -relative_line;       // Take modulo

    // Set line position
    while (relative_line-- > 0) {
        std::cout << shift;
    }

    // Set column position
    std::cout.put('\r');
    while (column-- > 0) {
        std::cout.put(' ');
    }

    return;
}













