#include "staff.h"
#include <iostream>

int main (void) {
	staff person1("Bob", 90000, "Boss");

	std::cout << "Name: " << person1.getName() << std::endl;
	std::cout << "Salary: $" << person1.getSalary() << std::endl;
	std::cout << "JobTitle: " << person1.getJobTitle() << std::endl;
}