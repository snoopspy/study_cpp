CONFIG -= qt
CONFIG += console

QMAKE_CXXFLAGS -= -g -flto -O3
QMAKE_LFLAGS += -g -flto
INCLUDEPATH += ../foo
LIBS += -L$${PWD} -lfoo
CONFIG += gstacktrace
include(../../../../../g/g/g.pri)
DESTDIR = $${PWD}
SOURCES += static_test.cpp
