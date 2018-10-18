#include "vehicle.h"
#include <iostream>
#include <sstream>
int main (void) {
	vehicle firstCar("123ABC", "Holden", "Commodore", "Sedan", 2010, 10000);

	std::cout << "Make: " << firstCar.getMake() << std::endl;
	std::cout << "Model: " << firstCar.getModel() << std::endl;
	std::cout << "Body Type: " << firstCar.getBody_type() << std::endl;
	std::cout << "Year: " << firstCar.getYear() << std::endl;
	std::cout << "Registration: " << firstCar.getRegistration() << std::endl;
	std::cout << "Price: $" << firstCar.getPrice() << std::endl;
	
	//vehicle secondCar(14, "Mazda", "6", "Hatch", "2012", 1000);
	
	//std::cout << "Make: " << secondCar.getMake() << std::endl;
	//std::cout << "Model: " << secondCar.getModel() << std::endl;
	//std::cout << "Body Type: " << secondCar.getBody_type() << std::endl;
	//std::cout << "Year: " << secondCar.getYear() << std::endl;
	//std::cout << "Registration: " << secondCar.getRegistration() << std::endl;
	//std::cout << "Price: $" << secondCar.getPrice() << std::endl;
	
	std::string crego1;
	std::string cmake1;
	std::string cmodel1;
	std::string cbody_type1;
	int cyear1; 
	int cprice1;
	char errorTest;
	std::string inputBuffer;

	std::cout << "Please enter the vehicle registration: " << std::endl;
	while(std::getline(std::cin, inputBuffer)) {
		std::stringstream linestream(inputBuffer);
		if(!(linestream >> crego1)) {
			std::cout << "That was an invalid input. Enter the vehicle's registration" << std::endl;
			continue;
		}
		break;
	}
		
	std:: cout << "Please enter the vehicle badge: " << std::endl;
	while(std::getline(std::cin, inputBuffer)) {
		std::stringstream linestream(inputBuffer);
		if(!(linestream >> cmake1)) {
			std::cout << "That was an invalid input. Enter the vehicle's badge" << std::endl;
			continue;
		}
		break;
	
	}
	std::cout << "Please enter the vehicle model: " << std::endl;
	while(std::getline(std::cin, inputBuffer)) {
		std::stringstream linestream(inputBuffer);
		if(!(linestream >> cmodel1)) {
			std::cout << "That was an invalid input. Enter the vehicle's model" << std::endl;
			continue;
		}
		break;
	}

	std::cout << "Please enter the year of manufacture: " << std::endl;
	while(std::getline(std::cin, inputBuffer)) {
		std::stringstream linestream(inputBuffer);
		if(!(linestream >> cyear1) || linestream >> errorTest) {
			std::cout << "That was an invalid input. Enter the vehicle's year of manufacture" << std::endl;
			continue;
		}
		break;
	}
										
	std::cout << "Please enter the purchase price of the vehicle: " << std::endl;
	while(std::getline(std::cin, inputBuffer)) {
		std::stringstream linestream(inputBuffer);
		if(!(linestream >> cprice1) ||linestream >> errorTest) {
			std::cout << "That was an invalid input. Enter the vehicle's purchase price" << std::endl;
			continue;
		}
		if(cprice1<0) {
			std::cout << "Sorry, the price must be positive" << std::endl;
			continue;
		}
		break;
	}

	std::cout << "Please enter the vehicle body type (Truck, Van, Bike, Coupe, etc.):" << std::endl;
	while(std::getline(std::cin, inputBuffer)) {
		std::stringstream linestream(inputBuffer);
		if(!(linestream >> cbody_type1)) {
			std::cout << "That was an invalid input. Enter the vehicle's body type" << std::endl;
			continue;
		}
		break;
	}
	
	vehicle thirdCar(crego1, cmake1, cmodel1, cbody_type1, cyear1, cprice1);
	
	std::cout << "Make: " << thirdCar.getMake() << std::endl;
	std::cout << "Model: " << thirdCar.getModel() << std::endl;
	std::cout << "Body Type: " << thirdCar.getBody_type() << std::endl;
	std::cout << "Year: " << thirdCar.getYear() << std::endl;
	std::cout << "Registration: " << thirdCar.getRegistration() << std::endl;
	std::cout << "Price: $" << thirdCar.getPrice() << std::endl;
	
}
