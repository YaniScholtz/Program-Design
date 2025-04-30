#ifndef CALCULATOR_H
#define CALCULATOR_H

template <class T>
class Calculator
{
private:
    Stack<T> *valueStack;
    Stack<Operator<T> *> *operatorStack;

public:
    Calculator();
    ~Calculator();
    void addValue(T val);
    void addOperator(Operator<T> *op);
    Operator<T> *removeOperator();
    T removeValue();
    int numValues();
    T calculate();
    int numOperators();
};


#endif