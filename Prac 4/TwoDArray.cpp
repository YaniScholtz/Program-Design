#include <iostream>
#include <string>
#include "TwoDArray.h"
using namespace std;

TwoDArray::TwoDArray(int **array, int *sizes, int baseSize)
{

    this->baseSize = baseSize;

    this->sizes = new int[baseSize];   // rows
    this->array = new int *[baseSize]; // rows
    for (int i = 0; i < baseSize; i++)
    {
        this->sizes[i] = sizes[i];
        this->array[i] = new int[sizes[i]]; // cols
        for (int j = 0; j < sizes[i]; j++)
        {
            this->array[i][j] = array[i][j];
        }
    }
}

TwoDArray::~TwoDArray()
{
    for (int i = 0; i < baseSize; i++)
    {
        delete[] array[i];
    }
    delete[] array;
    delete[] sizes;
}

ostream &operator<<(ostream &os, TwoDArray &tda)
{
    for (int i = 0; i < tda.baseSize; i++)
    {
        for (int j = 0; j < tda.sizes[i]; j++)
        {
            os << tda.array[i][j] << " ";
        }
        os << endl;
    }

    return os;
}

int **TwoDArray::getArray()
{

    int **NewArray = new int *[baseSize];
    for (int i = 0; i < baseSize; i++)
    {
        NewArray[i] = new int[*sizes];
        for (int j = 0; j < *sizes; j++)
        {
            NewArray[i][j] = array[i][j];
        }
    }
    return NewArray;
}

int *TwoDArray::getSizes()
{
    int *NewSizes = new int[baseSize];
    for (int i = 0; i < baseSize; i++)
    {
        NewSizes[i] = sizes[i];
    }
    return NewSizes;
}

int TwoDArray::getBaseSize()
{
    return baseSize;
}

TwoDArray::operator int()
{
    return baseSize;
}

TwoDArray::operator int *()
{
    int *NewSizes = new int[baseSize];
    for (int i = 0; i < baseSize; i++)
    {
        NewSizes[i] = sizes[i];
    }
    return NewSizes;
}

TwoDArray::operator int **()
{
    int **NewArray = new int *[baseSize];
    for (int i = 0; i < baseSize; i++)
    {
        NewArray[i] = new int[*sizes];
        for (int j = 0; j < *sizes; j++)
        {
            NewArray[i][j] = array[i][j];
        }
    }
    return NewArray;
}
