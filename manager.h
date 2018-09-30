#ifndef MANAGER_H
#define MANAGER_H

#include <string>

class manager:public salesman {


public: 

	manager();
	manager(std::string mName, int mSalary);

	addStaff(std::string pName, int pSalary, std::string jobTitle);
	removeStaff(std::string pName, std::string jobTitle);


	~manager(); 

};

#endif