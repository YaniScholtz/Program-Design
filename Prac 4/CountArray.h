#ifndef COUNTARRAY_H
#define COUNTARRAY_H
#include "TwoDArray.h"

class CountArray : public TwoDArray
{
public:
    CountArray(int **array, int *sizes, int baseSize);
   virtual int *operator[](int);
};

#endif