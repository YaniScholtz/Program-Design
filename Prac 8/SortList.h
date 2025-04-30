#ifndef DLL_H
#define DLL_H

#include "SortNode.h"

// SortList class Implementation here

template <class T>
class SortList
{
private:
    bool ascending;
    SortNode<T> *head;
    SortNode<T> *tail;

public:
    SortList(bool asc);
    void add(SortNode<T> *a);
    SortNode<T> *remove(T val);
    void sort();
    std::string print();
    SortNode<T> *getHead();
    void setAsc(bool);
    string debug();
};

#include "SortList.cpp"

#endif
