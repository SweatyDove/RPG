TEMPLATE = app
CONFIG += console c++23
CONFIG -= app_bundle
CONFIG -= qt





SOURCES += \
    Sources/Creatures/creature.cpp \
    Sources/Creatures/monster.cpp \
    Sources/Creatures/player.cpp \
    Sources/Creatures/trader.cpp \
    Sources/Creatures/warrior.cpp \
    Sources/Items/gold.cpp \
    Sources/Items/item.cpp \
    Sources/Items/potion.cpp \
    Sources/Items/scroll.cpp \
    Sources/Items/trash.cpp \
    Sources/attribute.cpp \
    Sources/container.cpp \
    Sources/main.cpp \
    Sources/menu.cpp \
    Sources/spell.cpp \
    Sources/world.cpp \

HEADERS += \
    Sources/Creatures/creature.h \
    Sources/Creatures/monster.h \
    Sources/Creatures/player.h \
    Sources/Creatures/trader.h \
    Sources/Creatures/warrior.h \
    Sources/Items/gold.h \
    Sources/Items/item.h \
    Sources/Items/potion.h \
    Sources/Items/scroll.h \
    Sources/Items/trash.h \
    Sources/attribute.h \
    Sources/container.h \
    Sources/main.h \
    Sources/menu.h \
    Sources/spell.h \
    Sources/world.h \


# List of libraries to be linked into the project. [-L] - path to library; [-l] - library
LIBS += -L $$PWD/../MyLibrary/Library/ -l:MyLib.a

INCLUDEPATH += $$PWD/../MyLibrary/Include
DEPENDPATH += $$PWD/../MyLibrary/Include

# Lists libraries that the target depends on.
PRE_TARGETDEPS += $$PWD/../MyLibrary/Library/MyLib.a
