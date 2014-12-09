#include "minesweeper.h"
#include <QGlobal.h>
#include <QTime>
#include <QVector>

MineSweeper::MineSweeper()
    :mines_map(400)
{
}

bool MineSweeper::random_fill()
{
    int mines = 0;
    int row;
    int col;
    //rellena las minas aleatorias con simbolo de -1, aun no funciona correctamente.
    while ( mines < 100 )
    {
        int qseed = 1;
        row = randInt(0, 19, mines);
        col = randInt(0, 19, mines);
        while( mines_map[index(row, col)] == -1)
        {
            row = randInt(0, 19, qseed);
            col = randInt(0, 19, qseed);
            ++qseed;
        }
        mines_map[index(row, col)] = -1;
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
            int contador = 0;
            if (mines_map[col < 19 && index(row, col+1)] == -1) ++contador;
            if (mines_map[col > 0 && index(row, col-1)] == -1) ++contador;
            if (mines_map[row > 0 && index(row - 1, col)] == -1) ++contador;
            if (mines_map[row < 19 && index(row+ 1, col)] == -1) ++contador;
            if (mines_map[row, col > 0 && index(row-1, col-1)] == -1) ++contador;
            if (mines_map[row < 19 && col > 0 && index(row+1, col-1)] == -1) ++contador;
            if (mines_map[row > 0 && col < 19 && index(row-1, col+1)] == -1) ++contador;
            if (mines_map[row, col > 19 && index(row+1, col+1)] == -1) ++contador;
            mines_map[index(row, col)] = contador;
        }
    }
    return true;
}

const int MineSweeper::getSpace(int row, int col)
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
