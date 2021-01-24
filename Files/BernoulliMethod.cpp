#include "BernoulliMethod.h"
#include <cmath>

BernoulliMethod::BernoulliMethod(Generator *task)
{
	setCount_n(task->getNewN());
	setFactor_P(task->getNewP());
	setCountTests_M(task->getNewP());
}

BernoulliMethod::BernoulliMethod(int N, double P, int M)
{
	setCount_n(N);
	setFactor_P(P);
	setCountTests_M(M);
}

std::vector<std::vector<double>> BernoulliMethod::resizeTable(int vert, int hor)
{
	std::vector<std::vector<double>> table;
	table.resize(vert+1);
	for(int i = 0; i < vert+1; i++)
		table[i].resize(hor+1);
	return table;	
}

double BernoulliMethod::solve(std::vector<int> &distributionRoster)
{
	int n = getCount_n();
	std::vector<std::vector<double>> table = resizeTable(n, n);
	 
	table[1][1] = 1.0;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (j <= i - 1)
			{															// 1 ... i-1
				table[i][j] += table[i - 1][j] * (1.0 - getFactor_P()); // left
			}
			if (j - 1 >= 1)
			{
				table[i][j] += table[i - 1][j - 1] * getFactor_P(); // right
			}
		}
	}
	int m = getCountTests_M();
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		int round = std::round(table[n][i] * m);
		sum += round * i ;
		distributionRoster.push_back(round);
	}	
	return (double)sum / m; 
}
