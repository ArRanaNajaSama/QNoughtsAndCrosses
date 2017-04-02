#pragma once

#include <QString>
#include <QVector>

class Board
{
public:
    Board(QVector <QString>_field = QVector <QString>(9, "Empty"));

    QVector <QString> getField();
    void setField(QString str, int i);

private:
    QVector <QString> field;
};
