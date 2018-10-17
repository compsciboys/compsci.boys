#ifndef COUPE_H
#define COUPE_H

#include <string>
#include "vehicle.h"

class coupe: public vehicle 
{
	int performance;

public:

	//Initialisers
	coupe();
	coupe(std::string registration, std::string make, std::string model, int year, int price, int performance);

	//Getters
	int getPerformance();
    
    //Setters
    void setPerformance(int performance);
    
    
    ~coupe();

};

#endif
