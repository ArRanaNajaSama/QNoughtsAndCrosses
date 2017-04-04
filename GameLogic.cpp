#include "GameLogic.h"

#include <QDebug>

#include "Player.h"

GameLogic::GameLogic()
{
    QObject::connect(this, SIGNAL(currCellChanged()), this, SLOT(gameLoop()));
}

GameLogic::~GameLogic()
{
    delete board;
}


void GameLogic::pvpGameMode()
{
    qDebug() << "Player Vs Player Game Mode";

    //initialize board, players.
    board = new Board();
    this->setCurrCell(-1);
    Player player1, player2;
    player1.setPscore(0);
    player2.setPscore(0);

    //promote scores to qml
    this->setScoreX(0);
    this->setScoreO(0);

    //anounce first turn
    this->setWhoseTurn("X start game!");

    //set 1st turn
    player = 1;
    nextTurn = 1;
}

void GameLogic::newGameMode()
{
    qDebug() << "New Game mode";
    //clean board and create new one
    delete board;
    board = new Board();
    this->setCurrCell(-1);

    //anounce first turn
    this->setWhoseTurn("X start game!");

    //set 1st turn
    player = 1;
    nextTurn = 1;

    //connect back signal and slot
    QObject::connect(this, SIGNAL(currCellChanged()), this, SLOT(gameLoop()));

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

int GameLogic::getImage()
{
    return image;
}

void GameLogic::setImage(int _img)
{
    if (image != _img)
    {
        image = _img;
        emit imageChanged();
    }
}

void GameLogic::gameLoop()
{
    //Identify whose turn is now
    player = (player % 2) ? 1:2;
    qDebug() << "Player " << player << " turn";

    //anounce player whose turn is
    nextTurn++;
    nextTurn = (nextTurn % 2) ? 1:2;
    if (nextTurn == 1)
    {
        this->setWhoseTurn("X attack!");
    } else {
        this->setWhoseTurn("O attack!");
    }

    //marker for cells
    int mark = (player == 1) ? 1:2;
    qDebug() << "mark " << mark;

    //Logic for filling border with X/O
    if (currCell > 8 || currCell < 0)
    {
        qDebug() << "Invalid move!";
        player--;
    } else {
        if(board->getField().at(currCell) == 7)
        {
            board->setField(mark, currCell);
            setImage(mark);
        }
    }
    player++;

    //after cell is filled we must check win and anounce if there is any
    int winner = checkWinner();
    this->anounceWinner(winner);
}


int GameLogic::checkWinner()
{
    for(int i = 1; i < 3; i++)
    {
        //for horizontal line
        if (    (board->getField().at(0) == i && board->getField().at(1) == i && board->getField().at(2) == i) ||
                (board->getField().at(3) == i && board->getField().at(4) == i && board->getField().at(5) == i) ||
                (board->getField().at(6) == i && board->getField().at(7) == i && board->getField().at(8) == i) ||

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

void GameLogic::anounceWinner(int win)
{
    switch (win) {

    case 0:
        //anounce the draw
        this->setWhoseTurn("Draw!");

        //prevent further point count
        QObject::disconnect(this, SIGNAL(currCellChanged()), this, SLOT(gameLoop()));

        //disable button

        break;

    case 1:
        //anounce that X is winner
        qDebug() << "X is winner!";
        this->setWhoseTurn("X is winner!");

        //update X player score
        this->updateScoreX(1);

        //prevent further point count
        QObject::disconnect(this, SIGNAL(currCellChanged()), this, SLOT(gameLoop()));
        break;

    case 2:
        //anounce that O is winner
        qDebug() << "O is winner!";
        this->setWhoseTurn("O is winner!");

        //update X player score
        this->updateScoreO(1);

        //prevent further point count
        QObject::disconnect(this, SIGNAL(currCellChanged()), this, SLOT(gameLoop()));
        break;

    default:
        qDebug() << "Continue game";
        break;
    }
}


