#ifndef MINESWEEPERBUTTON_H
#define MINESWEEPERBUTTON_H

#include <QPushButton>

class MineSweeperButton : public QPushButton
{
    Q_OBJECT

protected:
    int colum;
    int row;

public:
    explicit MineSweeperButton(QWidget *parent = 0, int the_row = 0, int the_col = 0);

public:
    virtual bool show_content() = 0;

public slots:
    inline void react(){show_content();}
};

#endif // MINESWEEPERBUTTON_H
