#include "staff.h"
#include "car.h"
#include "salesyard.h"
#include <string>

int maxWorkers=5;

salesyard::salesyard() {
	capacity = 10;
	numCars = 0;
	numWorkers = 0;
	name = "Car Yard";
	yard = new car*[capacity];
	workers = new staff*[maxWorkers];
}

salesyard::salesyard(int pcapacity, std::string pname) {
	numCars = 0;
	numWorkers = 0;
	name = pname;
	capacity=pcapacity;
	yard = new car*[capacity];
	workers = new staff*[maxWorkers];
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

bool salesyard::addCar(car *tempCar) {
	if (numCars<capacity) {
		yard[numCars]=tempCar;
		numCars++;
		return true;
	} else {
		return false;
	}
}

bool salesyard::sellCar(car *sellingCar) {
	//FINISH LATER
}

bool salesyard::addStaff(staff *newWorker) {
	if (numWorkers < maxWorkers) {
		workers[numWorkers]=newWorker;
		numWorkers++;
		return true;
	} else {
		return false;
	}
}
	
bool salesyard::removeStaff(staff *worker) {
	//FINISH LATER
}

salesyard::~salesyard() {
	delete[] yard;
	delete[] workers;
}
