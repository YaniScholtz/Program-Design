#include <iostream>
#include <string>
#include "SortArray.h"
using namespace std;

SortArray::SortArray(int **array, int *sizes, int baseSize) : TwoDArray(array, sizes, baseSize)
{
}

int *SortArray::operator[](int index)
{

    int *SortedArray;
    int temp = 0;
    SortedArray = new int[this->getSizes()[index]];

    for (int i = 0; i < this->getSizes()[index]; i++)
    {
        SortedArray[i] = this->getArray()[index][i];
    }

    for (int i = 0; i < this->getSizes()[index] - 1; i++)
    {
        for (int j = i + 1; j < this->getSizes()[index]; j++)
        {
            if (SortedArray[i] > SortedArray[j])
            {
                temp = SortedArray[i];
                SortedArray[i] = SortedArray[j];
                SortedArray[j] = temp;
            }
        }
    }
    return SortedArray;
}