
/*******************************************************************************
 ********  Defining the platform
 ******************************************************************************/
#if defined(unix) || defined(__unix__) || defined(__unix)
    #define PREDEF_PLATFORM_UNIX
#elif defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)
    #define PREDEF_PLATFORM_WINDOWS
#else
    // Nothing to do
#endif


#include <cstdlib>              // For std::rand(), std::srand()
#include <iostream>
#include <ctime>                // For std::time()
#include <utility>              // For std::move
#include <cassert>
#include <memory>
#include <type_traits>          // For std::is_same


// ######## STL containers
#include <array>
#include <vector>
#include <string>


// ######## My library
#include "my_string.h"
#include "my_log.h"
#include "my_utilities.h"
#include "my_queue.hpp"



// #### For multi-threading
#include <mutex>
#include <thread>
#include <atomic>


#if defined(PREDEF_PLATFORM_UNIX)
    #include <unistd.h>
    #include <sys/time.h>
    #include <sys/select.h>
    #include <termios.h>                // Describe a general terminal interface that
                                        // is provided to control asynchronous communications ports.

    // #### Define non-blocking input in Linux
    #define     CANONICAL   true
    #define     MOVE_CURSOR_ONE_LINE_UP  "\033[F"
    #define     NEW_LINE                 "\n"

    void    linuxTerminalMode(bool mode);
    int     linux_kbhit(void);

    #define     WORK_SCREEN_LINES       24
    #define     WORK_SCREEN_COLUMNS     80

    #define     MOVE_UP(ch)             (ch == 'W' || ch == 'w')
    #define     MOVE_DOWN(ch)           (ch == 'S' || ch == 's')
    #define     ACCEPT(ch)              (ch == 'E' || ch == 'e')

#elif defined(PREDEF_PLATFORM_WINDOWS)

    #include <windows.h>   // WinApi header

    // ######## Windows console text colors on black background
    extern HANDLE hConsole;

    #define     CLR_NAVY_BLUE           1
    #define     CLR_ISLAMIC_GREEN       2
    #define     CLR_SUMMER_SKY          3
    #define     CLR_FIRE_ENGINE_RED     4
    #define     CLR_PURPLE_HEART        5
    #define     CLR_DARK_GOLDENROD      6
    #define     CLR_VERY_LIGHT_GREY     7
    #define     CLR_PUMICE              8
    #define     CLR_DODGER_BLUE         9
    #define     CLR_DARK_PASTEL_GREEN   10
    #define     CLR_MEDIUM_TURQUOISE    11
    #define     CLR_FLAMINGO            12
    #define     CLR_DARK_MAGENTA        13
    #define     CLR_PALE_PRIM           14
    #define     CLR_WHITE_SMOKE         15

#endif







class Item;
class Gold;
class Potion;

class Creature;
class Player;
class Monster;


int getRandomNumber(int min, int max);
void clearWorkScreen(int lines, int columns);
void moveCursor(int relativeLine, unsigned int column);




