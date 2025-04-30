#include <iostream>
#include "matrix.h"
#include <iomanip>
using namespace std;

Matrix::Matrix(unsigned r, unsigned c)
{

    rows = r;
    cols = c;

    matrix = new double *[rows]; // array
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new double[cols]; // cols
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = 0;
        }
    }
}

Matrix::~Matrix()
{
    for (int i = 0; i < rows; i++)
    {

        delete[] matrix[i];
    }
    delete[] matrix;
}

Matrix::Matrix(const Matrix &rhs)
{
    rows = rhs.rows;
    cols = rhs.cols;
    matrix = new double *[rows]; // rows
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new double[cols]; // cols
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = rhs.matrix[i][j];
        }
    }
}

const Matrix &Matrix::operator=(const Matrix &rhs)
{
    if (this == &rhs)
    {
        return *this;
    }
    rows = rhs.rows;
    cols = rhs.cols;
    matrix = new double *[rows];
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new double[cols];
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = rhs.matrix[i][j];
        }
    }
    return *this;
}
void Matrix::readFile(istream &infile)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            infile >> matrix[i][j];
        }
    }
}

void Matrix::print()
{
    for (int a = 0; a < rows; a++)
    {
        for (int b = 0; b < cols; b++)
        {
            cout << setw(10) << setprecision(3) << matrix[a][b];
        }
        cout << endl;
    }
}

Vector Matrix::operator[](const unsigned r) const
{
    if ((r < 0) || (r >= rows))
    {
        throw "Error: invalid row index";
    }
    else
    {
        Vector vec(cols);
        for (int i = 0; i < cols; i++)
        {
            vec[i] = matrix[r][i];
        }
        return vec;
    }
}
const double &Matrix::operator()(const unsigned r, const unsigned c) const
{
    if ((r < 0) || (r >= rows))
        throw "Error: invalid row index";
    else if ((c < 0) || (c >= cols))
        throw "Error invalid column index";
    else
        return matrix[r][c];
}

double &Matrix::operator()(const unsigned r, const unsigned c)
{
    if ((r < 0) || (r >= rows))
        throw "Error: invalid row index";
    else if ((c < 0) || (c >= cols))
        throw "Error invalid column index";
    else
        return matrix[r][c];
}

unsigned Matrix::getRows() const
{
    return rows;
}

unsigned Matrix::getCols() const
{
    return cols;
}

Matrix Matrix::operator+(const Matrix &rhs)
{

    Matrix temp(rhs);

    if ((rows != rhs.rows) || (cols != rhs.cols))
    {
        throw "Error: adding matrices of different dimensionality";
    }
    else
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                temp.matrix[i][j] += matrix[i][j];
            }
        }

        return temp;
    }
}

Matrix operator*(const double &value, const Matrix &rhs)
{
    Matrix result(rhs.rows, rhs.cols);
    for (int i = 0; i < rhs.rows; i++)
    {
        for ( int j = 0; j < rhs.cols; j++)
        {
            result.matrix[i][j] = rhs.matrix[i][j] * value;
        }
    }
    return result ;
}

Matrix &Matrix::operator+=(const Matrix &rhs)
{

    if ((rows != rhs.rows) || (cols != rhs.cols))
    {
        throw "Error: adding matrices of different dimensionality";
    }
    else
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {

                matrix[i][j] += rhs.matrix[i][j];
            }
        }

        return *this;
    }
}

Matrix Matrix::operator-(const Matrix &rhs)
{
    Matrix temp(rhs);

    if ((rows != rhs.rows) || (cols != rhs.cols))
    {
        throw "Error: subtracting matrices of different dimensionality";
    }
    else
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                temp.matrix[i][j] -= matrix[i][j];
            }
        }

        return temp;
    }
}

Matrix &Matrix::operator-=(const Matrix &rhs)
{

    if ((rows != rhs.rows) || (cols != rhs.cols))
    {
        throw "Error: subtracting matrices of different dimensionality";
    }

    else
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {

                matrix[i][j] -= rhs.matrix[i][j];
            }
        }

        return *this;
    }
}

Matrix Matrix::operator/(const double &rhs)
{
    if (rhs == 0)
    {
        throw "Error: division by zero";
    }
    else
    {
        Matrix temp(rows, cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                temp.matrix[i][j] = matrix[i][j] / rhs;
            }
        }

        return temp;
    }
}

Matrix Matrix::operator*(const double &rhs)
{
    Matrix temp(rows, cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            temp.matrix[i][j] = rhs * matrix[i][j];
        }
    }
    return temp;
}

Matrix Matrix::operator*(const Matrix &rhs)
{

    if (this->cols != rhs.rows)
    {
        throw "Error: invalid matrix multiplication";
    }
    else
    {
        Matrix temp(this->rows, rhs.cols);

        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < rhs.cols; j++)
            {

                for (int k = 0; k < rhs.rows; k++)
                {
                    temp.matrix[i][j] += this->matrix[i][k] * rhs.matrix[k][j];
                }
            }
        }
        return temp;
    }
}

Matrix Matrix::operator^(int pow)
{
    Matrix result(*this);
    if (rows != cols)
    {
        throw "Error: non-square matrix provided";
    }
    if (pow < 0)
    {
        throw "Error: negative power is not supported";
    }

    if (pow != 0)
    {

        Matrix powermatrix(*this);
        for (int i = 1; i < pow; i++)
        {
            result = result * powermatrix;
        }

    } // end of if

    else
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (i == j)
                    result.matrix[i][j] = 1;
                else
                    result.matrix[i][j] = 0;
            }
        }
    }
    // end of else
    return result;
}
Matrix Matrix::operator~()
{
    Matrix temp(cols, rows);
    for (int i = 0; i < temp.rows; ++i)
    {
        for (int j = 0; j < temp.cols; ++j)
        {
            temp.matrix[i][j] = matrix[j][i];
        }
    }

    return temp;
}

Matrix &Matrix::operator*=(const Matrix &rhs)
{

    if (this->cols != rhs.rows)
    {
        throw "Error: invalid matrix multiplication";
    }
    else
    {
        Matrix mat(this->rows, rhs.cols);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < rhs.cols; j++)
            {

                for (int k = 0; k < rhs.rows; k++)
                {
                    mat.matrix[i][j] += matrix[i][k] * rhs.matrix[k][j];
                }
            }
        }

        *this = mat;

        return *this;
    }
}

Matrix &Matrix::operator*=(const double &rhs)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = matrix[i][j] * rhs;
        }
    }
    return *this;
}

Matrix &Matrix::operator^=(int pow)
{
    if (rows != cols)
    {
        throw "Error: non-square matrix provided";
    }

    if (pow < 0)
    {
        throw "Error: negative power is not supported";
    }

    if (pow != 0)
    {
        Matrix powermatrix(*this);
        for (int j = 1; j < pow; j++)
        {
            *this *= powermatrix;
        }
        return *this;
    }

    // end of if

    else
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (i == j)
                    matrix[i][j] = 1;
                else
                    matrix[i][j] = 0;
            }
        }
        return *this;
    } // end of else
}

Matrix &Matrix::operator|=(Matrix &rhs)
{

    if (rows != cols)
    {
        throw "Error: non-square matrix provided";
    }
    if ((rhs.cols != 1) || (rhs.rows != rows))
    {
        throw "Error: incorrect augmentaion";
    }

    double m = 0;
    for (int j = 0; j < rows - 1; j++)
    {
        for (int i = j + 1; i < rows; i++)
        {
            if (matrix[j][j] == 0)
            {
                throw "Error: division by zero";
            }
            m = matrix[i][j] / matrix[j][j];
            for (int k = 0; k < rows; k++)
            {
                matrix[i][k] = matrix[i][k] - (m * matrix[j][k]);
            }
            rhs.matrix[i][0] = rhs.matrix[i][0] - (m * rhs.matrix[j][0]);
        }
    }
    return *this;
}

Matrix Matrix::operator|(const Matrix &rhs)
{

    Matrix A(rows, cols);
    A.operator=(*this);
    bool flag;
    flag = true;

    Matrix s(rows, 1);
    s.operator=(rhs);

    if (this->rows != this->cols)
    {
        throw "Error: non-square matrix provided";
    }
    else if ((rhs.cols != 1) || (rhs.rows != rows))
    {
        throw "Error: incorrect augmentation";
    }

    for (int i = 1; i < rows; i++)
    {
        for (int k = 0; k < i; k++)
        {
            if (A.matrix[i][k] != 0)
            {
                flag = false;
            }
        }
    }

    if (flag == false)
    {
        A |= s;
    }

    for (int i = rows - 1; i >= 0; i--)
    {
        for (int j = i + 1; j < rows; j++)
        {
            s.matrix[i][0] = s.matrix[i][0] - (A.matrix[i][j] * s.matrix[j][0]);
        }
        if (A.matrix[i][i] == 0)
        {
            throw "Error: division by zero";
        }
        s.matrix[i][0] = s.matrix[i][0] / A.matrix[i][i];
    }

    return s;
}
