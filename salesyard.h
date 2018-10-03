#ifndef SALES_YARD
#define SALES_YARD

#include "staff.h"
#include "vehicle.h"
#include <string>

class salesyard {
	int capacity;
	int numVehicles;
	int numWorkers;
	std::string yardName;
	vehicle **yard;
	staff **workers; 
public:
	salesyard();
	salesyard(int pcapacity, std::string pname);
	
	int getNumVehicles();
	int getNumWorkers();
	std::string getYardName();
	vehicle ** getYard();
	staff ** getWorkers();

	bool addVehicle(vehicle *tempVehicle);
	bool sellVehicle(vehicle *sellingVehicle);

	bool addStaff(staff *newWorker);
	bool removeStaff(staff *worker);

	~salesyard();
};

#endif
