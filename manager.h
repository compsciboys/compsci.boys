#ifndef MANAGER_H
#define MANAGER_H

#include <string>

class manager:public salesman {


public: 

	manager();
	manager(std::string mName, int mSalary);

	bool yardOpen(int time); //in 24hour time

	~manager(); 

};

#endif
