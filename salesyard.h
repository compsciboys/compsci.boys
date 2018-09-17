#ifndef SALES_YARD
#define SALES_YARD

#include "staff.h"
#include "car.h"
#include <string>

class salesyard {
	int capacity;
	int numCars;
	int numWorkers;
	std::string name;
	car **yard;
	staff **workers; 
public:
	salesyard();
	salesyard(int pcapacity, std::string pname);
	
	std::string getName();
	car ** getYard();
	staff ** getWorkers();

	bool addCar(car *tempCar);
	bool sellCar(car *sellingCar);

	bool addStaff(staff *newWorker);
	bool removeStaff(staff *worker);

	void printCarStock(car** stock);

	~salesyard();
};

#endif