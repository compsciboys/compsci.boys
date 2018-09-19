#include "staff.h"
#include "car.h"
#include "salesyard.h"
#include <iostream>

int main (void) {
	std::string error = "Sorry the garage is full"; 

	staff person1("Bob", 90000, "Boss");

	std::cout << "Name: " << person1.getName() << std::endl;
	std::cout << "Salary: $" << person1.getSalary() << std::endl;
	std::cout << "JobTitle: " << person1.getJobTitle() << std::endl;

	car firstCar("123ABC", "Holden", "Commodore", "Sedan", 2010, 10000);

	std::cout << "Make: " << firstCar.getMake() << std::endl;
	std::cout << "Model: " << firstCar.getModel() << std::endl;
	std::cout << "Body Type: " << firstCar.getBody_type() << std::endl;
	std::cout << "Year: " << firstCar.getYear() << std::endl;
	std::cout << "Registration: " << firstCar.getRegistration() << std::endl;
	std::cout << "Price: $" << firstCar.getPrice() << std::endl;


	car secondCar("111AAA", "Mitsubishi", "Lancer", "Sedan", 2000, 5000);
	car thirdCar("222FGD", "Holden", "Barina", "Hatch", 2015, 12000);
	car fourthCar("666XXX", "Ford", "Mustang", "Coupe", 2016, 30000);
	car fifthCar("321KKK", "Subaru", "WRX", "Sedan", 2007, 10000);

	salesyard firstYard(3,"first yard");

	if (!firstYard.addCar(&firstCar)) {
		std::cout << error << std::endl;
	}


	if (!firstYard.addCar(&secondCar)) {
		std::cout << error << std::endl;
	}


	if (!firstYard.addCar(&thirdCar)) {
		std::cout << error << std::endl;
	}


	if (!firstYard.addCar(&fourthCar)) {
		std::cout << error << std::endl;
	}


	if (!firstYard.addCar(&fifthCar)) {
		std::cout << error << std::endl;
	}

	
}