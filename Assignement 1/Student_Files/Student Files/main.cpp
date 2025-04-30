#include <iostream>
#include <ctime>

#include "Chromosome.h"
#include "FitnessFunction.h"
#include "GA.h"
#include "RandomGenerator.h"

using namespace std;

double avg(double **arr, int d, int size)
{
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i][d];
    }
    return sum / size;
}

void benchMark(int numGenerations, int popSize, int selectionSize, int numGenes, long seed, bool generationResults, bool timeResults)
{
    RandomGenerator *randomGenerator = new RandomGenerator(seed);
    FitnessFunction *fitnessFunction = new FitnessFunction();
    GA *ga = new GA(popSize, randomGenerator, numGenes, selectionSize);
    clock_t startTime = clock();
    double **results = ga->run(fitnessFunction, numGenerations);
    clock_t endTime = clock();
    cout << "---" << endl;
    if (generationResults)
    {
        for (int i = 0; i < numGenerations; i++)
        {
            cout << "Gen " << i << endl;
            cout << "Avg accuracy: " << results[i][0] << endl;
            cout << "Std: " << results[i][1] << endl;
            cout << "Variance: " << results[i][2] << endl;
            cout << "---" << endl;
        }
    }

    cout << "Run summary: " << endl;
    cout << "Avg avg: " << avg(results, 0, numGenerations) << endl;
    cout << "Avg std: " << avg(results, 1, numGenerations) << endl;
    cout << "Avg var: " << avg(results, 2, numGenerations) << endl;
    if (timeResults)
        cout << "Execution time: " << difftime(endTime, startTime) / 1000 << "ms" << endl;

    for (int i = 0; i < numGenerations; i++)
    {
        delete[] results[i];
    }
    delete[] results;
    delete ga;
    delete fitnessFunction;
    delete randomGenerator;
}

void studentMain()
{

    Chromosome **p = new Chromosome *[10];
    for (int i = 0; i < 10; i++)
    {
        bool *arr = new bool[10];
        for (int j = 0; j < 10; j++)
        {
            arr[j] = j % 2;
            if (j == i)
            {
                arr[j] = false;
            }
        }
        p[i] = new Chromosome(arr, 10);
        delete[] arr;
    }
    // //new
    // for (int i = 0; i < 10; i++) {
    //     cout << "num of genes: " << p[i]->getNumGenes() << endl;
    //     cout << "p[" << i << "] is: ";
    //     for (int k = 0; k < p[i]->getNumGenes(); k++) {
    //         cout << p[i]->getGenes()[k];
    //     }
    //     cout << endl << endl;

    // }
    // //endnew
    RandomGenerator *rand = new RandomGenerator(12345);
    FitnessFunction *fitnessFunction = new FitnessFunction();
    GA *ga = new GA(10, rand, 10, 1);
    ga->setPopulation(p);
    for (int i = 0; i < 10; i++)
    {
        delete p[i];
    }
    delete[] p;

    cout << ga->calculateAvgAccuracy(fitnessFunction) << endl;
    cout << ga->calculateStd(fitnessFunction) << endl;
    cout << ga->calculateVariance() << endl;
    p = ga->run(fitnessFunction);
    ga->setPopulation(p);
    cout << ga->calculateAvgAccuracy(fitnessFunction) << endl;
    cout << ga->calculateStd(fitnessFunction) << endl;
    cout << ga->calculateVariance() << endl;
    for (int i = 0; i < 10; i++)
    {
        delete p[i];
    }
    delete[] p;
    delete ga;
    delete rand;
    delete fitnessFunction;
    // numgen pops select numgenes seed
    // run 1 net var verkeerd
    benchMark(100, 100, 5, 10, 1, true, true);
    // run 2 letterlik perfek nou
    // benchMark(1000, 1000, 10, 5, 12345, true, true);
    // run 3 niks net var verkeerd
    // benchMark(50, 50, 2, 10, 8888, true, false);
    // run 4 alles verkeerd 13.5 min execution time
    // benchMark(1000, 1000, 100, 100, 5050, true, true);
    ////run 5 net var verkeerd (0.0995333)
    // benchMark(75, 200, 10, 10, 1, true, true);
    // run 6  is exactly right
    // benchMark(10, 10, 1, 100, 44, true, true);
    // run 7 alles is af met bietjie
    // benchMark(50, 700, 70, 5, 54321, true, true);
    // default
    // benchMark(10, 10, 1, 10, 500, true, false);

    // benchMark(10, 10, 1, 10, 500, true, false);
}

int main()
{
    studentMain();
    return 0;
}