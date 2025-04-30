#include <iostream>
#include "IsPrimeNumber.h"
using namespace std;

int IsPrimeNumber::numAliveObjects = 0;

IsPrimeNumber::IsPrimeNumber()
{
    numAliveObjects++;
}

IsPrimeNumber::~IsPrimeNumber()
{
    numAliveObjects--;
}

bool IsPrimeNumber::evaluate(int val)
{
    int count = 0;
    if (val < 2)
    {
        return false;
    }
    for (int i = 1; i < val; i++)
    {
        if (val % i == 0)
        {
            count++;
        }
    }

    if (count > 1)
    {
        return false;
    }
    else
        return true;
}

NumberTester *IsPrimeNumber::clone()
{
    NumberTester *ptr = new IsPrimeNumber();
    return ptr;
}

int IsPrimeNumber::getNumAliveObjects()
{
    return numAliveObjects;
}