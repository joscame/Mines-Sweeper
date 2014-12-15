#ifndef NUMBERSPACE_H
#define NUMBERSPACE_H

#include <minesweeperbutton.h>

class MainWindow;

class NumberSpace : public MineSweeperButton
{
protected:
    int number = 1;
    QString file_name;
    MainWindow* interfaz;

public:
    NumberSpace(QWidget *parent = 0, int row = 0, int col = 0, int number = 0, MainWindow* intz = 0);

public:
    virtual bool show_content() override;
    bool set_number(int num);
};

#endif // NUMBERSPACE_H
