



/*
std::cout << "Choose your specialization:\n"
          << " 1 - Warrior\n"
          << " 2 - Mage\n"
          << " 3 - Hunter\n"
          << std::flush;
inLoop = true;
while (inLoop) {
    std::cin >> ch;
    std::cout << "\033[F \b";
    inLoop = false;
    switch (ch) {
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
*/

/*
 *   int state {0};
    int lastState {1};
    bool threadIsActive {true};
    //std::atomic<int> state {0};
    //std::atomic<int> lastState {1};
    //std::atomic<bool> threadIsActive {true};

    // ## Launch the thread, that has to display race menu each 30 msec
    // ## depending on the [state]
    //std::thread th_1(displayThread, state);
//    auto lambda = [&]() {
//            while (threadIsActive) {
//                if (lastState != state) {
//                    displayRaceMenu(state);
//                }
//                else {} // Nothing to do
//            }
//            std::this_thread::sleep_for(std::chrono::milliseconds(30));
//    };
    std::thread thread_1(displayThread, state, threadIsActive);

    bool inLoop {true};
    while (inLoop) {
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
        else {} // Nothing to do
    } // while()

    // ## Say [thread_1] to stop his work and will wait till it does it.
    threadIsActive = false;
    thread_1.join();

*/
