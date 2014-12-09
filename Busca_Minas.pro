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

HEADERS  += mainwindow.h \
    minesweeperbutton.h \
    whitespace.h \
    minespace.h \
    numberspace.h \
    minesweeper.h

FORMS    += mainwindow.ui

OTHER_FILES +=

RESOURCES += \
    assets/mine.qrc \
    new_game.qrc
