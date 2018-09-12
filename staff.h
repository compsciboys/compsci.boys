#ifndef STAFF_H
#define STAFF_H

#include <string>

class staff {
	std::string name;
	std::string jobTitle;
	int salary;
	int
	
public:
	staff();
	staff(std:string pName; int pSalary);
	
	int getSalary();
	std::string getName;
	
	void setSalary();
	
	~staff();
}
