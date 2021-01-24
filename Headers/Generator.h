#pragma once
#include <cstdlib>
#include <ctime>

class Generator
{
private:
	const int MIN = 2;
	const int MAX = 60;
	int _new_n;
	double _new_P;
	int _new_M;
	int random(int MIN, int MAX);
	
public:
	int getNewN();
	double getNewP();
	int getNewM();
	Generator();
	Generator(int N, int P, int M);
	~Generator() = default;
};

