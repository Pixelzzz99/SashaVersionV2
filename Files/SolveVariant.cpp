#include "SolveVariant.h"

int SolveVariant::getCount_n() const
{
    return n;
}

void SolveVariant::setCount_n(int count_n)
{
    this->n = count_n;
}

double SolveVariant::getFactor_P() const
{
    return P;
}

void SolveVariant::setFactor_P(double factor_p)
{
    this->P = factor_p;
}

int SolveVariant::getCountTests_M() const
{
    return M;
}

void SolveVariant::setCountTests_M(int count_m)
{
    this->M = count_m;
}