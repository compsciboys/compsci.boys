#ifndef TRUCK_H
#define TRUCK_H

#include <string>

class truck: public vehicle {
	int towingCap;

public:

	//Initialisers
	truck();
	truck(std::string registration, std::string make, std::string model, std::string body_type, int year, int price, int towingCap);

	//Getters
	int getTowingCap();
    
    //Setters
    void setTowingCap(int cTowing);

    ~truck();

};

#endif
