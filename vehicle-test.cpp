#include "vehicle.h"
#include <iostream>

int main (void) {
	vehicle firstCar("123ABC", "Holden", "Commodore", "Sedan", 2010, 10000);

	std::cout << "Make: " << firstCar.getMake() << std::endl;
	std::cout << "Model: " << firstCar.getModel() << std::endl;
	std::cout << "Body Type: " << firstCar.getBody_type() << std::endl;
	std::cout << "Year: " << firstCar.getYear() << std::endl;
	std::cout << "Registration: " << firstCar.getRegistration() << std::endl;
	std::cout << "Price: $" << firstCar.getPrice() << std::endl;
	
	vehicle secondCar(14, "Mazda", "6", "Hatch", "2012", 1000);
	
	std::cout << "Make: " << secondtCar.getMake() << std::endl;
	std::cout << "Model: " << secondCar.getModel() << std::endl;
	std::cout << "Body Type: " << secondCar.getBody_type() << std::endl;
	std::cout << "Year: " << secondCar.getYear() << std::endl;
	std::cout << "Registration: " << secondCar.getRegistration() << std::endl;
	std::cout << "Price: $" << secondCar.getPrice() << std::endl;
}
