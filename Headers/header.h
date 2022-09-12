#if defined(unix) || defined(__unix__) || defined(__unix)
    #define PREDEF_PLATFORM_UNIX
#elif defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)
    #define PREDEF_PLATFORM_WINDOWS
#else
    // Nothing to do
#endif


#include <cstdlib>              // For std::rand(), std::srand()
#include <iostream>
//#include <string>             // Replaced with "my_string.h"
#include <ctime>                // For std::time()
#include <utility>              // For std::move
#include <cassert>
#include <array>
#include <thread>
#include <atomic>

#include "my_string.h"

// #### Define non-blocking input in Linux
#ifdef PREDEF_PLATFORM_UNIX
    #include <unistd.h>
    #include <sys/time.h>
    #include <sys/select.h>
    #include <termios.h>                // Describe a general terminal interface that
                                        // is provided to control asynchronous communications ports.

    #define     CANONICAL   true
    #define     MOVE_CURSOR_ONE_LINE_UP  "\033[F"
    #define     NEW_LINE                 "\n"

    void    linuxTerminalMode(bool mode);
    int     linux_kbhit(void);

#endif // PREDEF_PLATFORM_UNIX

#define     WORK_SCREEN_LINES       20
#define     WORK_SCREEN_COLUMNS     80

#define     MOVE_UP(ch)             (ch == 'W' || ch == 'w')
#define     MOVE_DOWN(ch)           (ch == 'S' || ch == 's')
#define     ACCEPT(ch)              (ch == 'E' || ch == 'e')



class Item;
class Gold;
class Potion;

class Creature;
class Player;
class Monster;


int getRandomNumber(int min, int max);
void displayRaceMenu(int state);
void displaySpecMenu(int state);
void clearWorkScreen(int lines, int columns);
void moveCursor(int relativeLine, unsigned int column);




