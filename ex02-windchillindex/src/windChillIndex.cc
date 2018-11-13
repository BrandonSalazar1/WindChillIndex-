#include "windchillindex.h"
#include <iostream>
#include <cmath>
using namespace std;
using namespace edu;

int edu::vcccd::csv13::computeWindChillIndex(double v, double t)
{
	double w;
	//v = 0.0;
	//t = 0.0;
	
	w = 33 - (((10 * sqrt(v) - v + 10.5)*(33 - t)) / 23.1);

	system("pause");
	
	//return w;
	return 0;
	system("pause");
}

