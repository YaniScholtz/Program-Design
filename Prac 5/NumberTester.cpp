#include <iostream>
#include "NumberTester.h"
using namespace std;

int NumberTester::numAliveObjects = 0;

NumberTester::NumberTester()
{
    numAliveObjects++;
}

NumberTester::~NumberTester()
{
    numAliveObjects--;
}

int NumberTester::getNumAliveObjects()
{
    return numAliveObjects;
}