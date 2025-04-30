
#include <iostream>
#include <cstddef>
#include "Stack.h"
using namespace std;

template <class T>
Stack<T>::Stack()
{
    top = NULL;
}

template <class T>
Stack<T>::~Stack()
{
}

template <class T>
int Stack<T>::size()
{
    int count = 0;
    if (!top)
        return 0;
    else
    {
        Node<T> *temp = top;

        while (temp)
        {
            count++;
            temp = temp->getNext();
        }
        return count;
    }
}

template <class T>
bool Stack<T>::isEmpty()
{
    bool flag;
    if (!top)
        flag = true;
    else
        flag = false;
    return flag;
}

template <class T>
void Stack<T>::push(T data)
{
    Node<T> *newnode = new Node<T>(data);

    if (top)
    {
        newnode->setNext(top);
        top = newnode;
    }
    else
    {

        top = newnode;
    }
}

template <class T>
Node<T> *Stack<T>::pop()
{
    if (!top)
        return NULL;
    else
    {
        Node<T> *temp = top;
        top = temp->getNext();

        return temp;
    }
}

template <class T>
Node<T> *Stack<T>::getTop()
{
    if (!top)
        return NULL;
    else
        return top;
}

template <class T>
bool Stack<T>::contains(T data)
{
    Node<T> *ptr;
    ptr = top;
    bool flag = false;
    while (ptr)
    {
        if (ptr->getData() == data)
        {
            flag = true;
            break;
        }

        ptr = ptr->getNext();
    }

    if (flag == false)
        return false;
    else

        return true;
}

template <class T>
Stack<T> *Stack<T>::reverse()
{
    Stack<T> *newStack = new Stack<T>();

    if (!this->top)
    {
        return newStack;
    }

    else
    {
        T val;
        Node<T> *ptr = top;
        while (ptr)
        {

            val = ptr->getData();
            newStack->push(val);

            ptr = ptr->getNext();
        }

        return newStack;
    }
}
