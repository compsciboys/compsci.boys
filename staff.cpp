#include "staff.h"

staff::staff() {
  name="?";
  salary=50000;
  jobTitle="Salesman";
}

staff::staff(std::string pName, int pSalary, std::string pjobTitle) {
  name=pName;
  salary=pSalary;
  jobTitle=pjobTitle;
}

int staff::getSalary() {
  return salary;
}

std::string staff::getName() {
  return name;
}

std::string staff::getJobTitle() {
  return jobTitle;
}

void staff::setSalary(int pSalary) {
  salary=pSalary;
}

void staff::incrementCarsSold() {

}

void staff::increaseProfit(int income) {
  
}


staff::~staff() {
}
