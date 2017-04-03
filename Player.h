#pragma once
#include <QString>

class Player
{
public:
    Player(QString _pname = "Some John",
           QString _position = "X",
           int _score = "0");

    QString getPname();
    void setPname(QString name);
    QString getPosition();
    void setPosition(QString pos);
    int getPscore();
    void setPscore(int sc);
    void updateScore(int up);

private:
    QString pname;
    QString position; // X or O, by def - X
    int pscore;

};
