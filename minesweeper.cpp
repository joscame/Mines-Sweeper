#include "minesweeper.h"
#include <QGlobal.h>
#include <QTime>
#include <QVector>
#include <iostream>
#include <vectorshuffle.h>

MineSweeper::MineSweeper()
    :mines_map(400)
{
    for (int i = 0; i < 400; ++i)
        mines_map[i] = 0;
}

bool MineSweeper::random_fill()
{
    int mines = 0;
    VectorShuffle shuffler;
    QVector<int> mine_spots(60);
    shuffler.get_random_QNumVec(mine_spots);
    //rellena las minas aleatorias con simbolo de -1, aun no funciona correctamente.
    while ( mines < 60 )
    {
        mines_map[mine_spots[mines]] = -1;
        ++mines;
    }
    return fill_numbers();
}

int MineSweeper::randInt(int first, int last, int qseed)
{
    //QTime time = QTime::currentTime();
    QTime time = QTime::fromMSecsSinceStartOfDay(qseed);
    qsrand((uint)time.msec());
    return qrand() % ((last + 1) - first) + first;
}

int MineSweeper::index(int row, int col)
{
    return col + 20 * row;
}

//rellena los espacios con numeros del uno al 8 si un cuadro tiene minas en alguno de los 8 espacios a su alrededor,
//sino rellena con 0 que significa espacio vacío
bool MineSweeper::fill_numbers()
{
    for (int row = 0; row < 20; ++row)
    {
        for (int col = 0; col < 20; ++col)
        {
            if(mines_map[index(row, col)] != -1)
            {
                int contador = 0;
                if (col < 19 && mines_map[index(row, col+1)] == -1) ++contador;
                if (col > 0 && mines_map[index(row, col-1)] == -1) ++contador;
                if (row > 0 && mines_map[index(row - 1, col)] == -1) ++contador;
                if (row < 19 && mines_map[index(row+ 1, col)] == -1) ++contador;
                if (row > 0 && col > 0 && mines_map[index(row-1, col-1)] == -1) ++contador;
                if (row < 19 && col > 0 && mines_map[index(row+1, col-1)] == -1) ++contador;
                if (row > 0 && col < 19 && mines_map[index(row-1, col+1)] == -1) ++contador;
                if (row < 19 && col < 19 && mines_map[index(row+1, col+1)] == -1) ++contador;
                mines_map[index(row, col)] = contador;
            }
        }
    }
    return true;
}

int MineSweeper::getSpace(int row, int col)
{
    return mines_map[index(row, col)];
}

void MineSweeper::clear()
{
    for (int row = 0; row < 20; ++row)
    {
        for (int col = 0; col < 20; ++col)
        {
            mines_map[index(row, col)] = 0;
        }
    }
}
