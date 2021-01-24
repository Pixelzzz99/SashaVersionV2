#pragma once
#include <vector>

class SolveVariant
{
private:
    int n;
    double P;
    int M;
public:
    int getCount_n() const;
    void setCount_n(int count_n);
    double getFactor_P() const;
    void setFactor_P(double factor_p);
    int getCountTests_M() const;
    void setCountTests_M(int count_m);

    virtual double solve(std::vector<int> &distributionRoster) = 0;
    ~SolveVariant() = default;
};