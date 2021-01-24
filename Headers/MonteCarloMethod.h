#pragma once
#include "SolveVariant.h"
#include "Generator.h"

class MonteCarloMethod : public SolveVariant
{
private:
public:
    MonteCarloMethod(Generator *task);
    MonteCarloMethod(int N, double P, int M);
    ~MonteCarloMethod() = default;
    double solve(std::vector<int> &distributionRoster) override;
};