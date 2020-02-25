#include "functions.h"

int random_int(int begin, int end)
{
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(begin, end);
	return dist(mt);
}

float random_float(float begin, float end)
{
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<float> dist(begin, end);
	return dist(mt);
}