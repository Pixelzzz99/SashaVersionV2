#pragma once
#include "SolveVariant.h"
#include "Generator.h"

class BernoulliMethod :public SolveVariant
{
private:
	std::vector<std::vector<double>> resizeTable(int vert, int hor);
public:
	BernoulliMethod(Generator *task);
	BernoulliMethod(int N, double P, int M);
	~BernoulliMethod() = default;
	double solve(std::vector<int> &distributionRoster) override;	
};

