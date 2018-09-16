#include "staff.h"
#include "car.h"
#include "salesyard.h"
#include <string>

int numWorkers=5;

salesyard::salesyard() {
	capacity = 10;
	numCars=0;
	name = "Car Yard";
	yard = new car*[capacity];
	workers = new staff*[numWorkers];
}

salesyard::salesyard(int pcapacity, std::string pname) {
	numCars=0;
	name = pname;
	capacity=pcapacity;
	yard = new car*[capacity];
	workers = new staff*[numWorkers];
}
	
std::string salesyard::getName() {
	return name;
}

car ** salesyard::getYard() {
	return yard;
}

staff ** salesyard::getWorkers() {
	return workers;
}

bool salesyard::addCar(car tempCar) {
	//FINISH LATER
}

bool salesyard::sellCar(car sellingCar) {
	//FINISH LATER
}

bool salesyard::addStaff(staff newWorker) {
	//FINISH LATER
}
	
bool removeStaff(staff worker); {
	//FINISH LATER
}

salesyard::~salesyard() {
	delete[] yard;
	delete[] workers;
}
