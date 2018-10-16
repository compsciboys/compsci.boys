#include <string>
#include <iostream>
#include "vehicle.h"
#include "bike.h"

bike::bike():vehicle("??????", "Not Specified", "Not Specified", "Bike", 2018, 0)
{
	numberOfWheels = 2;
	numberOfSeats = 1;
}

bike::bike(std::string registration, std::string make, std::string model, int year, int price, bool includeHelmet):vehicle(registration, make, model, "Bike", year, price)
{
	numberOfWheels = 2;
	numberOfSeats = 1;
}

bool bike::addHelmet()
{
	if (includeHelmet == false)
	{
		includeHelmet = true;
		return true;
	}
	else if (includeHelmet == true)
	{
		return false;
	}
}

bool bike::getHelmet()
{
	return includeHelmet;
}


bike::~bike() {}