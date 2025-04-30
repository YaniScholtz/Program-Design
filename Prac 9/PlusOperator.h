#ifndef PLUSOPERATOR_H
#define PLUSOPERATOR_H

template <class T>
class PlusOperator : public Operator<T>
{
public:
    T operator()(T lhs, T rhs);
    Operator<T> *clone();
};



#endif