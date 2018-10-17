#include "vehicle.h"
#include "staff.h"
#include "salesman.h"
#include "salesyard.h"
#include "van.h"
#include "truck.h"
#include "bike.h"
#include "coupe.h"

#include <iostream>
#include <string>

int main (void) {
	bool run = true;
	bool salesyardSelected = true;
	bool vehicleSelected = true;
	bool returnToMenu = true;
	bool returnToSalesyardMenu = true;
	char userInput;
	bool cont;
	int numSalesyards = 0;
	int maxSalesyards = 5;
	salesyard *yards;
	yards = new salesyard[maxSalesyards];

	std::string tempName;
	int tempCapacity;
	std::string tempRego;

	int currentSalesyard; //index of current salesyard in yards array
	int currentVehicle; //index of current vehicle in current salesyard
	int currentSalesman; //index of current salesman
	int i;

	std::string tempMake;
	std::string tempModel;
	int tempYear;
	int tempPrice;
	std::string tempBodyType;
	int tempSalary;
	std::string tempJobTitle;

	vehicle *tempVehicle;
	bike *tempBike;
	van *tempVan;
	truck *tempTruck;
	coupe *tempCoupe;

	int tempTowing;
	int tempStorage;
	char tempHelmet;
	int tempPerformance;


	salesman *tempSalesman;
	staff *tempStaff;
	while(run==true) {
		std::cout << "\n~~~~~~Menu~~~~~~\n\n0 - Exit\n1 - Create new Salesyard\n2 - Select Salesyard\n" << std::endl;
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
				std::cin.get();		
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
							std::cin.get();
							while (salesyardSelected==true) {
								std::cout << "0 - Return to Menu\n1 - View vehicles\n2 - Add Vehicle\n3 - Sell Vehicle\n4 - View Staff\n5 - Hire Staff\n6 - Fire Staff\n7 - Delete Salesyard\n" << std::endl;
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
												std::cout << i+1<< " - " << yards[currentSalesyard].getYard()[i]->getYear() << " " << yards[currentSalesyard].getYard()[i]->getMake() << " " << yards[currentSalesyard].getYard()[i]->getModel() << std::endl;
											}
											while (returnToSalesyardMenu==false) {
												std::cin >> currentVehicle;
												std::cin.get();
												currentVehicle--;

												if (currentVehicle < yards[currentSalesyard].getNumVehicles() && currentVehicle >= 0) {
													std::cout << "You have selected the '" << yards[currentSalesyard].getYard()[currentVehicle]->getYear() << " " << yards[currentSalesyard].getYard()[currentVehicle]->getMake() << " " << yards[currentSalesyard].getYard()[currentVehicle]->getModel() << "'" << std::endl << "What would you like to do?" << std::endl;
													vehicleSelected=true;

													while (vehicleSelected==true) {
														std::cout << "0 - Return\n1 - View All Details\n2 - Change Registration\n";
														std::cin.get(userInput);

														switch (userInput) {
															case '0':
																vehicleSelected=false;
																returnToSalesyardMenu=true;
																break;
															case '1':
																std::cout << "Manufacturing Year: " << yards[currentSalesyard].getYard()[currentVehicle]->getYear() << std::endl;
																std::cout << "Purchase Price: " << yards[currentSalesyard].getYard()[currentVehicle]->getPrice() << std::endl;
																std::cout << "Registration: " << yards[currentSalesyard].getYard()[currentVehicle]->getRegistration() << std::endl; 
																std::cout << "Make: " << yards[currentSalesyard].getYard()[currentVehicle]->getMake() << std::endl;
																std::cout << "Model: " << yards[currentSalesyard].getYard()[currentVehicle]->getModel() << std::endl;
																std::cout << "Number of Wheels: " << yards[currentSalesyard].getYard()[currentVehicle]->get() << std::endl;
																std::cout << "Number of Seats: " << yards[currentSalesyard].getYard()[currentVehicle]->get() << std::endl;
																std::cout << "Body Type: " << yards[currentSalesyard].getYard()[currentVehicle]->getBody_type() << std::endl;
																/*
																if (yards[currentSalesyard].getYard()[currentVehicle]->getBody_type()=="Truck") { 
																	std::cout << "~~~~~Truck Specific Details~~~~~" << std::endl;
																	tempTruck = static_cast<truck *>(yards[currentSalesyard].getYard()[currentVehicle]);
																	std::cout << "Towing Capacity: " << tempTruck->getTowingCapacity() << std::endl;

																} else if (yards[currentSalesyard].getYard()[currentVehicle]->getBody_type()=="Van") {
																	std::cout << "~~~~~Van specific Details~~~~~" << std::endl;
																	tempVan = static_cast<van *>(yards[currentSalesyard].getYard()[currentVehicle]);
	
																} else if (yards[currentSalesyard].getYard()[currentVehicle]->getBody_type()=="Bike") {
																	std::cout << "~~~~~Bike specific Details~~~~~" << std::endl;
																	tempBike= static_cast<bike *>(yards[currentSalesyard].getYard()[currentVehicle]);

																} else if (yards[currentSalesyard].getYard()[currentVehicle]->getBody_type()=="Coupe") {
																	std::cout << "~~~~~Coupe specific Details~~~~~" << std::endl;
																	tempCoupe = static_cast<coupe *>(yards[currentSalesyard].getYard()[currentVehicle]);

																}
																*/
																std::cin.get();
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
										//do check for variable type?
										std::cout << "Please enter the vehicle registration: " << std::endl;
										std::cin >> tempRego;
										std:: cout << "Please enter the vehicle badge: " << std::endl;
										std::cin >> tempMake;
										std::cout << "Please enter the vehicle model: " << std::endl;
										std::cin >> tempModel;
										std::cout << "Please enter the year of manufacture: " << std::endl;
										std::cin >> tempYear;
										std::cout << "Please enter the price of the vehicle: " << std::endl;
										std::cin >> tempPrice;
										std::cout << "Please enter the vehicle body type (Truck, Van, Bike, Coupe, etc.):" << std::endl;
										std::cin >> tempBodyType;
										if (tempBodyType=="Truck") { /*
											std::cout << "Please enter the towing capacity of this truck" << std::endl;
											std::cin >> tempTowing;

											tempTruck=new truck(tempRego, tempMake, tempModel, tempYear, tempPrice, tempTowing);

											if (!yards[currentSalesyard].addVehicle(tempTruck)) {
												std::cout << "Sorry the salesyard is full" << std::endl;
											} else {
												std::cout << "Truck added successfully" << std::endl;
											}
										} else if (tempBodyType=="Van") {
											std::cout << "Please enter the storage capacity of this van" << std::endl;
											std::cin >> tempStorage;

											tempVan=new van(tempRego, tempMake, tempBodyType, tempYear, tempPrice, tempStorage);

											if (!yards[currentSalesyard].addVehicle(tempVan)) {
												std::cout << "Sorry the salesyard is full" << std::endl;
											} else {
												std::cout << "Van added successfully" << std::endl;
											}
										} else if (tempBodyType=="Bike") {
											std::cout << "Does this bike contain a helmet (y/n): " << std::endl;
											cont =true;
											while (continue) {
												std::cin.get() >> tempHelmet;
												if (tempHelmet=='y') {
													tempBike=new bike(tempRego, tempMake, tempModel, tempYear, tempPrice, true);
													cont = false;
												} else if (tempHelmet=='n') {
													tempBike=new bike(tempRego, tempMake, tempModel, tempYear, tempPrice, false);
													cont = false;
												} else {
													cont = true;
													std::cout << "Invalid input. Does this bike contain a helmet (y/n): "
												}
											}
											if (!yards[currentSalesyard].addVehicle(tempBike)) {
													std::cout << "Sorry the salesyard is full" << std::endl;
											} else {
													std::cout << "Bike added successfully" << std::endl;
											}
										} else if (tempBodyType=="Coupe") {
											std::cout << "Please enter the performance of this car (kWh): " << std::endl;
											std::cin >> tempPerformance;

											tempCoupe=new coupe(tempRego, tempMake, tempModel, tempYear, tempPrice, tempPerformance);

											if (!yards[currentSalesyard].addVehicle(tempCoupe)) {
												std::cout << "Sorry the salesyard is full" << std::endl;
											} else {
												std::cout << "Coupe added successfully" << std::endl;
											}
											*/
										} else {
											tempVehicle=new vehicle(tempRego, tempMake, tempModel, tempBodyType, tempYear, tempPrice);

											if (!yards[currentSalesyard].addVehicle(tempVehicle)) {
												std::cout << "Sorry the salesyard is full" << std::endl;
											} else {
												std::cout << "Car added successfully" << std::endl;
											}
										}
										std::cin.get();
										break;
									case '3':
										returnToSalesyardMenu=false;
										if (yards[currentSalesyard].getNumVehicles()>0) {
											std::cout << "Select the vehicle you would like to sell" << std::endl;
											for (i=0;i<yards[currentSalesyard].getNumVehicles();i++) {
												std::cout << i << " - " << yards[currentSalesyard].getYard()[i]->getYear() << " " << yards[currentSalesyard].getYard()[i]->getMake() << " " << yards[currentSalesyard].getYard()[i]->getModel() << std::endl;
											}
											while (returnToSalesyardMenu==false) {
												std::cin >> currentVehicle;

												if (currentVehicle < yards[currentSalesyard].getNumVehicles() && currentVehicle >= 0) {
													std::cout << "Which Salesman has sold the '" << yards[currentSalesyard].getYard()[currentVehicle]->getYear() << " " << yards[currentSalesyard].getYard()[currentVehicle]->getMake() << " " << yards[currentSalesyard].getYard()[currentVehicle]->getModel() << "'" << std::endl << "What would you like to do?" << std::endl;
													vehicleSelected=true;
													for (i=0;i<yards[currentSalesyard].getNumWorkers();i++) {
														std::cout << i << " - " << yards[currentSalesyard].getWorkers()[i]->getName() << std::endl;
													}
													std::cin >> currentSalesman;
													if (currentSalesman>=0 && currentSalesman<yards[currentSalesyard].getNumWorkers()) {
														if (yards[currentSalesyard].getWorkers()[i]->getJobTitle() == "Salesman") {
															std::cout << "This car was bought for $" << yards[currentSalesyard].getYard()[currentVehicle]->getPrice() << " .How much was it sold for?" << std::endl;
															std::cin >> tempPrice;
															tempSalesman = static_cast<salesman *>(yards[currentSalesyard].getWorkers()[currentSalesman]);
															yards[currentSalesyard].sellVehicle(currentVehicle, tempSalesman,tempPrice);
														} else {
															std::cout << "Sorry, " << yards[currentSalesyard].getWorkers()[currentSalesman]->getName() << " can't sell cars" << std::endl;
														}
													} else {
														std::cout << "That is not a valid selection" << std::endl;
													}
												} else {
													std::cout << "That is not a valid selection" << std::endl;
													returnToSalesyardMenu=true;
													std::cin.get();
												}
											}
										}
										break;
									case '4':
										returnToSalesyardMenu=false;
										if (yards[currentSalesyard].getNumWorkers()>0) {
											std::cout << "Select the staff member you would like to view" << std::endl;
											std::cout << "0 - Return to Salesyard Menu" << std::endl;
											for (i=0;i<yards[currentSalesyard].getNumWorkers();i++) {
												std::cout << i+1<< " - " << yards[currentSalesyard].getWorkers()[i]->getName() << std::endl;
											}
											while (returnToSalesyardMenu==false) {
												std::cin >> currentSalesman;
												currentSalesman--;

												if (currentSalesman < yards[currentSalesyard].getNumWorkers() && currentSalesman >= 0) {
													std::cout << "Name: " << yards[currentSalesyard].getWorkers()[currentSalesman]->getName() << "\nSalary: $" << yards[currentSalesyard].getWorkers()[currentSalesman]->getSalary()  << "\nJob Title:"  << yards[currentSalesyard].getWorkers()[currentSalesman]->getJobTitle() << std::endl;
													if (yards[currentSalesyard].getWorkers()[currentSalesman]->getJobTitle()=="Salesman") {
														tempSalesman = static_cast<salesman *>(yards[currentSalesyard].getWorkers()[currentSalesman]);
														std::cout << "Cars Sold: " << tempSalesman->getNumCarsSold() << "\nProfit: $" << tempSalesman->getProfit() << std::endl;
													}
													returnToSalesyardMenu=true;
													std::cin.get();
												}
											}
										} else {
											std::cout << "Sorry this salesyard does not have any staff" << std::endl;
										}
										break;
									case '5':
										std::cout << "Please enter the Staff's salary: " << std::endl;
										std::cin >> tempSalary;
										std::cin.ignore();
										std::cout << "Please enter the Staff's name: " << std::endl;
										std::getline(std::cin, tempName);
										std::cout << "Please enter the Staff's job title (Salesman, etc.): " << std::endl;
										std::getline(std::cin, tempJobTitle);
										if (tempJobTitle == "Salesman") {
											tempSalesman = new salesman(tempName, tempSalary);
											yards[currentSalesyard].addStaff(tempSalesman);
										} else {
											tempStaff = new staff(tempName, tempSalary, tempJobTitle);
											yards[currentSalesyard].addStaff(tempStaff);
										}
										break;
									case '6':
										if (yards[currentSalesyard].getNumWorkers()>0) {
											std::cout << "Select the staff member you would like to fire" << std::endl;
											for (i=0;i<yards[currentSalesyard].getNumWorkers();i++) {
												std::cout << i<< " - " << yards[currentSalesyard].getWorkers()[i]->getName() << std::endl;
											}
											std::cin >> currentSalesman;
											if (currentSalesman < yards[currentSalesyard].getNumWorkers() && currentSalesman >= 0) {
												yards[currentSalesyard].removeStaff(currentSalesman);
											} else {
												std::cout << "That is not a valid selection" << std::endl;
											}
										} else {
											std::cout << "You don't have any staff to fire" << std::endl;
										}
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
	}	
}

