#include <string>
#include "car.h"

car::car(){

	registration = "?";
	brand = "Default";
	model = "No Model";
	body_type = "No Body Type";
	price = 10000; 

}

car::car(std::string crego, std::string cbrand, std::string cmodel, std::string cbody_type, int cprice){

	registration = crego;
	brand = cbrand;
	model = cmodel;
	body_type = cbody_type;
	price = cprice; 

}
int car::getPrice(){

	return price;
}

std::string car::getRegistration(){

	return registration;
} 

std::string car::getModel(){

	return model; 
}

std::string car::getBrand(){

	return brand; 
}

std::string car::getBody_type(){

	return body_type;
}

void car::setPrice(int newPrice){

	price = newPrice;
}

void car::setRegistration(std::string newRego){

	registration = newRego;

}   



car::~car();