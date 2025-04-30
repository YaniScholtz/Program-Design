#ifndef ISGREATER
#define ISGREATER
#include "ValueDependantTester.h"
#include <cstddef>
class IsGreater : public ValueDependantTester
{

private:
    static int numAliveObjects;

public:
    IsGreater(int value);
    ~IsGreater();
    bool evaluate(int val); 
    NumberTester* clone(); 
    static int getNumAliveObjects(); 
};

#endif