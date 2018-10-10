#include "vehicle.h"
#include "staff.h"
#include "salesman.h"
#include "salesyard.h"

#include <iostream>
#include <string>

int main (void) {
	bool run = true;
	std::string menu = 
	char userInput;
	int numSalesyards = 0;
	int maxSalesyards = 5;
	salesyard *yards;
	yards = new salesyard[maxSalesyards];
	std::string tempName;
	int tempCapacity;

	while(run==true) {
		std::cout << "Salesyard Program (press the corresponding key to select an option)\n0 - exit\n 1 - Create new Salesyard\n 2 - Select Salesyard\n" << std::endl;
		std::cin.get(char) >> userInput;

		switch (userInput) {
			case '0':
				run=false;
				break;
			case '1':
				if (numSalesyards<maxSalesyards) {
					std::cout << "What would you like to name your salesyard?: ";
					std::cin >>  tempName;

					std::cout << "How many cars can '" << tempName << "' hold?: ";
					std::cin >> tempCapacity;

					yard[numSalesyards]
					numSalesyards++;
				} else {
					std::cout << "Sorry you have already have " << numSalesyards << " salesyards, the max amount of salesyards allowed" << std::endl;
				}		
				break;
			case '2'
				std::cout << 
				break;
			case '~'

				break;
			default:
				std::cout << "That is an invalid input" << std::endl;

		}
	}	
}

