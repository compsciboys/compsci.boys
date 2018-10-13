#include "staff.h"
#include "salesman.h"
#include <string>

salesman::salesman():staff("?",50000,"Salesman") {
	profit = 0;
	numCarsSold = 0;
}

salesman::salesman(std::string pName, int pSalary):staff(pName,pSalary,"Salesman") {
	profit = 0;
	numCarsSold = 0;
}

int salesman::getNumCarsSold() {
	return numCarsSold;
}
	
int salesman::getProfit() {
	return profit;
}

void salesman::incrementCarsSold() {
	numCarsSold++;
}

void salesman::increaseProfit(int income) {
	profit=profit+income;
}

salesman::~salesman() {

}