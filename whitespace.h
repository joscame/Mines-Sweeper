#ifndef WHITESPACE_H
#define WHITESPACE_H

#include <minesweeperbutton.h>

class MainWindow;

class WhiteSpace : public MineSweeperButton
{
protected:
    MainWindow* interfaz;

public:
    WhiteSpace(QWidget *parent = 0, int row = 0, int col = 0, MainWindow* intz = 0);

public:
    virtual bool show_content() override;
};

#endif // WHITESPACE_H
