#include <iostream>
#include "IsDivisible.h"
using namespace std;
// sit dalk onder
int IsDivisible::numAliveObjects = 0;

IsDivisible::IsDivisible(int value) : ValueDependantTester(value)
{
    numAliveObjects++;
    this->value = value;
}

IsDivisible::~IsDivisible()
{
    numAliveObjects--;
}

bool IsDivisible::evaluate(int val)
{
    // ruil dalk?
    if (val % value == 0)
    {
        return true;
    }
    else
        return false;
}

NumberTester *IsDivisible::clone()
{
    NumberTester *ptr = new IsDivisible(value);
    return ptr;
}

int IsDivisible::getNumAliveObjects()
{
    return numAliveObjects;
}
