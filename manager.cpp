#include "staff.h"
#include "salesman.h"
#include "manager.h"
#include <string>

manager::manager():staff("?",100000,"Manager"){

}
	
manager::manager(std::string mName, int mSalary):staff(mName, mSalary, "Manager") {

}

bool yardOpen(int time){

	if (time>9 && time<17){
		return true;
	}
	else{
		return false;
	}
}

manager::~manager(){}