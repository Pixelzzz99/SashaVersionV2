#include "Generator.h"


Generator::Generator() {
	srand(RAND_MAX);
	//srand(time(nullptr));
	_new_n = random(MIN, MAX);
	int temp_P = random(MIN, MAX);
	if ((temp_P / 10) == 0)
	{
		_new_P = (double)temp_P / 10;
	}
	else
	{
		_new_P = (double)temp_P / 100;
	}
}

Generator::Generator(int N, int P, int M)
{
	this->_new_n = N;
	this->_new_P = P;
	this->_new_M = M;
}

int Generator::getNewN() {
	return _new_n;
}

double Generator::getNewP() {
	return _new_P;
}

int Generator::getNewM()
{
	return _new_M;
}

int Generator::random(int MIN, int MAX) {
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<int>(rand() * fraction * (MAX - MIN + 1) + MIN);
}
