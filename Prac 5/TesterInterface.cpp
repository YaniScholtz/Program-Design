#include "TesterInterface.h"

TesterInterface::TesterInterface(int maxNumTests)
{
    if (maxNumTests < 1)
    {
        maxNumTests = 0;

        testers = new NumberTester *[0];
        currNumTesters = 0;
    }
    else
    {
        this->maxNumTesters = maxNumTests;
        currNumTesters = 0;
        testers = new NumberTester *[maxNumTesters]; // array
    }
}

TesterInterface::TesterInterface(TesterInterface *other)
{

    if (other != NULL)
    {
        maxNumTesters = other->maxNumTesters;
        testers = new NumberTester *[other->maxNumTesters];
        currNumTesters = other->currNumTesters;
        for (int i = 0; i < other->maxNumTesters; i++)
        {
            if (other->testers[i] != NULL)
            {
                testers[i] = other->testers[i]->clone();
            }
            else
            {
                testers[i] = NULL;
            }
        }
    }
    else
    {
        maxNumTesters = 0;
        currNumTesters = 0;
        testers = new NumberTester *[0];
    }
}

TesterInterface::TesterInterface(TesterInterface &other)
{
    maxNumTesters = other.maxNumTesters;
    currNumTesters = other.currNumTesters;
    testers = new NumberTester *[other.maxNumTesters];
    for (int i = 0; i < maxNumTesters; i++)
    {
        if (other.testers[i] != NULL)
        {
            testers[i] = other.testers[i]->clone();
        }
        else
        {
            testers[i] = NULL;
        }
    }
}

TesterInterface::~TesterInterface()
{
    for (int i = 0; i < maxNumTesters; i++)
    {
        delete testers[i];
    }
    delete[] testers;
}

bool TesterInterface::removeTester(int pos)
{
    if ((pos < 0) || (pos > maxNumTesters))
    {
        return false;
    }
    else if (testers[pos] != NULL)
    {
        delete testers[pos];
        testers[pos] = NULL;
        currNumTesters--;
        return true;
    }
    else
    {
        return false;
    }
}

int TesterInterface::addTester(NumberTester *tester)
{
    if (maxNumTesters == currNumTesters)
    {
        return -1;
    }
    int counter = 0;

    if (tester != NULL)
    {
        for (int i = 0; i < maxNumTesters; i++)
        {
            if (testers[i] == NULL)
            {
                testers[i] = tester->clone();
                counter = i;
                currNumTesters++;

                return counter;
            }
        }
    }

    return -1;
}

NumberTester *TesterInterface::operator[](int pos)
{
    if ((pos < 0) || (pos > maxNumTesters))
    {
        return NULL;
    }
    else
        return testers[pos];
}

bool TesterInterface::evaluate(int num)
{
    if (testers == NULL)
    {
        return false;
    }
    for (int i = 0; i < maxNumTesters; i++)
    {
        if (testers[i])
        {
            if (testers[i]->evaluate(num) == false)
            {
                return false;
            }
        }
    }
    return true;
}

int TesterInterface::numberOfFailedTests(int num)
{
    int count = 0;
    if (testers == NULL)
    {
        return 0;
    }
    for (int i = 0; i < maxNumTesters; i++)
    {
        if (testers[i] != NULL)
        {
            if (testers[i]->evaluate(num) == false)
            {
                count++;
            }
        }
    }
    return count;
}

int *TesterInterface::failedTests(int num)
{
    int count = 0;
    for (int i = 0; i < maxNumTesters; i++)
    {
        if (testers[i])
            if (testers[i]->evaluate(num) == false)
                count++;
    }

    int *array = new int[count];
    int arrcounter = 0;
    for (int i = 0; i < maxNumTesters; i++)

    {
        if (testers[i])
            if (testers[i]->evaluate(num) == false)
            {
                array[arrcounter] = i;
                arrcounter++;
            }
    }
    return array;
}

int TesterInterface::getCurrNumTesters() const
{
    return currNumTesters;
}

int TesterInterface::getMaxNumTesters() const
{
    return maxNumTesters;
}
