TEMPLATE = app
CONFIG -= qt
QMAKE_CXXFLAGS += -g -flto
QMAKE_LFLAGS_RELEASE += -g -flto
SOURCES += *.cpp
HEADERS += *.h
