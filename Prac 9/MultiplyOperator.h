#ifndef MULTIPLYOPERATOR_H
#define MULTIPLYOPERATOR_H

template <class T>
class MultiplyOperator : public Operator<T>
{
public:
    T operator()(T lhs, T rhs);

    Operator<T> *clone();
};


#endif