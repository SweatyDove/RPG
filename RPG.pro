TEMPLATE = app
CONFIG += console c++23
CONFIG -= app_bundle
CONFIG -= qt





SOURCES += \
    Tests/test_container.cpp \
#    Core/Creatures/creature.cpp \
#    Core/Creatures/monster.cpp \
#    Core/Creatures/player.cpp \
#    Core/Creatures/trader.cpp \
#    Core/Creatures/warrior.cpp \
    Core/Items/gold.cpp \
    Core/Items/item.cpp \
    Core/Items/potion.cpp \
#    Core/Items/scroll.cpp \
#    Core/Items/trash.cpp \
#    Core/attribute.cpp \
    Core/container.cpp \
#    Core/menu.cpp \
#    Core/spell.cpp \
#    Core/world.cpp \

HEADERS += \
    Core/main.h \
#    Core/Creatures/creature.h \
#    Core/Creatures/monster.h \
#    Core/Creatures/player.h \
#    Core/Creatures/trader.h \
#    Core/Creatures/warrior.h \
    Core/Items/gold.h \
    Core/Items/item.h \
    Core/Items/potion.h \
#    Core/Items/scroll.h \
#    Core/Items/trash.h \
#    Core/attribute.h \
    Core/container.h \
#    Core/menu.h \
#    Core/spell.h \
#    Core/world.h \


# List of libraries to be linked into the project. [-L] - path to library; [-l] - library
LIBS += -L $$PWD/../MyLibrary/Library/ -l:MyLib.a

INCLUDEPATH += $$PWD/../MyLibrary/Include
DEPENDPATH += $$PWD/../MyLibrary/Include

# Lists libraries that the target depends on.
PRE_TARGETDEPS += $$PWD/../MyLibrary/Library/MyLib.a
