#include "staff.h"
#include "car.h"
#include <iostream>

int main (void) {
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

	
}