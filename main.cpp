#include "vehicle.h"
#include "staff.h"
#include "salesman.h"
#include "salesyard.h"

#include <iostream>
#include <string>

int main (void) {
	bool run = true;
	char userInput;
	int numSalesyards = 0;
	int maxSalesyards = 5;
	salesyard *yards;
	yards = new salesyard[maxSalesyards];

	std::string tempName;
	int tempCapacity;
	int currentSalesyard;
	int i;

	while(run==true) {
		std::cout << "Menu\n\n0 - exit\n1 - Create new Salesyard\n2 - Select Salesyard\n" << std::endl;
		std::cin.get(userInput);

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

					yards[numSalesyards].setName(tempName);
					yards[numSalesyards].setCapacity(tempCapacity);
					yards[numSalesyards].resetYard();
					numSalesyards++;
				} else {
					std::cout << "Sorry you have already have " << numSalesyards << " salesyards, the max amount of salesyards allowed" << std::endl;
				}		
				break;
			case '2':
				if (numSalesyards==0) {
					std::cout << "You have not yet created any salesyards" << std::endl;
				} else {
					std::cout << "You currently have the following salesyards" << std::endl;
					for (i=0; i<numSalesyards; i++) {
						std::cout << i << " - " << yards[i].getName() << std::endl;
					}
					while (true) {
						std::cin >> currentSalesyard;
						if (currentSalesyard <= numSalesyards && currentSalesyard >= 0) {
							std::cout << "You have selected the salesyard '" << yards[currentSalesyard].getName() << "'" << std::endl << "What would you like to do?" << std::endl;
							while (true) {
								std::cout << "0 - Add Car\n1 - Sell Car\n";
								std::cin.get(userInput);

								switch (userInput) {
									case '0':

										break;
									case '1':

										break;
									default:
										std::cout << "That is an invalid input" << std::endl;
								}
							}
							break;
						} else {
							std::cout << "That is not a valid selection" << std::endl;
						}
					}
				}
				break;
			case '~':
		
				break;
			default:
				std::cout << "That is an invalid input" << std::endl;

		}
		std::cin.get();
	}	
}

