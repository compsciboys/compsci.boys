#include <string>
#include "vehicle.h"
#include "coupe.h"

coupe::coupe()
{
	registration = "??????";
	model = "Not Specified";
	body_type = "Coupe";
	year = "2018";
	purchasePrice = "-1";
	numberOfSeats = 2;
	performance  = "-1";
}

coupe::coupe(std::string crego, std::string cmake, std::string cmodel, int cyear, int cprice, int cperformance)
{
	registration = crego;
	make = cmake;
	model = cmodel;
	body_type = "Coupe";
	year = cyear;
	purchasePrice = cprice;
	numberOfSeats = 2;
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