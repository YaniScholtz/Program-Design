#include <iostream>
#include "FitnessFunction.h"
using namespace std;

double FitnessFunction::calculateFitness(Chromosome *chromosome, int numGenes)
{
    double count = 0.0;
    double counter = 0.0;

    if (chromosome == NULL)
    {
        return 0;
    }

    if (numGenes == 0)
    {
        return 0;
    }
    for (int i = 0; i < numGenes; i++)
    {
        if (chromosome == 0)
        {
            return 0;
        }
        else if (chromosome->getGenes()[i] == true)
        {
            count++;
        }
        counter++;
    }

    return count / numGenes;
}
