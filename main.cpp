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
	int numSalesyard = 0;
	int maxSalesyards = 5;
	salesyard *yards;
	yards = new salesyard[maxSalesyards];

	yard[numSalesyard]=newSalesyard();

	salesyard newSalesyard() {
	
	

	while(run==true) {
		std::cout << "Salesyard Program (press the corresponding key to select an option)\n0 - exit\n 1 - Create new Salesyard\n 2 - Select Salesyard\n" << std::endl;
		std::cin.get(char) >> userInput;

		switch (userInput) {
			case '0':
				run=false;
				break;
			case '1':
				if (numSalesyard<maxSalesyards) {
					std::cout << "What would you like to name your salesyard?: ";
					std::cin >>  std::string tempname;

					std::cout << "Wha" 
				} else {
					std::cout << "Sorry you have already have " << numSalesyards << " salesyards, the max amount of salesyards allowed" << std::endl;
				}		
				break;
			case '2'

				break;
			case '~'

				break;
			default:
				std::cout << "That is an invalid input" << std::endl;

		}
	}	
}

