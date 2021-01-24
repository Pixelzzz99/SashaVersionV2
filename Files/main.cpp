#include <iostream>
#include <vector>
#include "DeskOfGalton.h"
#include "BernoulliMethod.h"
#include "Generator.h"
#include "MonteCarloMethod.h"
#include <fstream>
#include <cmath>
#include <iomanip>

int Test1Bernoulli()
{
	DeskOfGalton *solveD = new DeskOfGalton(new BernoulliMethod(50, 0.5, 10000));
	std::vector<int> vect;
	double dist = solveD->CalculateDistribution(vect);
	std::cout << "Distribution: " << dist << std::endl;
	std::cout << std::endl;
	std::ofstream out1;
	out1.open("D:\\projects\\SashaVersionV2\\Graphs\\InfoBernuolli.txt");
	for (int i = 0; i < vect.size(); i++)
	{
		std::cout << i << "\t" << vect[i] << std::endl;
		out1 << i << std::endl;
		out1 << vect[i] << std::endl;
	}
	std::cout << std::endl;
	delete solveD;
	return 1;
}

int Test1MonteCarlo()
{
	DeskOfGalton *solveD = new DeskOfGalton(new MonteCarloMethod(50, 0.5, 10000));
	std::vector<int> vect;
	double dist = solveD->CalculateDistribution(vect);
	std::cout << "Distribution: " << dist << std::endl;
	std::cout << std::endl;
	std::ofstream out1;
	out1.open("D:\\projects\\SashaVersionV2\\Graphs\\InfoMonteCarlo.txt");
	for (int i = 0; i < vect.size(); i++)
	{
		std::cout << i << "\t" << vect[i] << std::endl;
		out1 << i << std::endl;
		out1 << vect[i] << std::endl;
	}
	std::cout << std::endl;
	delete solveD;
	return 1;
}

int Test2MonteCarloAndBernoulli()
{
	std::ofstream out1;
	out1.open("D:\\projects\\SashaVersionV2\\Graphs\\DistributionBernuolli.txt", std::ios::app);

	std::ofstream out2;
	out2.open("D:\\projects\\SashaVersionV2\\Graphs\\DistributionMonteCarlo.txt", std::ios::app);

	for (int i = 1; i < 10; i++)
	{

		double factor = (double)i / 100;
		DeskOfGalton *solveB = new DeskOfGalton(new BernoulliMethod(50, factor, 10000));
		DeskOfGalton *solveM = new DeskOfGalton(new MonteCarloMethod(50, factor, 10000));
		std::vector<int> vect1;
		std::vector<int> vect2;
		double dist1 = solveB->CalculateDistribution(vect1);
		double dist2 = solveM->CalculateDistribution(vect2);
		if (out1.is_open() && out2.is_open())
		{
			out1 << std::setprecision(20) << factor << std::endl;
			out2 << std::setprecision(20) << factor << std::endl;
			out1 << std::setprecision(20) << dist1 << std::endl;
			out2 << std::setprecision(20) << dist2 << std::endl;
		}
		delete solveB;
		delete solveM;
	}
	std::cout << "testFinished" << std::endl;
	return 1;
}

int TestMemory()
{
	std::ofstream out1;
	out1.open("D:\\projects\\SashaVersionV2\\Graphs\\Memory1.txt", std::ios::app);

	std::ofstream out2;
	out2.open("D:\\projects\\SashaVersionV2\\Graphs\\Memory2.txt", std::ios::app);
	int count_N = 10;
	int count_M = 100;

	for (int i = 1; i < 5; i++)
	{
		DeskOfGalton *solveB = new DeskOfGalton(new MonteCarloMethod(count_N, 0.5, count_M));
		DeskOfGalton *solveM = new DeskOfGalton(new BernoulliMethod(count_N, 0.5, count_M));
		std::vector<int> vect1;
		std::vector<int> vect2;

		long size1 = ((count_N * count_N) * sizeof(double)) + (count_M * sizeof(int)) + 24;
		long size2 = ((count_N * sizeof(int)) + (count_M * sizeof(int))) + 24;

		if (out1.is_open() && out2.is_open())
		{
			out1 << std::setprecision(20) << count_N << std::endl;
			out2 << std::setprecision(20) << count_N << std::endl;
			out1 << std::setprecision(20) << size1 << std::endl;
			out2 << std::setprecision(20) << size2 << std::endl;
		}
		delete solveB;
		delete solveM;
		count_N *= 10;
		count_M *= 10;
	}
	std::cout << "testFinished" << std::endl;
	return 1;
}

int main()
{
	std::cout.precision(40);
	//Test1Bernoulli();
	//Test1MonteCarlo();
	//Test2MonteCarloAndBernoulli();
	TestMemory();
	system("pause>nul");

	return 0;
}