#include <iostream>
#include "RandomGenerator.h"
using namespace std;

RandomGenerator::RandomGenerator(int seed)
{
    srand(seed);

    this->seed = seed;
}

bool RandomGenerator::randomBool()
{
    int random;
    random = rand();
    if (random % 2 == 0)
    {
        return false;
    }
    else
        return true;
}