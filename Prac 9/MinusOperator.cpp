

#include <iostream>
#include <cstddef>
#include "MinusOperator.h"
using namespace std;

template <class T>
T MinusOperator<T>::operator()(T lhs, T rhs)
{
    return lhs - rhs;
}

template <class T>
Operator<T> *MinusOperator<T>::clone()
{
    MinusOperator<T> *newobject = new MinusOperator<T>();
    return newobject;
}
