#include "staff.h"
#include "vehicle.h"
#include "salesyard.h"
#include <string>

int maxWorkers=5;

salesyard::salesyard() {
	capacity = 10;
	numVehicles = 0;
	numWorkers = 0;
	name = "Car Yard";
	yard = new vehicle*[capacity];
	workers = new staff*[maxWorkers];
}

salesyard::salesyard(int pcapacity, std::string pname) {
	numVehicles = 0;
	numWorkers = 0;
	name = pname;
	capacity=pcapacity;
	yard = new vehicle*[capacity];
	workers = new staff*[maxWorkers];
}
	
int salesyard::getNumVehicles() {
	return numVehicles;
}

int salesyard::getNumWorkers() {
	return numWorkers;
}

std::string salesyard::getYardName() {
	return name;
}

vehicle ** salesyard::getYard() {
	return yard;
}

staff ** salesyard::getWorkers() {
	return workers;
}

bool salesyard::addVehicle(vehicle *tempVehicle) {
	if (numVehicles<capacity) {
		yard[numVehicles]=tempVehicle;
		numVehicles++;
		return true;
	} else {
		return false;
	}
}

bool salesyard::sellVehicle(vehicle *sellingVehicle) {
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

void salesyard::setName(std::string pname) {
	name=pname;
}

void salesyard::setCapacity(int pcapacity) {
	capacity=pcapacity;
}

salesyard::~salesyard() {
	delete[] yard;
	delete[] workers;
}