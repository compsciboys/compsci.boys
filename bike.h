#ifndef BIKE_H
#define BIKE_H

#include <string>

class bike: public vehicle 
{
	bool includeHelmet;

public:

	//Initialisers
	bike();
	bike(std::string registration, std::string brand, std::string make, int year, int price);

    //Setters
	bool includeHelmet();
    
    ~bike();

};

#endif
