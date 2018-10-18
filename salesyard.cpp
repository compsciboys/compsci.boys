#include "staff.h"
#include "salesman.h"
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

std::string salesyard::getName() {
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

void salesyard::sellVehicle(int index, salesman *worker, int price) {
	worker->increaseProfit(price-yard[index]->getPrice());
	worker->incrementCarsSold();
	yard[index]=yard[numVehicles-1];
	numVehicles--;
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
	
void salesyard::removeStaff(int index) {
	workers[index]=workers[numWorkers];
	numWorkers--;
}

void salesyard::resetYard() {
	yard = new vehicle*[capacity];
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