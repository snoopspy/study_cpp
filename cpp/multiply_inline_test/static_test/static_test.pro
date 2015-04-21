TEMPLATE = app
CONFIG -= qt
CONFIG += console
QMAKE_CXXFLAGS += -g
LIBS += -L. -lmultiply
SOURCES += static_test.cpp
HEADERS += *.h
