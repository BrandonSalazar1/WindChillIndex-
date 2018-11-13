#include "windchillindex.h"
#include <iostream>
#include <string>
using namespace std;
//using namespace edu;


//double v;
//int t;
//double w;
//int x;
int main() {
	int edu::vcccd::csv13::computeWindChillIndex(double v, double t);
	double wind, temp;
	cout << "Enter velocity: ";
	cin >> wind;
	cout << "Enter the temperature: ";
	cin >> temp;
	//cout << "test : " << temp << endl;
	//cin >> x;
	cout << "temperature: " << temp << endl;
	cout << "wind chill" << edu::vcccd::csv13::computeWindChillIndex(wind, temp) << endl;
	//cout << "w" << w << endl;
	//return w;


}