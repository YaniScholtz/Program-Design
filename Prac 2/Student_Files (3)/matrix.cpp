#include <iostream>

#include "matrix.h"

using namespace std;

Matrix::Matrix(int in_rows, int in_columns)
{

    if ((in_rows < 1) || (in_columns < 1))
    {

        this->rows = 3;
        this->columns = 3;
        matrix = new int **[3];
        for (int i = 0; i < 3; i++)
        {
            matrix[i] = new int *[columns];
            for (int j = 0; j < 3; j++)
            {
                matrix[i][j] = new int(1);
            }
        }
    }
    else if ((in_rows >= 1) && (in_columns >= 1))
    {
        this->rows = in_rows;
        this->columns = in_columns;
        matrix = new int **[rows];
        for (int i = 0; i < rows; i++)
        {
            matrix[i] = new int *[columns];
            for (int j = 0; j < columns; j++)
            {
                matrix[i][j] = new int(0);
            }
        }
    }
}

Matrix::~Matrix()
{
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < columns; col++)
        {
            delete matrix[row][col];
        }
        delete[] matrix[row];
    }

    delete[] matrix;
}

void Matrix::resizeRows(int num_rows)
{
    if (num_rows < 1)
    {
        cout << "Error: cannot have less than 1 row" << endl;
    }

    else if (num_rows < rows)
    {
        int ***newArray = new int **[num_rows];
        for (int i = 0; i < num_rows; i++)
        {
            newArray[i] = new int *[columns];
            for (int j = 0; j < columns; j++)
            {
                newArray[i][j] = matrix[i][j];
            }
        }
        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < columns; col++)
                delete matrix[row][col];
            delete[] matrix[row];
        }
        delete[] matrix;
        // matrix = new int **[rows];
        // for (int i = 0; i < rows; i++)
        // {
        //     matrix[i] = new int *[columns];
        //     for (int j = 0; j < columns; j++)
        //     {
        //         matrix[i][j] = new int(0);
        //     }
        // }
        this->rows = num_rows;
        matrix = newArray;
    }

    else if (num_rows > rows)
    {
        int ***newArray = new int **[num_rows];
        for (int i = 0; i < num_rows; i++)
        {
            newArray[i] = new int *[columns];
            for (int j = 0; j < columns; j++)
            {
                newArray[i][j] = new int(0);
            }
        }

        for (int k = 0; k < rows; k++)
        {
            for (int u = 0; u < columns; u++)
            {
                newArray[k][u] = matrix[k][u];
            }
        }

        for (int row = 0; row < rows; row++)
        {

            delete[] matrix[row];
        }
        delete[] matrix;

        // matrix = new int **[rows];
        // for (int i = 0; i < rows; i++)
        // {
        //     matrix[i] = new int *[columns];
        //     for (int j = 0; j < columns; j++)
        //     {
        //         matrix[i][j] = new int(0);
        //     }
        // }
        this->rows = num_rows;
        matrix = newArray;
    }
}

void Matrix::resizeColumns(int num_cols)
{

    if (num_cols < 1)
    {

        cout << "Error: cannot have less than 1 column" << endl;
    }

    else if (num_cols < columns)
    {
        int ***newArray = new int **[rows];
        for (int i = 0; i < rows; i++)
        {
            newArray[i] = new int *[num_cols];
            for (int j = 0; j < num_cols; j++)
            {
                newArray[i][j] = matrix[i][j];
            }
        }

        for (int row = 0; row < rows; row++)
        {
            delete[] matrix[row];
        }
        delete[] matrix;

        // matrix = new int **[rows];
        // for (int i = 0; i < rows; i++)
        // {
        //     matrix[i] = new int *[columns];
        //     for (int j = 0; j < columns; j++)
        //     {
        //         matrix[i][j] = new int(0);
        //     }
        // }
        this->columns = num_cols;
        matrix = newArray;
    }

    else if (num_cols > columns)
    {
        int ***newArray = new int **[rows];
        for (int i = 0; i < rows; i++)
        {
            newArray[i] = new int *[num_cols];
            for (int j = 0; j < num_cols; j++)
            {
                newArray[i][j] = new int(0);
            }
        }

        for (int k = 0; k < rows; k++)
        {
            for (int u = 0; u < columns; u++)
            {
                newArray[k][u] = matrix[k][u];
            }
        }

        for (int row = 0; row < rows; row++)
        {
            delete[] matrix[row];
        }
        delete[] matrix;

        // matrix = new int **[rows];
        // for (int i = 0; i < rows; i++)
        // {
        //     matrix[i] = new int *[columns];
        //     for (int j = 0; j < columns; j++)
        //     {
        //         matrix[i][j] = new int(0);
        //     }
        // }
        this->columns = num_cols;
        matrix = newArray;
    }
}

void Matrix::setMatrix()
{
    int numbers;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cin >> numbers;
            *matrix[i][j] = numbers;
        }
    }
}

// Do not change the displayMatrix() function
void Matrix::displayMatrix()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {

            cout << *matrix[i][j];

            if (j != columns - 1)
            {
                cout << " ";
            }
        }

        cout << endl;
    }
}