#include "Board.h"

Board::Board(QVector<QString>_field) : field(_field)
{
}

QVector<QString> Board::getField()
{
    return field;
}

void Board::setField(QString str, int i)
{
    if (str != field[i])
    {
        field[i] = str;
    }
}
