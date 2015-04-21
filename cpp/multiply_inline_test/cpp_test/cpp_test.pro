TEMPLATE = app
CONFIG -= qt
CONFIG += console
QMAKE_CXXFLAGS += -g -flto
LIBS += -g -flto
SOURCES += *.cpp
HEADERS += *.h
