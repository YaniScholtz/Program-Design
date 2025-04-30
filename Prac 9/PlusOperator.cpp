

#include <iostream>
#include <cstddef>
#include "PlusOperator.h"
using namespace std;

template <class T>
T PlusOperator<T>::operator()(T lhs, T rhs)
{
    return lhs + rhs;
}

template <class T>
Operator<T> *PlusOperator<T>::clone()
{
    PlusOperator<T> *newobject = new PlusOperator<T>();
    return newobject;
}
