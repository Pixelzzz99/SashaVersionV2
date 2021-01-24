#include "MonteCarloMethod.h"
#include <ctime>
#include <algorithm>
#include <random>

MonteCarloMethod::MonteCarloMethod(Generator *task)
{
    setCount_n(task->getNewN());
    setFactor_P(task->getNewP());
    setCountTests_M(task->getNewP());
}

MonteCarloMethod::MonteCarloMethod(int N, double P, int M)
{
    setCount_n(N);
    setFactor_P(P);
    setCountTests_M(M);
}

double MonteCarloMethod::solve(std::vector<int> &distributionRoster)
{
    int quantity = getCountTests_M();
    int mean = getCount_n() / 2;
    int highBoard = getCount_n();
    double randomFactor;
    std::vector<int> value(mean * 2 + 1, 0);
    double you_factor = getFactor_P();
    int index;
    std::srand((unsigned)time(nullptr));

    for (int i = 0; i < quantity; i++)
    {
        for (int j = 0; j < mean; j++)
        {
            randomFactor = (double)rand() / (RAND_MAX + 1);
            if (randomFactor <= you_factor)
            {
                if (!j)
                    index = mean + 1;
                else
                    index++;
            }
            else
            {
                if (!j)
                    index = mean;
                else
                    index--;
            }
        }
        value[index]++;
    }

    double sum = 0.0;
    for (int i = 0; i <= highBoard; i++)
    {
        distributionRoster.push_back(value[i]);;
        sum += value[i] * i;
    }

    double avg = (double)sum / quantity;
    return avg;
}
