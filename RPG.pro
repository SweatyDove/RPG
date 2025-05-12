TEMPLATE = app
CONFIG += console c++23
CONFIG -= app_bundle
CONFIG -= qt





SOURCES += \
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
    Sources/warrior.cpp \
    Sources/world.cpp

HEADERS += \
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
    Sources/world.h


# List of libraries to be linked into the project. [-L] - path to library; [-l] - library
LIBS += -L $$PWD/../MyLibrary/Library/ -l:MyLib.a

INCLUDEPATH += $$PWD/../MyLibrary/Include
DEPENDPATH += $$PWD/../MyLibrary/Include

# Lists libraries that the target depends on.
PRE_TARGETDEPS += $$PWD/../MyLibrary/Library/MyLib.a
