#pragma once

#include <QString>
#include <QVector>

class Board
{
public:
    Board(QVector <int>_field = QVector <int>(9, 7));

    QVector<int> getField();
    void setField(int x, int i);

private:
    QVector <int> field;
};
