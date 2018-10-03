#include "vehicle.h"
#include <iostream>

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
	
	std::cout << "Please enter the vehicle registration: " << endl; ;
	std::cin >> crego1;
	std:: cout << "Please enter the vehicle badge: " << endl;
	std::cin >> cmake1;
	std::cout << "Please enter the vehicle model: " << endl;
	std::cin >> cmodel1;
	std::cout << "Please enter the vehicle body type: " << endl;
	std::cin >> cbody_type1;
	std::cout << "Please enter the year of manufacture: " << endl;
	std::cin >> cyear1;
	std::cout << "Please enter the price of the vehicle: " << endl;
	std::cin >> cprice1;
	
	vehicle thirdCar(crego1, cmake1, cmodel1, cbody_type1, cyear1, cprice1);
	
	std::cout << "Make: " << thirdCar.getMake() << std::endl;
	std::cout << "Model: " << thirdCar.getModel() << std::endl;
	std::cout << "Body Type: " << thirdCar.getBody_type() << std::endl;
	std::cout << "Year: " << thirdCar.getYear() << std::endl;
	std::cout << "Registration: " << thirdCar.getRegistration() << std::endl;
	std::cout << "Price: $" << thirdCar.getPrice() << std::endl;
	
}
