#include <iostream>
#include <string>
#include "SumArray.h"
using namespace std;

SumArray::SumArray(int **array, int *sizes, int baseSize) : TwoDArray(array, sizes, baseSize)
{
}

int *SumArray::operator[](int index)
{
    int sum = 0;
    int *sumArray;

    int **newTwoArray = this->getArray();

    for (int i = 0; i < this->getSizes()[index]; i++)
    {
        sum += newTwoArray[index][i];
    }
    sumArray =   new int(sum);
    return sumArray;
}