#include "car.h"
#include <iostream>

int main (void) {
	car firstCar("123ABC", "Holden", "Commodore", "Sedan", 2010, 10000);

	std::cout << "Make: " << firstCar.getMake() << std::endl;
	std::cout << "Model: " << firstCar.getModel() << std::endl;
	std::cout << "Body Type: " << firstCar.getBody_type() << std::endl;
	std::cout << "Year: " << firstCar.getYear() << std::endl;
	std::cout << "Registration: " << firstCar.getRegistration() << std::endl;
	std::cout << "Price: $" << firstCar.getPrice() << std::endl;
}