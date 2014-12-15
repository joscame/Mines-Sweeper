#-------------------------------------------------
#
# Project created by QtCreator 2014-12-04T20:56:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Busca_Minas
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    minesweeperbutton.cpp \
    whitespace.cpp \
    minespace.cpp \
    numberspace.cpp \
    minesweeper.cpp \
    vectorshuffle.cpp

HEADERS  += mainwindow.h \
    minesweeperbutton.h \
    whitespace.h \
    minespace.h \
    numberspace.h \
    minesweeper.h \
    vectorshuffle.h

FORMS    += mainwindow.ui

OTHER_FILES +=

RESOURCES += \
    assets/mine.qrc \
    new_game.qrc \
    assets/1.qrc \
    assets/2.qrc \
    assets/3.qrc \
    assets/4.qrc \
    assets/5.qrc \
    assets/6.qrc \
    assets/7.qrc \
    assets/8.qrc \
    assets/start_button.qrc \
    assets/background.qrc
