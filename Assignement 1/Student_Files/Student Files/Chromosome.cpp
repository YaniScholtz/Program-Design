#include <iostream>
#include "Chromosome.h"
using namespace std;

Chromosome::Chromosome(int numGenes, RandomGenerator *rand)
{
    if (numGenes < 0)
    {
        this->numGenes = 0;
    }


    this->numGenes = numGenes;
    this->genes = new bool[numGenes];
    if (rand == NULL)
    {
        for (int i = 0; i < numGenes; i++)
            genes[i] = false;
    }
    else
    {
        for (int i = 0; i < numGenes; i++)
        {
            genes[i] = rand->randomBool();
        }
    }
}

Chromosome::Chromosome(Chromosome *chromosome)
{
    if (chromosome == 0)
    {
        this->numGenes = 0;
    }
    else
    {
        this->numGenes = chromosome->getNumGenes();
    }
    bool *newGenes = new bool[this->numGenes];
    for (int i = 0; i < this->numGenes; i++)
    {
        newGenes[i] = chromosome->getGenes()[i];
    }
    this->genes = newGenes;
}

Chromosome::Chromosome(bool *genes, int numGenes)
{
    if (numGenes < 0)
    {
        this->numGenes = 0;
    }
    else
    {
        this->numGenes = numGenes;
    }
    this->genes = new bool[numGenes];
    if (genes == 0)
    {
        for (int i = 0; i < numGenes; i++)
        {
            this->genes[i] = false;
        }
    }
    else
    {
        for (int i = 0; i < numGenes; i++)
        {
            this->genes[i] = genes[i];
        }
    }
}
Chromosome::~Chromosome()
{
}
double Chromosome::fitness(FitnessFunction *fitnessFunction, Chromosome *chromosome, int numGenes)
{
    if (fitness == 0)
    {
        return 0;
    }
    else

        if (chromosome == 0)
    {
        return 0;
    }
    else

        if (numGenes <= 0)
    {
        return 0;
    }

    return fitnessFunction->calculateFitness(chromosome, numGenes);
}

int Chromosome::getNumGenes()
{
    return numGenes;
}

Chromosome *Chromosome::crossOver(Chromosome *c2)
{
    bool *nGenes;
    Chromosome *newChromosome;
    if (c2 == NULL)
    {
        bool *nGenes = new bool[this->getNumGenes()];
        for (int k = 0; k < this->getNumGenes(); k++)
        {
            nGenes[k] = this->genes[k];
        }
        newChromosome = new Chromosome(nGenes, numGenes);
    }
    else
    {
        bool *nGenes = new bool[c2->getNumGenes()];

        int crossoverPoint = floor(double(c2->getNumGenes()) / 2.0);

        for (int i = 0; i < crossoverPoint; i++)
        {
            nGenes[i] = this->genes[i];
        }

        for (int i = crossoverPoint; i < c2->getNumGenes(); i++)
        {
            nGenes[i] = c2->getGenes()[i];
        }
        newChromosome = new Chromosome(nGenes, c2->numGenes);
    }

    return newChromosome;
}

Chromosome *Chromosome::mutate()
{

    bool *nGenes = new bool[numGenes];
    for (int i = 0; i < numGenes; i++)

    {
        nGenes[i] = !genes[i];
    }
    Chromosome *chromo = new Chromosome(nGenes, this->numGenes);

    return chromo;
}

string Chromosome::toString()
{
    if (numGenes == 0)
    {
        return "";
    }
    string s; // remove dalk die = "";
    for (int i = 0; i < numGenes; i++)
    {
        if (genes[i] == true)
        {
            s = s + "1";
        }

        else
        {
            s = s + "0";
        }
    }
    return s;
}

bool *Chromosome::getGenes()
{
    return genes;
}
