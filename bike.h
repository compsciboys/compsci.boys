#ifndef BIKE_H
#define BIKE_H

#include <string>

class bike: public vehicle 
{
	std::string healthInsurance;
    int numberOfWheels;

public:

	//Setters
	coupe();
	coupe(std::string registration, std::string brand, std::string make, std::string body_type, int year, int price);

	//Getters
	bool healthInsurance();

}
