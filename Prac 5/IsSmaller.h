#ifndef ISSMALLER
#define ISSMALLER
#include "ValueDependantTester.h"
#include <cstddef>
class IsSmaller : public ValueDependantTester
{

private:
    static int numAliveObjects;

public:
    IsSmaller(int value);
    ~IsSmaller();
    bool evaluate(int val);
    NumberTester *clone();
    static int getNumAliveObjects();
};

#endif