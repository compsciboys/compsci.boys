#include <string>
#include "vehicle.h"
#include "truck.h"

truck::truck():vehicle("??????", "Not Specified", "Not Specified", "Truck", 2018, 0)
{
	numberOfSeats = 2;
	numberOfWheels = 4;
	towingCap=0;
}

truck::truck(std::string registration, std::string make, std::string model, int year, int price, int towing):vehicle(registration, make, model, "Truck", year, price) {
	numberOfSeats = 2;
	numberOfWheels = 4;
	towingCap=towing;
}

int truck::getTowingCap()
{
	return towingCap;
}

void truck::setTowingCap(int ctowingCap)
{
	towingCap = ctowingCap;
}

truck::~truck() {}
