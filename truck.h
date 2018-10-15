#ifndef TRUCK_H
#define TRUCK_H

#include <string>

class truck: public vehicle 
{
	int towingCap;

public:

	//Initialisers
	truck();
	truck(std::string registration, std::string brand, std::string make, std::string body_type, int year, int price);

	//Getters
	int getTowingCap();
    
    //Setters
    int setTowingCap();

    ~truck();

};

#endif
