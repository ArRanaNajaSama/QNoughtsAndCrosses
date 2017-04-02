#pragma once

#include <QObject>

#include "Board.h"

class GameLogic : public QObject
{
    Q_OBJECT

public:
    GameLogic();
    ~GameLogic();

    Q_INVOKABLE void pvpGameMode();
    Q_PROPERTY(QString whoseTurn READ getWhoseTurn WRITE setWhoseTurn NOTIFY whoseTurnChanged)
    Q_PROPERTY(int currCell READ getCurrCell WRITE setCurrCell NOTIFY currCellChanged)

    QString getWhoseTurn();
    void setWhoseTurn(QString str);

    int getCurrCell();
    void setCurrCell(int _cell);

    int checkWinner();

public slots:
    void getCellNumberFromQML(int cell);
    void gameLoop();

signals:
    void whoseTurnChanged();
    void currCellChanged();

private:
    int currCell;
    QString whoseTurn;
    Board *board;
    int player;

};
