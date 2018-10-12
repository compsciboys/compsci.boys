#ifndef STAFF_H
#define STAFF_H

#include <string>

class staff {
	std::string name;
	std::string jobTitle;
	int salary;
	
public:
	staff();
	staff(std::string pName, int pSalary, std::string pJobTitle);
	
	int getSalary();
	std::string getName();
	std::string getJobTitle();
	
	void setName(std::string pName);
	void setJobTitle(std::string pJobTitle);
	void setSalary(int pSalary);
	
	~staff();
};

#endif