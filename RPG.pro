TEMPLATE = app
CONFIG += console c++23
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += ../MyLibrary


SOURCES += \
        ../MyLibrary/my_dynamicarray.cpp \
        ../MyLibrary/my_string.cpp \
        ../MyLibrary/my_utilities.cpp \
        ../MyLibrary/my_array.cpp \
        ../MyLibrary/my_smartptr.cpp \
        ../MyLibrary/my_prettyprint.cpp \
        Sources/attribute.cpp \
        Sources/creature.cpp \
        Sources/gold.cpp \
        Sources/item.cpp \
        Sources/main.cpp \
        Sources/monster.cpp \
        Sources/player.cpp \
        Sources/potion.cpp \
        Sources/spell.cpp \
        Sources/trader.cpp \
        Sources/trash.cpp \
        Sources/utilities.cpp \
        Sources/warrior.cpp \

HEADERS += \
    ../MyLibrary/my_dynamicarray.h \
    ../MyLibrary/my_string.h \
    ../MyLibrary/my_utilities.h \
    ../MyLibrary/my_array.h \
    ../MyLibrary/my_smartptr.h \
    ../MyLibrary/my_prettyprint.h \
#    ../MyLibrary/my_smartptr.hpp \
    Sources/attribute.h \
    Sources/creature.h \
    Sources/gold.h \
    Sources/item.h \
    Sources/main.h \
    Sources/monster.h \
    Sources/player.h \
    Sources/potion.h \
    Sources/spell.h \
    Sources/trader.h \
    Sources/trash.h \
    Sources/warrior.h \
