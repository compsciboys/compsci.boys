#ifndef SALESMAN_H
#define SALESMAN_H

#include <string>

class salesman:public staff {
	int numCarsSold;
	int profit;
public:
	salesman();
	salesman(std::string pName, int pSalary);

	int getnumCarsSold();
	int getProfit();

	~salesman();
};

#endif