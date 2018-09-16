#ifndef STAFF_H
#define STAFF_H

#include <string>

class staff {
	std::string name;
	std::string jobTitle;
	int salary;
	
public:
	staff();
	staff(std::string pName, int pSalary, std::string pjobTitle);
	
	int getSalary();
	std::string getName();
	std::string getJobTitle();
	
	void setSalary(int pSalary);
	
	~staff();
};

#endif