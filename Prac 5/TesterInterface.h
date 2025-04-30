#ifndef TESTERINTERFACE
#define TESTERINTERFACE
#include "NumberTester.h"
#include <cstddef>
class TesterInterface
{

private:
    int maxNumTesters;
    int currNumTesters;
    NumberTester **testers;

public:
    TesterInterface(int maxNumTests);
    TesterInterface(TesterInterface *other);
    TesterInterface(TesterInterface &other);
    ~TesterInterface();
    int addTester(NumberTester *tester);
    bool removeTester(int pos);
    int *failedTests(int num);
    NumberTester *operator[](int pos);
    bool evaluate(int num);
    int getCurrNumTesters() const;
    int getMaxNumTesters() const;
    int numberOfFailedTests(int num);
};

#endif