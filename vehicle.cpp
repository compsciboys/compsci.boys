#include <string>
#include "vehicle.h"

vehicle::vehicle(){

	registration = "??????";
	make = "Default";
	model = "No Model";
	body_type = "No Body Type";
	year = 2018;
	purchasePrice = 10000; 

}

vehicle::vehicle(std::string crego, std::string cmake, std::string cmodel, std::string cbody_type, int cyear, int cprice){

	registration = crego;
	make = cmake;
	model = cmodel;
	body_type = cbody_type;
	year = cyear;
	purchasePrice = cprice; 

}

int vehicle::getPrice(){

	return purchasePrice;
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


void vehicle::setRegistration(std::string newRego){

	registration = newRego;

}   

vehicle::~vehicle() {}
