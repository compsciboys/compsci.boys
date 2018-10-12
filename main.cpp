#include "vehicle.h"
#include "staff.h"
#include "salesman.h"
#include "salesyard.h"

#include <iostream>
#include <string>

int main (void) {
	bool run = true;
	bool salesyardSelected = true;
	bool vehicleSelected = true;
	bool returnToMenu = true;
	bool returnToSalesyardMenu = true;
	char userInput;
	int numSalesyards = 0;
	int maxSalesyards = 5;
	salesyard *yards;
	yards = new salesyard[maxSalesyards];

	std::string tempName;
	int tempCapacity;
	std::string tempRego;

	int currentSalesyard; //index of current salesyard in yards array
	int currentVehicle; //index of current vehicle in current salesyard
	int i;

	std::string tempMake;
	std::string tempModel;
	int tempYear;
	int tempPrice;
	std::string tempBodyType;
	vehicle tempVehicle;

	while(run==true) {
		std::cout << "\nMenu\n\n0 - Exit\n1 - Create new Salesyard\n2 - Select Salesyard\n" << std::endl;
		std::cin.get(userInput);

		switch (userInput) {
			case '0':
				run=false;
				break;
			case '1':
				if (numSalesyards<maxSalesyards) {
					std::cout << "What would you like to name your salesyard?: ";
					std::cin >>  tempName;

					std::cout << "How many vehicles can '" << tempName << "' hold?: ";
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
				returnToMenu=false;
				if (numSalesyards==0) {
					std::cout << "You have not yet created any salesyards" << std::endl;
				} else {
					std::cout << "You currently have the following salesyards" << std::endl;
					for (i=0; i<numSalesyards; i++) {
						std::cout << i << " - " << yards[i].getName() << std::endl;
					}
					while (returnToMenu==false) {
						std::cin >> currentSalesyard;

						if (currentSalesyard < numSalesyards && currentSalesyard >= 0) {

							std::cout << "You have selected the salesyard '" << yards[currentSalesyard].getName() << "'" << std::endl << "What would you like to do?" << std::endl;
							salesyardSelected=true;
							while (salesyardSelected==true) {
								std::cout << "0 - Return to Menu\n1 - View vehicles\n2 - Add Vehicle\n3 - Sell Vehicle\n4 - View Staff\n5 - Hire Staff\n6 - Fire Staff\n7 - Delete Salesyard\n";
								std::cin.get();
								std::cin.get(userInput);

								switch (userInput) {
									case '0':
										salesyardSelected=false;
										returnToMenu=true;
										break;
									case '1':
										returnToSalesyardMenu=false;
										if (yards[currentSalesyard].getNumVehicles()>0) {
											std::cout << "Select the vehicle you would like to view" << std::endl;
											std::cout << "0 - Return to Salesyard Menu" << std::endl;
											for (i=0;i<yards[currentSalesyard].getNumVehicles();i++) {
												std::cout << i << yards[currentSalesyard].getYard()[i]->getYear() << " " << yards[currentSalesyard].getYard()[i]->getMake() << " " << yards[currentSalesyard].getYard()[i]->getModel() << " \n" << std::endl;
											}
											while (returnToSalesyardMenu==false) {
												std::cin >> currentVehicle;

												if (currentVehicle < yards[currentSalesyard].getNumVehicles() && currentVehicle >= 0) {
													std::cout << "You have selected the '" << yards[currentSalesyard].getYard()[currentVehicle]->getYear() << " " << yards[currentSalesyard].getYard()[currentVehicle]->getMake() << " " << yards[currentSalesyard].getYard()[currentVehicle]->getModel() << "'" << std::endl << "What would you like to do?" << std::endl;
													vehicleSelected=true;

													while (vehicleSelected==true) {
														std::cout << "0 - Return\n1 - View All Details\n2 - Change Registration\n";
														std::cin.get();
														std::cin.get(userInput);

														switch (userInput) {
															case '0':
																vehicleSelected=false;
																returnToSalesyardMenu=true;
																break;
															case '1':
																//print vehicle details nicely formatted
																break;
															case '2':
																std::cout << "Enter New Registration: " << std::endl;
																std::getline(std::cin, tempRego);
																yards[currentSalesyard].getYard()[currentVehicle]->setRegistration(tempRego);
															default:
																std::cout << "That is an invalid input" << std::endl;
														}
													}
												}
											}
										} else {
											std::cout << "Sorry this salesyard is empty" << std::endl;
										}
										break;
									case '2':

										std::cout << "Please enter the vehicle registration: " << std::endl; ;
										std::cin >> tempRego;
										std:: cout << "Please enter the vehicle badge: " << std::endl;
										std::cin >> tempMake;
										std::cout << "Please enter the vehicle model: " << std::endl;
										std::cin >> tempModel;
										std::cout << "Please enter the year of manufacture: " << std::endl;
										std::cin >> tempYear;
										std::cout << "Please enter the price of the vehicle: " << std::endl;
										std::cin >> tempPrice;
										std::cout << "Please enter the vehicle body type: " << std::endl;
										std::cin >> tempBodyType;
										if (tempBodyType=="Sedan") {

										} else if (tempBodyType=="Truck") {

										} else if (tempBodyType=="") {

										}

										//yards[currentSalesyard].addVehicle(&tempVehicle);
										break;
									case '3':

										break;
									case '4':

										break;
									case '5':

										break;
									case '6':

										break;
									case '7':
										yards[currentSalesyard]=yards[numSalesyards-1];
										numSalesyards--;
										salesyardSelected=false;
										returnToMenu=true;
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

