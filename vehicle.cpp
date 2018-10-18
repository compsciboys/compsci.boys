#include <string>
#include "vehicle.h"

vehicle::vehicle(){

	registration = "??????";
	make = "Default";
	model = "No Model";
	body_type = "No Body Type";
	year = 2018;
	purchasePrice = 10000;
    numberOfWheels = 4;
    numberOfSeats = 5; 

}

vehicle::vehicle(std::string crego, std::string cmake, std::string cmodel, std::string cbody_type, int cyear, int cprice){

	registration = crego;
	make = cmake;
	model = cmodel;
	body_type = cbody_type;
	year = cyear;
	purchasePrice = cprice; 
	numberOfWheels = 4;
    numberOfSeats = 5; 

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

int vehicle::getNumSeats() {
	return numberOfSeats;
}

int vehicle::getNumWheels() {
	return numberOfWheels;
}

void vehicle::setRegistration(std::string newRego){

	registration = newRego;

}   

void vehicle::setPrice(int cPrice) {
	purchasePrice=cPrice;
}

void vehicle::setYear(int cYear) {
	year=cYear;
}

void vehicle::setMake(std::string cMake) {
	make=cMake;
}

void vehicle::setModel(std::string cModel) {
	model=cModel;
}

void vehicle::setBody_type(std::string cBodyType) {
	body_type=cBodyType;
}

vehicle::~vehicle() {}
