#ifndef MINUSOPERATOR_H
#define MINUSOPERATOR_H

template <class T>
class MinusOperator : public Operator<T>
{
public:
    T operator()(T lhs, T rhs);
    Operator<T> *clone();
};


#endif