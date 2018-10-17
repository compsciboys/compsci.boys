#ifndef BIKE_H
#define BIKE_H
#include "vehicle.h"

#include <string>
#include "vehicle.h"

class bike: public vehicle 
{
	bool includeHelmet;

public:

	//Initialisers
	bike();
	bike(std::string registration, std::string make, std::string model, int year, int price, bool includeHelmet);

	//Setters
	bool addHelmet();
	
   	//Getters
	bool getHelmet();
    
    ~bike();

};

#endif

