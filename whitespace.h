#ifndef WHITESPACE_H
#define WHITESPACE_H

#include <minesweeperbutton.h>

class WhiteSpace : public MineSweeperButton
{
public:
    WhiteSpace(QWidget *parent = 0, int row = 0, int col = 0);

public:
    virtual bool show_content() override;
};

#endif // WHITESPACE_H
