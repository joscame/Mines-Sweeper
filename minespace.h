#ifndef MINESPACE_H
#define MINESPACE_H

#include <minesweeperbutton.h>

class MineSpace : public MineSweeperButton
{
public:
    MineSpace(QWidget *parent = 0, int row = 0, int col = 0);

public:
    virtual bool show_content() override;
};

#endif // MINESPACE_H
