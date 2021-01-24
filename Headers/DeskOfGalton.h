#pragma once
#include <vector>
#include "SolveVariant.h"

class DeskOfGalton
{
private:
	SolveVariant *method;

public:
	DeskOfGalton(SolveVariant *method = nullptr);
	~DeskOfGalton();
	int getCount_n();
	double getFactor_P();
	int getCountTests_M();
	double CalculateDistribution(std::vector<int> &distributionRoster);
};
