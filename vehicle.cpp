#include <string>
#include "vehicle.h"

vehicle::vehicle(){

	registration = "??????";
	make = "Default";
	model = "No Model";
	body_type = "No Body Type";
	year = 2018;
	price = 10000; 

}

vehicle::vehicle(std::string crego, std::string cmake, std::string cmodel, std::string cbody_type, int cyear, int cprice){

	registration = crego;
	make = cmake;
	model = cmodel;
	body_type = cbody_type;
	year = cyear;
	price = cprice; 

}

int vehicle::getPrice(){

	return price;
}

std::string vehicle::getRegistration(){

	return registration;
} 

std::string vehicle::getMake(){

	return make; 
}

std::string vehicle::getModel(){

	return model;
}

std::string vehicle::getBody_type(){

	return body_type;
}

int vehicle::getYear(){

	return year;
}

void vehicle::setPrice(int newPrice){

	price = newPrice;
}

void vehicle::setRegistration(std::string newRego){

	registration = newRego;

}   

vehicle::~vehicle() {}
