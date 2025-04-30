#include <iostream>
#include "IsEvenOdd.h"
using namespace std;

int IsEvenOdd::numAliveObjects = 0;

IsEvenOdd::IsEvenOdd()
{
    numAliveObjects++;
}

IsEvenOdd::~IsEvenOdd()
{
    numAliveObjects--;
}

bool IsEvenOdd::evaluate(int val)
{
    if (val % 2 == 0)
        return true;
    else
        return false;
}

NumberTester *IsEvenOdd::clone()
{
    NumberTester *ptr = new IsEvenOdd();
    return ptr;
}

int IsEvenOdd::getNumAliveObjects()
{
    return numAliveObjects;
}
