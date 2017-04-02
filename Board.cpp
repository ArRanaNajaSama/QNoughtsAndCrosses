#include "Board.h"

Board::Board(QVector<int> _field) : field(_field)
{
}

QVector<int> Board::getField()
{
    return field;
}

void Board::setField(int x, int i)
{
    if (x != field[i])
    {
        field[i] = x;
    }
}
