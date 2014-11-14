#-------------------------------------------------
#
# Project created by QtCreator 2014-11-12T23:44:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = bo-project
TEMPLATE = app


SOURCES +=  src/qt/main.cpp\
            src/qt/widget.cpp \
            src/engine/ParseOptions.cpp \
            src/engine/Point.cpp \
            src/engine/Problem.cpp \
            src/engine/Random.cpp \
            src/engine/Solver.cpp \
            src/engine/Tool.cpp \
            src/engine/Toolchain.cpp \
            src/engine/Workpoint.cpp

HEADERS  += src/qt/widget.h \
            src/engine/ParseOptions.h \
            src/engine/Point.h \
            src/engine/Problem.h \
            src/engine/Random.h \
            src/engine/Solver.h \
            src/engine/Tool.h \
            src/engine/Toolchain.h \
            src/engine/Workpoint.h

INCLUDEPATH +=  src/engine/ \
                src/qt/

FORMS    += src/qt/widget.ui

QMAKE_CXXFLAGS += -std=c++11

LIBS += -lqcustomplot
