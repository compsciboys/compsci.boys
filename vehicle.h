#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

class vehicle {
	std::string registration;
	std::string make;
	std::string model;
	std::string body_type;
	int year;
	int purchasePrice; 
protected:
	int numberOfSeats;
	int numberOfWheels;
public: 

	vehicle();
	vehicle(std::string registration, std::string make, std::string model, std::string body_type, int year, int price);
	
	int getPrice();
	int getYear();
	std::string getRegistration(); 
	std::string getMake();
	std::string getModel();
	std::string getBody_type();
	int getNumSeats();
	int getNumWheels();

	void setPrice(int cPrice);
	void setYear(int cYear);
	void setRegistration(std::string newRego); 
	void setMake(std::string cMake);
	void setModel(std::string cModel);
	void setBody_type(std::string cBodyType);

	~vehicle();

};

#endif
