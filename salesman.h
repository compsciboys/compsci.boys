#ifndef SALESMAN_H
#define SALESMAN_H

#include <string>

class salesman:public staff {
	int numCarsSold;
	int profit;
public:
	salesman();
	salesman(std::string pName, int pSalary);

	int getNumCarsSold();
	int getProfit();

	void incrementCarsSold();
	void increaseProfit(int income);
	~salesman();
};

#endif