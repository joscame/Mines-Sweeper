#include "mainwindow.h"
#include <QApplication>
#include "minesweeper.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MineSweeper *game;
    game = new MineSweeper();
    game->random_fill();
    MainWindow w(0, game);
    w.show();

    return a.exec();
}

