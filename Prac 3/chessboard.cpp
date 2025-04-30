
#include <iostream>
#include "chessboard.h"

using namespace std;

Chessboard::Chessboard(Chessboard &obj)
{

    this->rows = obj.rows;
    this->columns = obj.columns;

    board = new Chesspiece **[rows];
    for (int i = 0; i < rows; i++)
    {

        board[i] = new Chesspiece *[columns];
        for (int j = 0; j < columns; j++)
        {
            if (obj.board[i][j] != NULL)
            {
                board[i][j] = new Chesspiece(*obj.board[i][j]);
            }
            else
            {
                board[i][j] = NULL;
            }
        }
    }
}

Chessboard::Chessboard(int in_rows, int in_columns)
{
    rows = in_rows;
    columns = in_columns;
    board = new Chesspiece **[rows];
    for (int i = 0; i < rows; i++)
    {
        board[i] = new Chesspiece *[columns];
        for (int j = 0; j < columns; j++)
        {
            board[i][j] = NULL;
        }
    }
}

Chessboard::~Chessboard()
{
    if (board != NULL)
    {
        for (int i = 0; i < rows; i++)
        {
            if (board[i] != NULL)
            {
                for (int j = 0; j < columns; j++)
                {

                    if (board[i][j] != NULL)
                    {
                        delete board[i][j];
                        board[i][j] = NULL;
                    }
                }

                delete[] board[i];
                board[i] = NULL;
            }
        }
        delete[] board;
        board = NULL;
    }
}

void Chessboard::addChesspiece(Chesspiece *piece, int row, int column)
{

    board[row][column] = piece;
}

void Chessboard::removeChesspiece(int row, int column)
{

    delete board[row][column];
    board[row][column] = NULL;
}

Chesspiece &Chessboard::at(int row, int column) const
{

    return *board[row][column];
}

Chessboard &Chessboard::operator=(const Chessboard &other)
{

    if (this == &other)
    {
        return *this;
    }
    else
    {

        this->rows = other.rows;
        this->columns = other.columns;

        // delete elements
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                delete board[i][j];
            }
        }

        // board = new Chesspiece **[rows];
        for (int i = 0; i < rows; i++)
        {
            // if (this->board[i] != NULL)
            // {

            // board[i] = new Chesspiece *[columns];
            for (int j = 0; j < columns; j++)
            {
                if (other.board[i][j] != NULL)
                {
                    this->board[i][j] = new Chesspiece(*other.board[i][j]);
                }
                else
                {
                    this->board[i][j] = NULL;
                }
            }
            // }
        }

        return *this;
    }
}

Chessboard &Chessboard::operator+=(const Chessboard &rhs)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if ((rhs.board[i][j] != NULL) && (this->board[i][j] == NULL))
            {
                this->board[i][j] = rhs.board[i][j];
            }
        }
    }

    return *this;
}
