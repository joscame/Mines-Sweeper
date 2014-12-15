#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include <QVector>

class MineSweeper
{
public:
    QVector<int> mines_map;

public:
    MineSweeper();
    bool random_fill();
    int randInt(int first, int last, int qseed);
    int index(int row, int col);
    bool fill_numbers();
    int getSpace(int row, int col);
    void clear();
};

#endif // MINESWEEPER_H
