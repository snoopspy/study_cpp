CONFIG -= qt
CONFIG += console

CONFIG += gstacktrace
include(../../../../../g/g/g.pri)
QMAKE_CXXFLAGS_RELEASE += -O2 -g -flto
QMAKE_LFLAGS_RELEASE += -O1 -g -flto
INCLUDEPATH += ../foo
SOURCES += ../foo/*.cpp *.cpp
HEADERS += ../foo/*.h
