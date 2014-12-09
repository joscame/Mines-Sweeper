#include "whitespace.h"

WhiteSpace::WhiteSpace(QWidget *parent, int row, int col):
    MineSweeperButton(parent, row, col)
{
}

bool WhiteSpace::show_content()
{
    //setEnabled(false);
    setVisible(false);
    return true;
}
