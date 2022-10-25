TEMPLATE = app
CONFIG += c++17
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += $$PWD/Headers





SOURCES += \
        Sources/cls_gold.cpp \
        Sources/cls_item.cpp \
        Sources/cls_monster.cpp \
        Sources/cls_player.cpp \
        Sources/cls_potion.cpp \
		Sources/cls_warrior.cpp \
		Sources/excluded_code_snippets.cpp \
		Sources/linux_nonblock_input.cpp \
        Sources/main.cpp \
		Sources/my_log.cpp \
        Sources/my_string.cpp \
		Sources/my_utilities.cpp \
		Sources/player_general.cpp \
        Sources/utilities.cpp \

HEADERS += \
	Headers/header.h \
	Headers/cls_gold.h \
	Headers/cls_item.h \
	Headers/cls_monster.h \
	Headers/cls_player.h \
	Headers/cls_potion.h \
	Headers/cls_warrior.h \
	Headers/my_log.h \
	Headers/my_queue.hpp \
	Headers/my_string.h \ \
	Headers/my_utilities.h

DISTFILES +=

QMAKE_CXXFLAGS += -std=c++0x -pthread
LIBS += -pthread



