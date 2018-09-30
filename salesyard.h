#ifndef SALES_YARD
#define SALES_YARD

#include "staff.h"
#include "vehicle.h"
#include <string>

class salesyard {
	int capacity;
	int numCars;
	int numWorkers;
	std::string yardName;
	vehicle **yard;
	staff **workers; 
public:
	salesyard();
	salesyard(int pcapacity, std::string pname);
	
	int getNumCars();
	int getNumWorkers();
	std::string getYardName();
	vehicle ** getYard();
	staff ** getWorkers();

	bool addCar(car *tempCar);
	bool sellCar(car *sellingCar);

	bool addStaff(staff *newWorker);
	bool removeStaff(staff *worker);

	~salesyard();
};

#endif
