#ifndef COUPE_H
#define COUPE_H

#include <string>

class coupe: public vehicle 
{
	int performance;

public:

	//Initialisers
	coupe();
	coupe(std::string registration, std::string brand, std::string make, int year, int price);

	//Getters
	int getPerformance();
    
    //Setters
    int setPerformance();
    
    
    ~coupe();

};

#endif
