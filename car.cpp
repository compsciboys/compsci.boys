#include <string>
#include "car.h"

car::car(){

	registration = "??????";
	make = "Default";
	model = "No Model";
	body_type = "No Body Type";
	year = 2018;
	price = 10000; 

}

car::car(std::string crego, std::string cmake, std::string cmodel, std::string cbody_type, int cyear, int cprice){

	registration = crego;
	make = cmake;
	model = cmodel;
	body_type = cbody_type;
	year = cyear;
	price = cprice; 

}

int car::getPrice(){

	return price;
}

std::string car::getRegistration(){

	return registration;
} 

std::string car::getMake(){

	return make; 
}

std::string car::getModel(){

	return model;
}

std::string car::getBody_type(){

	return body_type;
}

int car::getYear(){

	return year;
}

void car::setPrice(int newPrice){

	price = newPrice;
}

void car::setRegistration(std::string newRego){

	registration = newRego;

}   

car::~car() {}