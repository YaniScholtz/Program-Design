#include <iostream>
#include "ValueIndependantTester.h"
using namespace std;

int ValueIndependantTester::numAliveObjects = 0;

ValueIndependantTester::ValueIndependantTester()
{
    numAliveObjects++;
}

ValueIndependantTester::~ValueIndependantTester()
{
    numAliveObjects--;
}

int ValueIndependantTester::getNumAliveObjects()
{
    return numAliveObjects;
}