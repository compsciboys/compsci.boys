#include <string>
#include "vehicle.h"
#include "coupe.h"

coupe::coupe():vehicle("??????", "Not Specified", "Not Specified", "Coupe", 2018, 0)
{

	numberOfSeats = 2;
	numberOfWheels = 4;
	performance  = "-1";
}

coupe::coupe(std::string crego, std::string cmake, std::string cmodel, int cyear, int cprice, int cperformance)
{
	
	numberOfSeats = 2;
	numberOfWheels = 4; 
	performance = cperformance;
}

coupe::getPerformance()
{
	return cperformance;
}

coupe::setPerformance(int cperformance)
{
	performance = cperformance;
}

coupe::~coupe() {}
