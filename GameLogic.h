#pragma once

#include <QObject>

class GameLogic : public QObject
{
    Q_OBJECT

public:
    GameLogic();
    ~GameLogic();

    Q_INVOKABLE void pvpGameMode();
    Q_PROPERTY(QString whoseTurn READ getWhoseTurn WRITE setWhoseTurn NOTIFY whoseTurnChanged)
    Q_PROPERTY(int currCell READ getCurrCell WRITE setCurrCell NOTIFY currCellChanged)
    Q_PROPERTY(int playerOneScore READ getPlayerOneScore WRITE setPlayerOneScore NOTIFY playerOneScoreChanged)

    QString getWhoseTurn();
    void setWhoseTurn(QString str);

    int getPlayerOneScore();
    void setPlayerOneScore(int score);

    int getCurrCell();
    void setCurrCell(int _cell);


public slots:
    void getCellNumberFromQML(int cell);

signals:
    void whoseTurnChanged();
    void currCellChanged();
    void playerOneScoreChanged();

private:
    int playerOneScore;
    int currCell;
    QString whoseTurn;


};
