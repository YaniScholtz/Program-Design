#include <iostream>

using namespace std;

template <class T>
SortNode<T>::SortNode(T val)
{

    value = val;
    next = NULL;
    prev = NULL;
}

template <class T>
T SortNode<T>::getValue()
{
    return value;
}

template <class T>
std::string SortNode<T>::print()
{
    stringstream temp;
    temp << value;
    return temp.str();
}
