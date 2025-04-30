
#include <iostream>
#include <cstddef>
#include "Calculator.h"
using namespace std;

template <class T>
Calculator<T>::Calculator()
{
    // Net hakkies by gesit
    valueStack = new Stack<T>();
    operatorStack = new Stack<Operator<T> *>();
}

template <class T>
Calculator<T>::~Calculator()
{
}

template <class T>
void Calculator<T>::addValue(T val)
{

    valueStack->push(val);
}

template <class T>
void Calculator<T>::addOperator(Operator<T> *op)
{

    Operator<T> *deepOperator;
    deepOperator = op->clone();
    operatorStack->push(op);
}

template <class T>
T Calculator<T>::removeValue()
{

    if (valueStack->getTop() == NULL)
    {
        return NULL;
    }
    T val = valueStack->pop()->getData();
    return val;
}

template <class T>
Operator<T> *Calculator<T>::removeOperator()
{
    if (!operatorStack->getTop())
    {
        return NULL;
    }
    else
    {

        Node<Operator<T> *> *ptr = operatorStack->pop();

        return ptr->getData();
    }
}

template <class T>
int Calculator<T>::numValues()
{
    int count = 0;
    if (!valueStack->getTop())
        return 0;
    else
    {
        Node<T> *temp = valueStack->getTop();
        while (temp)
        {
            count++;
            temp = temp->getNext();
        }
    }

    return count;
}

template <class T>
int Calculator<T>::numOperators()
{
    int count = 0;
    if (!operatorStack->getTop())
        return 0;
    else
    {
        Node<Operator<T> *> *temp = operatorStack->getTop();
        while (temp)
        {
            count++;
            temp = temp->getNext();
        }
    }

    return count;
}

template <class T>
T Calculator<T>::calculate()
{

    if (operatorStack->isEmpty() || valueStack->isEmpty())
    {
        return NULL;
    }
    else
    {
        if (valueStack->size() < 2)

        {
            return NULL;
        }
        while (operatorStack->isEmpty() == false)
        {
            if (valueStack->isEmpty())
            {
                break;
            }
            Node<T> *first = valueStack->pop();
            Node<T> *second = valueStack->pop();
            Node<Operator<T> *> *op = operatorStack->pop();
            Operator<T> *opext;
            if (first == NULL || second == NULL)

            {
                if (first == NULL && second == NULL)
                {
                    break;
                }
                if (first == NULL)
                {
                    valueStack->push(second->getData());
                }
                valueStack->push(first->getData());
                break;
            }
            opext = op->getData();
            T inter = opext->operator()(first->getData(), second->getData());
            valueStack->push(inter);
        }
        return valueStack->getTop()->getData();
    }
}
