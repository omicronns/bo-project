#-------------------------------------------------
#
# Project created by QtCreator 2014-11-12T23:44:02
#
#-------------------------------------------------

QT       += core gui \
            printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = bo-project
TEMPLATE = app


SOURCES +=  src/qt/main.cpp \
            src/qt/widget.cpp \
            src/qt/guidata.cpp \
            src/qt/globalvariables.cpp \
            src/qt/toolpathwidget.cpp \
            src/qt/generateform.cpp \
            src/qt/qcustomplot/qcustomplot.cpp \
            src/engine/ParseOptions.cpp \
            src/engine/Point.cpp \
            src/engine/Problem.cpp \
            src/engine/Random.cpp \
            src/engine/Solver.cpp \
            src/engine/Tool.cpp \
            src/engine/Toolchain.cpp \
            src/engine/Workpoint.cpp \

HEADERS  += src/qt/widget.h \
            src/qt/guidata.h \
            src/qt/globalvariables.h \
            src/qt/toolpathwidget.h \
            src/qt/generateform.h \
            src/qt/qcustomplot/qcustomplot.h \
            src/engine/ParseOptions.h \
            src/engine/Point.h \
            src/engine/Problem.h \
            src/engine/Random.h \
            src/engine/Solver.h \
            src/engine/Tool.h \
            src/engine/Toolchain.h \
            src/engine/Workpoint.h \

INCLUDEPATH +=  src/qt/ \
                src/qt/qcustomplot \
                src/engine/

FORMS    += src/qt/widget.ui \
            src/qt/generateform.ui

QMAKE_CXXFLAGS += -std=c++11

#LIBS += -lqcustomplot
