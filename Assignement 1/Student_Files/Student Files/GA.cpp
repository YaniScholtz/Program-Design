#include <iostream>
#include "GA.h"
using namespace std;

GA::GA(int populationSize, RandomGenerator *rand, int numGenes, int selectionSize)
{

    this->populationSize = populationSize;
    this->selectionSize = selectionSize;
    population = new Chromosome *[populationSize]; // creates 1D array
    for (int i = 0; i < populationSize; i++)
    {
        population[i] = new Chromosome(numGenes, rand);
    }
}

GA::GA(GA *geneticAlgorithm)
{
    this->populationSize = geneticAlgorithm->populationSize;
    this->selectionSize = geneticAlgorithm->selectionSize;
    population = new Chromosome *[populationSize];
    for (int u = 0; u < populationSize; u++)
    {
        population[u] = new Chromosome(geneticAlgorithm->population[u]);
    }
}

GA::~GA()
{
}

Chromosome **GA::selection(FitnessFunction *fitnessFunction)
{
    ///////
    if (fitnessFunction == NULL)
    {
        return 0;
    }

    Chromosome **New = new Chromosome *[populationSize];
    Chromosome *temp;
    for (int j = 0; j < populationSize; j++)
    {
        New[j] = new Chromosome(population[j]);
        New[j] = population[j];
    }
    for (int j = 0; j < populationSize; j++)
    {
        for (int x = 0; x < populationSize - 1 - j; x++)
        {
            if (fitnessFunction->calculateFitness(New[x], New[x]->getNumGenes()) < fitnessFunction->calculateFitness(New[x + 1], New[x + 1]->getNumGenes()))
            {
                temp = New[x];
                New[x] = New[x + 1];
                New[x + 1] = temp;
            }
        }
        temp = NULL;
    }

    return New;
}

Chromosome **GA::inverseSelection(FitnessFunction *fitnessFunction)
{

    if (fitnessFunction == NULL)
    {
        return 0;
    }

    Chromosome **New = new Chromosome *[populationSize];
    Chromosome *temp;
    for (int j = 0; j < populationSize; j++)
    {

        New[j] = new Chromosome(population[j]);

        New[j] = population[j];
    }

    for (int y = 0; y < populationSize / 2; y++)
    {
        temp = New[y];

        New[y] = New[populationSize - y - 1];

        New[populationSize - y - 1] = temp;
    }
    for (int i = 0; i < populationSize; i++)
    {
        for (int j = 0; j < populationSize - 1 - i; j++)
        {

            if (fitnessFunction->calculateFitness(New[j], New[j]->getNumGenes()) > fitnessFunction->calculateFitness(New[j + 1], New[j + 1]->getNumGenes()))
            {
                temp = New[j];

                New[j] = New[j + 1];

                New[j + 1] = temp;
            }
        }
    }

    return New;
}

Chromosome **GA::crossOver(Chromosome *c1, Chromosome *c2)
{

    if ((c1 == NULL) || (c2 == NULL))
    {
        return 0;
    }

    Chromosome **result = new Chromosome *[2]; // creates 1D array
    result[0] = c1->crossOver(c2);

    result[1] = c2->crossOver(c1);

    return result;
}

Chromosome *GA::mutate(Chromosome *c1)
{

    if (c1 == NULL)
    {
        return 0;
    }

    Chromosome *Chromo = c1->mutate();
    return Chromo;
}

double GA::calculateAvgAccuracy(FitnessFunction *fitnessFunction)
{

    if (fitnessFunction == NULL)
    {
        return 0;
    }

    double result = 0.0;
    double sumfit = 0.0;
    for (int i = 0; i < populationSize; i++)
    {
        if (population[i] != NULL)
        {
            sumfit += fitnessFunction->calculateFitness(population[i], population[i]->getNumGenes());
        }
    }
    result = sumfit / populationSize;

    return result;
}

double GA::calculateStd(FitnessFunction *fitnessFunction)
{

    if (fitnessFunction == NULL)
    {
        return 0;
    }

    double result = 0.0;
    double bo = 0.0;

    double avg = calculateAvgAccuracy(fitnessFunction);

    for (int i = 0; i < populationSize; i++)
    {

        bo = bo + pow(fitnessFunction->calculateFitness(population[i], population[i]->getNumGenes()) - avg, 2);
    }
    result = sqrt(bo / populationSize);
    return result;
}

double GA::calculateVariance()
{

    double results = 0.0;
    double above = 0.0;

    int notunique = 0;

    bool flag = false;

    for (int k = 0; k < this->populationSize - 1; k++)
    {
        for (int u = k + 1; u < this->populationSize; u++)
        {
            if (population[k]->toString() == population[u]->toString())
            {
                notunique++;

                break;
            }
        }
    }

    above = populationSize - (double(notunique));
    double calVariance = above / this->populationSize;
    return calVariance;
}

void GA::setPopulation(Chromosome **p)
{

    for (int i = 0; i < populationSize; i++)
    {
        Chromosome *pop = new Chromosome(p[i]);
        population[i] = pop;
    }
}

Chromosome **GA::run(FitnessFunction *fitnessFunction)
{

    if (fitnessFunction == NULL)
    {
        return 0;
    }

    Chromosome **winners = selection(fitnessFunction);
    Chromosome **losers = inverseSelection(fitnessFunction);
    Chromosome **Offsprings = new Chromosome *[3 * selectionSize];
    Chromosome **p = new Chromosome *[populationSize];

    Chromosome **nChromosomes;
    for (int i = 0; i < (2 * selectionSize); i++)
    {
        nChromosomes = this->crossOver(winners[i], winners[i + 1]);
        Offsprings[i] = nChromosomes[0];

        Offsprings[i + 1] = nChromosomes[1];
        i++;
    }
    for (int k = 0; k < selectionSize; k++)
    {
        Offsprings[k + (2 * selectionSize)] = mutate(winners[k + (2 * selectionSize)]);
    }

    for (int i = 0; i < populationSize; i++)

    {
        p[i] = population[i];
    }
    int u = 0;
    Chromosome *dyingchrommosome;
    for (int y = 0; y < 3 * selectionSize; y++)

    {
        dyingchrommosome = losers[y];
        for (int i = 0; i < populationSize; i++)
        {

            if (dyingchrommosome == p[i])

            {
                u = i;

                break;
            }
        }
        p[u] = Offsprings[y];
    }

    return p;
}

double **GA::run(FitnessFunction *fitnessFunction, int numGenerations)
{

    if (numGenerations == 0)
    {
        return 0;
    }
    else if (fitnessFunction == NULL)
    {
        return 0;
    }

    double **results = new double *[numGenerations];
    for (int g = 0; g < numGenerations; g++)
    {
        results[g] = new double[3];
    }
    Chromosome **newPop;

    for (int i = 0; i < numGenerations; i++)
    { // cout << "i: " << i << endl ;
        newPop = run(fitnessFunction);
        population = newPop;

        results[i][0] = calculateAvgAccuracy(fitnessFunction);

        results[i][1] = calculateStd(fitnessFunction);

        results[i][2] = calculateVariance();
    }

    return results;
}
