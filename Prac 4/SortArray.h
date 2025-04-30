#ifndef SORTARRAY_H
#define SORTARRAY_H
#include "TwoDArray.h"

class SortArray : public TwoDArray
{
    public: 
    SortArray(int **array, int *sizes, int baseSize) ;

    virtual int *operator[](int);
};

#endif