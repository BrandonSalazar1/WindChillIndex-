#ifndef WINDCHILLINDEX_H
#define WINDCHILLINDEX_H

#include <iostream>
#include <cmath>
namespace edu {
	namespace vcccd {
		namespace csv13 {
			int computeWindChillIndex(double v, double t);
			int computeWindChillIndex(double wind, double temp);
			//double w;
			//double wind, temp;
		}
	}
}


#endif // !WINDCHILLINDEX_H