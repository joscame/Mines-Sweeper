#include "minesweeperbutton.h"

MineSweeperButton::MineSweeperButton(QWidget *parent, int the_row, int the_col) :
    QPushButton(parent)
  ,colum(the_col)
  ,row(the_row)
{
}

