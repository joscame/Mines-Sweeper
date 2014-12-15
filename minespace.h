#ifndef MINESPACE_H
#define MINESPACE_H

#include <minesweeperbutton.h>

class MainWindow;

class MineSpace : public MineSweeperButton
{
protected:
    MainWindow* interfaz;

public:
    MineSpace(QWidget *parent = 0, int row = 0, int col = 0, MainWindow* interfaz = 0);

public:
    virtual bool show_content() override;
};

#endif // MINESPACE_H
