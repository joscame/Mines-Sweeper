#ifndef NUMBERSPACE_H
#define NUMBERSPACE_H

#include <minesweeperbutton.h>

class NumberSpace : public MineSweeperButton
{
protected:
    int number = 1;

public:
    NumberSpace(QWidget *parent = 0, int row = 0, int col = 0);

public:
    virtual bool show_content() override;
    bool set_number(int num);
};

#endif // NUMBERSPACE_H
