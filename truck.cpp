#include <string>
#include "vehicle.h"
#include "truck.h"

truck::truck()
{
	registration = "??????";
	model = "Not Specified";
	body_type = "truck";
	year = "2018";
	purchasePrice = "-1";
	numberOfSeats = 4;
	towingCap  = "-1";
}

truck::truck(std::string crego, std::string cmake, std::string cmodel, int cyear, int cprice, int ctowingCap)
{
	registration = crego;
	make = cmake;
	model = cmodel;
	body_type = "Coupe";
	year = cyear;
	purchasePrice = cprice;
	numberOfSeats = 4;
	towingCap = ctowingCap;
}

truck::getTowingCap()
{
	return towingCap;
}

truck::setTowingCap(int ctowingCap)
{
	towingCap = ctowingCap;
}

truck::~truck() {}
