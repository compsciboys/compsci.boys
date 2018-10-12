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

	bool addVehicle(vehicle *tempVehicle);
	void sellVehicle(int index, staff *worker, int price);

	bool addStaff(staff *newWorker);
	void removeStaff(int index);

	void resetYard();
	void setName(std::string pname);
	void setCapacity(int pcapacity);

	~salesyard();
};

#endif
