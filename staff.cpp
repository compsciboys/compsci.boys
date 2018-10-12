#include "staff.h"

staff::staff() {
  name="?";
  salary=50000;
  jobTitle="Salesman";
}

staff::staff(std::string pName, int pSalary, std::string pJobTitle) {
  name=pName;
  salary=pSalary;
  jobTitle=pJobTitle;
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

void staff::setName(std::string pName) {
  name=pName;
}

void staff::setJobTitle(std::string pJobTitle) {
  jobTitle=pJobTitle;
}

void staff::setSalary(int pSalary) {
  salary=pSalary;
}

staff::~staff() {
}
