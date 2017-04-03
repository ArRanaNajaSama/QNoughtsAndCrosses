#include "GameLogic.h"

#include <QDebug>

#include "Player.h"

GameLogic::GameLogic()
{
    QObject::connect(this, SIGNAL(currCellChanged()), this, SLOT(gameLoop()));
}

GameLogic::~GameLogic()
{}


void GameLogic::pvpGameMode()
{
    qDebug() << "Player Vs Player Game Mode";

    //initialize board, players.
    board = new Board();
    Player player1, player2;
    player1.setPscore(0);
    player2.setPscore(0);
    this->setScoreX(0);
    this->setScoreO(0);
    this->setWhoseTurn("X start game!");
    player = 1;
    plTurn = 1;

    // start new game
    //this->gameLoop();
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


int GameLogic::getCurrCell()
{
    return currCell;
}

void GameLogic::setCurrCell(int _cell)
{
    if (_cell != currCell)
    {
        currCell = _cell;
        emit currCellChanged();
    }
}

int GameLogic::getScoreX()
{
    return scoreX;
}

void GameLogic::setScoreX(int x)
{
    if (scoreX != x)
    {
        scoreX = x;
        emit scoreXChanged();
    }
}

void GameLogic::updateScoreX(int x)
{
    scoreX += x;
    emit scoreXChanged();
}

int GameLogic::getScoreO()
{
    return scoreO;
}

void GameLogic::setScoreO(int o)
{
    if (scoreO != o)
    {
        scoreO = o;
        emit scoreOChanged();
    }
}

void GameLogic::updateScoreO(int o)
{
    scoreO += o;
    emit scoreOChanged();
}


void GameLogic::getCellNumberFromQML(int cell)
{
    qDebug() << "Pressed cell number:" << cell;
    this->setCurrCell(cell);
    qDebug() << "Current Cell is" << getCurrCell();
}

void GameLogic::gameLoop()
{
    player = (player % 2) ? 1:2;
    qDebug() << "Player " << player << " turn";

    plTurn++;
    plTurn = (plTurn % 2) ? 1:2;
    if (plTurn == 1)
    {
        this->setWhoseTurn("X attack!");
    } else {
        this->setWhoseTurn("O attack!");
    }

    //marker for cells
    int mark = (player == 1)? 1:2;

    //Logic for filling border
    if (getCurrCell() == 0)
    {
        if(board->getField().at(0) == 7)
        {
            board->setField(mark, 0);
        }
    } else if (getCurrCell() == 1)
    {
        if(board->getField().at(1) == 7)
        {
            board->setField(mark, 1);
        }
    }else if (getCurrCell() == 2)
    {
        if(board->getField().at(2) == 7)
        {
            board->setField(mark, 2);
        }
    } else if (getCurrCell() == 3)
    {
        if(board->getField().at(3) == 7)
        {
            board->setField(mark, 3);
        }
    }else if (getCurrCell() == 4)
    {
        if(board->getField().at(4) == 7)
        {
            board->setField(mark, 4);
        }
    }else if (getCurrCell() == 5)
    {
        if(board->getField().at(5) == 7)
        {
            board->setField(mark, 5);
        }
    }else if (getCurrCell() == 6)
    {
        if(board->getField().at(6) == 7)
        {
            board->setField(mark, 6);
        }
    }else if (getCurrCell() == 7)
    {
        if(board->getField().at(7) == 7)
        {
            board->setField(mark, 7);
        }
    }else if (getCurrCell() == 8)
    {
        if(board->getField().at(8) == 7)
        {
            board->setField(mark, 8);
        }
    } else {
        qDebug() << "Invalid move!";
        player--;
    }

    player++;

    //after cell is filled we must check win
    int winner = checkWinner();
    if (winner == 1)
    {
        this->setWhoseTurn("X is winner!");
        qDebug() << "X is winner!";
        //stop game
        QObject::disconnect(this, SIGNAL(currCellChanged()), this, SLOT(gameLoop()));

        //increase X player score
        this->updateScoreX(1);

        //continue / new game?

    } else if (winner == 2)
    {
        this->setWhoseTurn("O is winner!");
        //stop game
        QObject::disconnect(this, SIGNAL(currCellChanged()), this, SLOT(gameLoop()));

        //increase O player score
        this->updateScoreO(1);

        //ask whether its new game or continue?

    } else if (winner == 0)
    {
        this->setWhoseTurn("Draw!");

        //stop game
        QObject::disconnect(this, SIGNAL(currCellChanged()), this, SLOT(gameLoop()));

        //continue / new game?

    }
}


int GameLogic::checkWinner()
{
    for(int i = 1; i < 3; i++)
    {
        //for horizontal line
        if (    (board->getField().at(0) == i && board->getField().at(1) == i && board->getField().at(2) == i) ||
                (board->getField().at(3) == i && board->getField().at(4) == i && board->getField().at(5) == i) ||
                (board->getField().at(3) == i && board->getField().at(4) == i && board->getField().at(5) == i) ||

                //for vertical lines
                (board->getField().at(0) == i && board->getField().at(3) == i && board->getField().at(6) == i) ||
                (board->getField().at(1) == i && board->getField().at(4) == i && board->getField().at(7) == i) ||
                (board->getField().at(2) == i && board->getField().at(5) == i && board->getField().at(8) == i) ||

                //for diagonals:
                (board->getField().at(0) == i && board->getField().at(4) == i && board->getField().at(8) == i) ||
                (board->getField().at(2) == i && board->getField().at(4) == i && board->getField().at(6) == i) )
        {
            return i;
        }
    }

    //Draw check
    int count = 0;
    for (int i = 0; i < board->getField().size(); i++)
    {
        if (board->getField().at(i) != 7)
        {
            count++;
        }
    }
    // if all field are filled
    if(count == 9)
    {
        return 0;
    }
    return -1;

}
