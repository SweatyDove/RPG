cmake_minimum_required(VERSION 3.23)

project(ConsoleRPG)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS -pthread)

include_directories(Headers)

add_executable(ConsoleRPG

        Headers/header.h
        Headers/cls_gold.h
        Headers/cls_item.h
        Headers/cls_monster.h
        Headers/cls_player.h
        Headers/cls_potion.h
        Headers/cls_warrior.h
        Headers/my_string.h
        Headers/my_log.h
        Headers/my_queue.hpp
        Headers/my_utilities.h

        Sources/main.cpp
        Sources/cls_gold.cpp
        Sources/cls_item.cpp
        Sources/cls_monster.cpp
        Sources/cls_player.cpp
        Sources/cls_potion.cpp
        Sources/cls_warrior.cpp
        Sources/linux_nonblock_input.cpp
        Sources/player_general.cpp
        Sources/utilities.cpp
        Sources/my_string.cpp
        Sources/my_log.cpp
        Sources/my_utilities.cpp
        )
