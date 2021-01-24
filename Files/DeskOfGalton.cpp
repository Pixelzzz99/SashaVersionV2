#include "DeskOfGalton.h"

DeskOfGalton::DeskOfGalton(SolveVariant *method)
{
	this->method = method;
}

DeskOfGalton::~DeskOfGalton()
{
	delete method;
}

int DeskOfGalton::getCount_n()
{
	return this->method->getCount_n();
}

double DeskOfGalton::getFactor_P()
{
	return this->method->getFactor_P();
}

int DeskOfGalton::getCountTests_M()
{
	return this->method->getCountTests_M();
}

double DeskOfGalton::CalculateDistribution(std::vector<int> &distributionRoster)
{
	return this->method->solve(distributionRoster);
}
