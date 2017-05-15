#-------------------------------------------------
#
# Project created by QtCreator 2017-05-12T15:12:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = graph
TEMPLATE = app

CONFIG += c++11

INCLUDEPATH += C:\Boost\boost_1_64_0\boost_1_64_0\boost_mingw_530\include\boost-1_64\
LIBS += -LC:\Boost\boost_1_64_0\boost_1_64_0\boost_mingw_530\lib -lboost


SOURCES += main.cpp\
        mainwindow.cpp \
    graphview.cpp \
    bridge.cpp

HEADERS  += mainwindow.h \
    graphview.h \
    bridge.h

FORMS    += mainwindow.ui
