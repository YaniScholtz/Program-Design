#include <iostream>
#include "IsSmaller.h"
using namespace std;

int IsSmaller::numAliveObjects = 0;

IsSmaller::IsSmaller(int value) : ValueDependantTester(value)
{
    numAliveObjects++;
    this->value = value;
}

IsSmaller::~IsSmaller()
{
    numAliveObjects--;
}
bool IsSmaller::evaluate(int val)
{
    if (val < value)
    {
        return true;
    }
    else
        return false;
}

NumberTester *IsSmaller::clone()
{
    NumberTester *prt = new IsSmaller(value);
    return prt;
}

int IsSmaller::getNumAliveObjects()
{
    return numAliveObjects;
}
