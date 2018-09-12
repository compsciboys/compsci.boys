#ifndef CAR_H
#define CAR_H

#include <string>

class car {

	std::string registration;
	std::string brand;
	std::string model;
	std::string body_type;
	int price; 


public: 

	car();
	car(std::string registration, std::string brand, std::string model, std::string body_type, int price);
	int getPrice();
	std::string getRegistration(); 
	std::string getModel();
	std::string getBrand();
	std::string getBody_type();
	void setPrice(int newPrice);
	void setRegistration(std::string newRego);   



	~car();

};

#endif