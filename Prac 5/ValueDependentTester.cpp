#include <iostream>
#include "ValueDependantTester.h"
using namespace std;

int ValueDependantTester::numAliveObjects = 0;

ValueDependantTester::ValueDependantTester(int val)
{
    value = val;
    numAliveObjects++;
}

ValueDependantTester::~ValueDependantTester()
{
    numAliveObjects--;
}

int ValueDependantTester::getNumAliveObjects()
{
    return numAliveObjects;
}
