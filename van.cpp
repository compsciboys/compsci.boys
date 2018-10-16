#include <string>
#include "vehicle.h"
#include "van.h"

van::van():vehicle("??????", "Not Specified", "Not Specified", "Van", 2018, 0) {
	numberOfSeats = 2;
	numberOfWheels = 4;
	storageSpace=0;
}

van::van(std::string registration, std::string make, std::string model, std::string body_type, int year, int price, int storage):vehicle(registration, make, model, body_type, year, price) {
	numberOfSeats = 2;
	numberOfWheels = 4;
	storageSpace = storage;
}

int van::getStorageSpace() {
	return storageSpace;
}

void van::setStorageSpace(int cStorageSpace) {
	storageSpace = cStorageSpace;
}

van::~van() {}
