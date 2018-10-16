#ifndef VAN_H
#define VAN_H

#include <string>

class van: public vehicle {
	int storageSpace;

public:

	//Initialisers 
	van();
	van(std::string registration, std::string make, std::string model, std::string body_type, int year, int price, int storage);

	//Getters
	int getStorageSpace();
    
    //Setters 
    void setStorageSpace(int cStorageSpace);

    ~van();

};

#endif
