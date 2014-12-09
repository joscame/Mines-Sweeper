#include "numberspace.h"

NumberSpace::NumberSpace(QWidget *parent, int row, int col):
    MineSweeperButton(parent, row, col)
{
}

bool NumberSpace::show_content()
{
    QString label(QString::number(number));
    setText(label);
    setEnabled(false);
    return true;
}

bool NumberSpace::set_number(int num)
{
    number = num;
    return true;
}
