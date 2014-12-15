#include "minespace.h"
#include <QIcon>
#include <QPixmap>
#include "mainwindow.h"
#include <QGridLayout>

MineSpace::MineSpace(QWidget *parent, int row, int col, MainWindow* intz):
    MineSweeperButton(parent, row, col)
  , interfaz(intz)
{
}

bool MineSpace::show_content()
{
    QString file_name("://mina");
    QPixmap image(file_name);
    QIcon mine_icon(image);
    setIcon(mine_icon);
    setEnabled(false);
    return interfaz->begin_new_one();
}

