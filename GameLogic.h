#pragma once

#include <QObject>

class GameLogic : public QObject
{
    Q_OBJECT

public:
    GameLogic();

    Q_INVOKABLE void pvpGameMode();

signals:

private:

};
