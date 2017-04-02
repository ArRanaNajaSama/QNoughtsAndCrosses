#include "GameLogic.h"

#include <QDebug>

#include "Player.h"
#include "Board.h"

GameLogic::GameLogic()
{}

GameLogic::~GameLogic()
{}


void GameLogic::pvpGameMode()
{
    qDebug() << "Player Vs Player Game Mode";

    //initialize board, players.
    Board board;
    Player playerOne;
    playerOne.setPname("Player One");
    playerOne.setPosition("X");
    Player playerTwo;
    playerTwo.setPname("Player Two");
    playerTwo.setPosition("O");

    //new game data: set turn on 0 and players scores on 0
    int turn = 0;
    this->setPlayerOneScore(0);

    //game loop
    //anounce whose turn is now
    if (turn == 0)
    {
        this->setWhoseTurn("X attack!");
    }

    //check if any cell was pressed
    switch(getCurrCell())
    {
        case 0:
         QString fieldStatus = board.getField().at(0);
         qDebug() << "fieldStatus" << fieldStatus;
         if (fieldStatus == "Empty")
         {
             board.setField("X", 0);
             turn++;
             break;
         } else {
             qDebug() << "Error! Invalid move!";
         }

    }
}

QString GameLogic::getWhoseTurn()
{
    return whoseTurn;
}

void GameLogic::setWhoseTurn(QString str)
{
    if (str != whoseTurn)
    {
        whoseTurn = str;
        emit whoseTurnChanged();
    }
}

int GameLogic::getPlayerOneScore()
{
    return playerOneScore;
}

void GameLogic::setPlayerOneScore(int score)
{
    if (playerOneScore != score)
    {
        playerOneScore = score;
        emit playerOneScoreChanged();
    }
}

int GameLogic::getCurrCell()
{
    return currCell;
}

void GameLogic::setCurrCell(int _cell)
{
    if (_cell != currCell)
    {
        currCell = _cell;
    }
}

void GameLogic::getCellNumberFromQML(int cell)
{
    qDebug() << "Pressed cell number:" << cell;
    this->setCurrCell(cell);
    qDebug() << "Current Cell is" << getCurrCell();
    emit currCellChanged();
}
