#include <string>
#include "vehicle.h"
#include "bike.h"

bike::bike()
{
	registration = "??????";
	model = "Not Specified";
	body_type = "Bike";
	year = "2018";
	purchasePrice = "-1";
	numberOfWheels = 2;
	numberOfSeats = 1;
}

bike::bike(std::string crego, std::string cmake, std::string cmodel, int cyear, int cprice)
{
	registration = crego;
	make = cmake;
	model = cmodel;
	body_type = "Bike";
	year = cyear;
	purchasePrice = cprice;
	numberOfWheels = 2;
	numberOfSeats = 1;
}

bool includeHelmet();
{
	char input;

	if (includeHelmet == true)
	{
		std::cout << "You have already inclded a helmet in this sale" << endl;
	}
	else if (incldeHelmet == false)
	{
		std::cout << "A helmet has not been included in this sale, would you like to include a helmet? [Y/N]: ";
		std::cin >> input;

		switch(input)
		{
			case 'y' :
			includeHelmet = true; 
				cout << "A helmet has been included in this sale" << endl; 
				break;

			case 'n' : 
				incldeHelmet = false;
				cout << "A helmet will not be included in this sale" << endl;
				break;

			default :
				cout << "Invalid input, please enter y for 'yes' and n for 'no'" << endl;
		}
	}
}

bike::~bike() {}