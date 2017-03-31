#pragma once
#include <QString>

class Player
{
public:
    Player(QString _pname = "Some John",
           QString _position = "X");

    QString getPname();
    void setPname(QString name);
    QString getPosition();
    void setPosition(QString pos);

private:
    QString pname;
    QString position; // X or O, by def - X

};
