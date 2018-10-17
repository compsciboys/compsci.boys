#include <string>
#include "vehicle.h"
#include "coupe.h"

coupe::coupe():vehicle("??????", "Not Specified", "Not Specified", "Coupe", 2018, 0) {
	numberOfSeats = 2;
	numberOfWheels = 4;
	performance  = 0;
}

coupe::coupe(std::string crego, std::string cmake, std::string cmodel, int cyear, int cprice, int cperformance):vehicle(crego, cmake, cmodel, "Coupe", cyear, cprice) {
	numberOfSeats = 2;
	numberOfWheels = 4; 
	performance = cperformance;
}

int coupe::getPerformance()
{
	return performance;
}

void coupe::setPerformance(int cperformance)
{
	performance = cperformance;
}

coupe::~coupe() {}
