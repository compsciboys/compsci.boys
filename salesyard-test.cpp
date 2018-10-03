#include "staff.h"
#include "vehicle.h"
#include "salesyard.h"
#include <iostream>

int main (void) {
	std::string error = "Sorry the garage is full"; 

	staff person1("Bob", 90000, "Boss");

	std::cout << "Name: " << person1.getName() << std::endl;
	std::cout << "Salary: $" << person1.getSalary() << std::endl;
	std::cout << "JobTitle: " << person1.getJobTitle() << std::endl;

	vehicle firstVehicle("123ABC", "Holden", "Commodore", "Sedan", 2010, 10000);

	std::cout << "Make: " << firstVehicle.getMake() << std::endl;
	std::cout << "Model: " << firstVehicle.getModel() << std::endl;
	std::cout << "Body Type: " << firstVehicle.getBody_type() << std::endl;
	std::cout << "Year: " << firstVehicle.getYear() << std::endl;
	std::cout << "Registration: " << firstVehicle.getRegistration() << std::endl;
	std::cout << "Price: $" << firstVehicle.getPrice() << std::endl;


	vehicle secondVehicle("111AAA", "Mitsubishi", "Lancer", "Sedan", 2000, 5000);

	std::cout << "Make: " << secondVehicle.getMake() << std::endl;
	std::cout << "Model: " << secondVehicle.getModel() << std::endl;
	std::cout << "Body Type: " << secondVehicle.getBody_type() << std::endl;
	std::cout << "Year: " << secondVehicle.getYear() << std::endl;
	std::cout << "Registration: " << secondVehicle.getRegistration() << std::endl;
	std::cout << "Price: $" << secondVehicle.getPrice() << std::endl;

	vehicle thirdVehicle("222FGD", "Holden", "Barina", "Hatch", 2015, 12000);
	vehicle fourthVehicle("666XXX", "Ford", "Mustang", "Coupe", 2016, 30000);
	vehicle fifthVehicle("321KKK", "Subaru", "WRX", "Sedan", 2007, 10000);

	salesyard firstYard(3,"first yard");

	if (!firstYard.addVehicle(&firstVehicle)) {
		std::cout << error << std::endl;
	}


	if (!firstYard.addVehicle(&secondVehicle)) {
		std::cout << error << std::endl;
	}


	if (!firstYard.addVehicle(&thirdVehicle)) {
		std::cout << error << std::endl;
	}


	if (!firstYard.addVehicle(&fourthVehicle)) {
		std::cout << error << std::endl;
	}


	if (!firstYard.addVehicle(&fifthVehicle)) {
		std::cout << error << std::endl;
	}

	std::cout << firstYard.getYard()[2]->getRegistration() ;

	
}
