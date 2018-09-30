#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

class vehicle {

	std::string registration;
	std::string make;
	std::string model;
	std::string body_type;
	int year;
	int price; 


public: 

	vehicle();
	vehicle(std::string registration, std::string brand, std::string make, std::string body_type, int year, int price);
	
	int getPrice();
	int getYear();
	std::string getRegistration(); 
	std::string getMake();
	std::string getModel();
	std::string getBody_type();
	
	void setPrice(int newPrice);
	void setRegistration(std::string newRego);

	~vehicle();

};

#endif
