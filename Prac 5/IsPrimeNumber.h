#ifndef ISPRIMENUMBER
#define ISPRIMENUMBER
#include "ValueIndependantTester.h"
#include <cstddef>
class IsPrimeNumber : public ValueIndependantTester
{

private:
    static int numAliveObjects;

public:
    IsPrimeNumber();
    ~IsPrimeNumber();
    bool evaluate(int val);
    NumberTester *clone();
    static int getNumAliveObjects();
};

#endif