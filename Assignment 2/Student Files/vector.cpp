#include <iostream>
#include "vector.h"
#include <iomanip>
using namespace std;

Vector::Vector(unsigned s)
{
    if (s < 1)
        throw "Error: Invalid row index";
    size = s;
    vector = new double[size];
    for (int i = 0; i < size; i++)
    {
        vector[i] = 0;
    }
}

Vector::~Vector()
{
    delete[] vector;
}

Vector::Vector(const Vector &rhs)
{
    size = rhs.size;
    vector = new double[size];
    for (int i = 0; i < size; i++)
    {
        vector[i] = rhs[i];
    }
}

const Vector &Vector::operator=(const Vector &rhs)
{
    if (this == &rhs)
    {
        return *this;
    }
    size = rhs.size;
    vector = new double[size];
    for (int i = 0; i < size; i++)
    {
        vector[i] = rhs.vector[i];
    }
    return *this;
}

void Vector::print()
{
    for (int i = 0; i < size; i++)
    {
        cout << setw(10) << setprecision(3) << vector[i];
    }
    cout << endl;
}

void Vector::readFile(istream &infile)
{

    for (int i = 0; i < size; i++)
    {
        infile >> vector[i];
    }
}

double &Vector::operator[](const unsigned r)
{
    if (r < 0 || r >= size)
        throw "Error: invalid row index";
    else

        return vector[r];
}

const double &Vector::operator[](const unsigned r) const
{
    if (r < 0 || r >= size)
        throw "Error: invalid row index";
    else
        return vector[r];
}

unsigned Vector::getSize() const
{
    return size;
}

Vector Vector::operator+(const Vector &rhs)
{
    Vector temp(size);

    if (rhs.size != size)
    {
        throw "Error: adding vetors of different dimensionality";
    }
    else
    {

        for (int i = 0; i < size; i++)
        {
            temp.vector[i] = vector[i] + rhs.vector[i];
        }
        return temp;
    }
}
Vector &Vector::operator+=(const Vector &rhs)
{

    if (rhs.size != size)
    {
        throw "Error: adding vetors of different dimensionality";
    }

    else
    {
        for (int i = 0; i < size; i++)
        {
            vector[i] = vector[i] + rhs.vector[i];
        }
        return *this;
    }
}

Vector Vector::operator-(const Vector &rhs)
{
    Vector temp(size);

    if (size != rhs.size)
    {
        throw "Error: subtracting vetors of different dimensionality";
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            temp.vector[i] = vector[i] - rhs.vector[i];
        }
        return temp;
    }
}

Vector &Vector::operator-=(const Vector &rhs)
{

    if (rhs.size != size)
    {
        throw "Error: subtracting vectors of different dimensionality";
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            vector[i] = vector[i] - rhs.vector[i];
        }
        return *this;
    }
}

Vector Vector::operator^(int pow)
{
    Vector vec(*this);
    if (pow < 0)
        throw "Error: negative power is not supported";

    if (pow == 0)
    {
        for (int i = 0; i < size; i++)
        {
            vec[i] = 1;
        }
        return vec;
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 1; j < pow; j++)
            {
                vec.vector[i] *= vector[i];
            }
        }
        return vec;
    }
}

Vector operator*(const double &value, const Vector &rhs)
{
    Vector result(rhs);

    for (int i = 0; i < result.size; i++)
    {

        result.vector[i] = result.vector[i] * value;
    }
    return result;
}
Vector Vector::operator~()
{
    Vector newVector(size);

    for (int i = 0; i < size; i++)
    {
        newVector.vector[i] = this->vector[size - 1 - i];
    }

    return newVector;
}

Vector Vector::operator*(const double &rhs)
{
    Vector final(*this);
    for (int i = 0; i < size; i++)
    {
        final.vector[i] *= rhs;
    }
    return final;
}

Vector Vector::operator/(const double &rhs)
{
    Vector final(*this);
    if (rhs == 0)
    {
        throw "Error: division by zero";
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            final.vector[i] = vector[i] / rhs;
        }
        return final;
    }
}

Vector &Vector::operator^=(int pow)
{
    Vector vec(*this);
    if (pow < 0)
    {
        throw "Error: negative power is not supported";
    }

    if (pow == 0)
    {
        for (int i = 0; i < size; i++)
        {
            vector[i] = 1;
        }
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j < pow; j++)
        {
            vector[i] *= vec.vector[i];
        }
    }
    return *this;
}

Vector &Vector::operator*=(const double &rhs)
{
    for (int i = 0; i < size; i++)
    {
        vector[i] = vector[i] * rhs;
    }
    return *this;
}
