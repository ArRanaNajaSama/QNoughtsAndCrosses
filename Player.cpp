#include "Player.h"

Player::Player(QString _pname, QString _position, int _score) : pname(_pname), position(_position)
{}

QString Player::getPname()
{
    return pname;
}

void Player::setPname(QString name)
{
    if (name != pname)
    {
        pname = name;
    }
}

QString Player::getPosition()
{
    return position;
}

void Player::setPosition(QString pos)
{
    if (pos != position)
    {
        position = pos;
    }
}

int Player::getPscore()
{
    return pscore;
}

void Player::setPscore(int sc)
{
    if (sc != pscore)
    {
        pscore = sc;
    }
}

void Player::updateScore(int up)
{
    pscore += up;
}
