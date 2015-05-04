CONFIG -= qt
CONFIG += console

QMAKE_CXXFLAGS += -g
LIBS += -L. -lmultiply
SOURCES += shared_test.cpp
HEADERS += multiply.h
