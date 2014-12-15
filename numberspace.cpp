#include "numberspace.h"
#include "mainwindow.h"

NumberSpace::NumberSpace(QWidget *parent, int row, int col, int number, MainWindow *intz):
    MineSweeperButton(parent, row, col)
  , file_name(":/")
  , interfaz(intz)
{
    QString num = QString::number(number);
    file_name = file_name + num + ".png";
}

bool NumberSpace::show_content()
{
    QPixmap image(file_name);
    QIcon number_icon(image);
    setIcon(number_icon);
    setEnabled(false);
    return interfaz->turn_switch();
}

bool NumberSpace::set_number(int num)
{
    number = num;
    return true;
}
