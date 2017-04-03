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
    Q_PROPERTY(int scoreX READ getScoreX WRITE setScoreX NOTIFY scoreXChanged)
    Q_PROPERTY(int scoreO READ getScoreO WRITE setScoreO NOTIFY scoreOChanged)

    QString getWhoseTurn();
    void setWhoseTurn(QString str);

    int getCurrCell();
    void setCurrCell(int _cell);

    QString getPlayerName();
    void setPlayerName();

    int getScoreX();
    void setScoreX(int x);
    void updateScoreX(int x);
    void updateScoreO(int o);

    int getScoreO();
    void setScoreO(int o);

    int checkWinner();

public slots:
    void getCellNumberFromQML(int cell);
    void gameLoop();

signals:
    void whoseTurnChanged();
    void currCellChanged();
    void scoreXChanged();
    void scoreOChanged();

private:
    int currCell;
    QString whoseTurn;
    Board *board;
    int player;
    QString playerName;
    int scoreX;
    int scoreO;
    int plTurn;

};
