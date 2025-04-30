#include <iostream>
#include <string>
#include "CountArray.h"

using namespace std;

CountArray::CountArray(int **array, int *sizes, int baseSize) : TwoDArray(array, sizes, baseSize)

{
}

int *CountArray::operator[](int index)
{

    int *number;
    *number = this->getSizes()[index];
    return number;
}