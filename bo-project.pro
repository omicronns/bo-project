#-------------------------------------------------
#
# Project created by QtCreator 2014-11-12T23:44:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = bo-project
TEMPLATE = app


SOURCES +=  main.cpp\
            widget.cpp \
            src/ParseOptions.cpp \
            src/Point.cpp \
            src/Problem.cpp \
            src/Random.cpp \
            src/Solver.cpp \
            src/Tool.cpp \
            src/Toolchain.cpp \
            src/Workpoint.cpp

HEADERS  += widget.h \
            src/ParseOptions.h \
            src/Point.h \
            src/Problem.h \
            src/Random.h \
            src/Solver.h \
            src/Tool.h \
            src/Toolchain.h \
            src/Workpoint.h

INCLUDEPATH += src/

FORMS    += widget.ui

QMAKE_CXXFLAGS += -std=c++11

LIBS += -lqcustomplot
