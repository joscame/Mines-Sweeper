#include "whitespace.h"
#include "mainwindow.h"

WhiteSpace::WhiteSpace(QWidget *parent, int row, int col, MainWindow *intz):
    MineSweeperButton(parent, row, col)
  , interfaz(intz)
{
}

bool WhiteSpace::show_content()
{
    //setEnabled(false);
    setVisible(false);
    return interfaz->turn_switch();
}
