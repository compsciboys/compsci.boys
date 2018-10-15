#include <string>
#include "vehicle.h"
#include "van.h"

van::van()
{
	registration = "??????";
	model = "Not Specified";
	body_type = "Van";
	year = "2018";
	purchasePrice = "-1";
	numberOfSeats = 2;
	storageSpace  = "-1";
}

van::van(std::string crego, std::string cmake, std::string cmodel, int cyear, int cprice, int cstorageSpace)
{
	registration = crego;
	make = cmake;
	model = cmodel;
	body_type = "Van";
	year = cyear;
	purchasePrice = cprice;
	numberOfSeats = 2;
	storageSpace = cstorageSpace;
}

van::getStroageSpace()
{
	return storageSpace;
}

van::storageSpace(int cstorageSpace)
{
	storageSpace = cstorageSpace;
}

van::~van() {}
