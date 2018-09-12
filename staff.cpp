#include "staff.h"

staff::staff() {
  name="?";
  salary=50000;
  jobTitle="Salesman";
}

staff::staff(std:string pName; int pSalary) {
  name=pName;
  salary=pSalary;
  jobTitle="Salesman";
}

int staff::getSalary() {
  return salary;
}

std::string staff::getName() {
  return name;
}
	
void staff::setSalary() {
  salary=pSalary;
	
staff::~staff() {
}
