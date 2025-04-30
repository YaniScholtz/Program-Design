#include <iostream>
#include "IsGreater.h"
using namespace std;

int IsGreater::numAliveObjects = 0;

IsGreater::IsGreater(int value) : ValueDependantTester(value)
{
    numAliveObjects++;
    this->value = value;
}

IsGreater::~IsGreater()
{
    numAliveObjects--;
}

bool IsGreater::evaluate(int val)
{
    if (val > value)
    {
        return true;
    }
    else
        return false;
}

NumberTester *IsGreater::clone()
{
    NumberTester *ptr = new IsGreater(value);
    return ptr;
}

int IsGreater::getNumAliveObjects()
{
    return numAliveObjects;
}