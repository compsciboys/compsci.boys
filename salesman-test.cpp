#include "staff.h"
#include "salesman.h"

#include <iostream>

int main (void) {
	salesman person1("John", 50000);

	std::cout << person1.getName() << std::endl;
	std::cout << person1.getSalary() << std::endl;
}