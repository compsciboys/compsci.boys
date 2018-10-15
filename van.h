#ifndef VAN_H
#define VAN_H

#include <string>

class van: public vehicle 
{
	int strorageSpace;

public:

	//Initialisers 
	van();
	van(std::string registration, std::string brand, std::string make, std::string body_type, int year, int price);

	//Getters
	int getStrorageSpace();
    
    //Setters 
    int setStorageSpace();

    ~van();

};

#endif
