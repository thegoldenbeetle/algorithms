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

SOURCES += main.cpp\
        mainwindow.cpp \
    graphview.cpp

HEADERS  += mainwindow.h \
    graphview.h

FORMS    += mainwindow.ui
