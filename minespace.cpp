#include "minespace.h"
#include <QIcon>
#include <QPixmap>

MineSpace::MineSpace(QWidget *parent, int row, int col):
    MineSweeperButton(parent, row, col)
{
}

bool MineSpace::show_content()
{
    QString file_name("://mina");
    QPixmap image(file_name);
    QIcon mine_icon(image);
    setIcon(mine_icon);
    setEnabled(false);
    return true;
}
