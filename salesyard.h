#ifndef SALES_YARD
#define SALES_YARD

#include "staff.h"
#include "vehicle.h"
#include <string>

class salesyard {
	int capacity;
	int numVehicles;
	int numWorkers;
	std::string name;
	vehicle **yard;
	staff **workers; 
public:
	salesyard();
	salesyard(int pcapacity, std::string pname);
	
	int getNumVehicles();
	int getNumWorkers();
	std::string getName();
	vehicle ** getYard();
	staff ** getWorkers();

	bool addVehicle(vehicle *tempVehicle, staff *worker);
	bool sellVehicle(vehicle *sellingVehicle, staff *worker);

	bool addStaff(staff *newWorker);
	bool removeStaff(staff *worker);

	void resetYard();
	void setName(std::string pname);
	void setCapacity(int pcapacity);

	~salesyard();
};

#endif
