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
#include <sstream>

int main (void) {
	//Default initialisers for boolean variables
	bool run = true, salesyardSelected = true, vehicleSelected = true, returnToMenu = true, returnToSalesyardMenu = true, cont;
	char userInput;
	
	//Initialisng an array of salesyards
	int numSalesyards = 0, maxSalesyards = 5;
	salesyard *yards;                                            
	yards = new salesyard[maxSalesyards];
	std::string inputBuffer;
	char errorTest;

	//Temporary variables that will be used when adding vehicles to the salesyard array
	std::string tempName;
	int tempCapacity;
	std::string tempRego;

	int currentSalesyard; //Index of current salesyard in yards array
	int currentVehicle; //Index of current vehicle in current salesyard
	int currentSalesman; //Index of current salesman
	int i;

	//Temporary variables that are implemented in seeting the statuses in the vehicle class
	std::string tempMake;
	std::string tempModel;
	int tempYear;
	int tempPrice;
	std::string tempBodyType;
	int tempSalary;
	std::string tempJobTitle;

	//Initialising an array of vehicles(superclass) and subclasses bike, van, truck, coupe.
	vehicle *tempVehicle;
	bike *tempBike;
	van *tempVan;
	truck *tempTruck;
	coupe *tempCoupe;

	//Initialising default values for special variable relating to specific sublcasses
	int tempTowing;
	int tempStorage;
	char tempHelmet = 'c';
	int tempPerformance;

	//Initialisng an array of staff(superclass)
	staff *tempStaff;

	//Initialising an array of 
	salesman *tempSalesman;

	std::cout << "\nWelcome to the Car Salesyard database v 1.0.0" << std::endl;

	//While loop that the program is contained within, terminates if run == false
	while(run==true) {

		std::cout << "\n~~~~~~Menu~~~~~~\n\n0 - Exit\n1 - Create new Salesyard\n2 - Select Salesyard\n" << std::endl;
		std::cin.get(userInput);

		//Top level of the program, primarily based around creating and viewing salesyards
		switch (userInput) {
			case '0':
				run=false;
				break;
			case '1': //Case for adding salesyards
				if (numSalesyards<maxSalesyards) {
					std::cout << "What would you like to name your salesyard?: "; //Prompt for naming added salesyard
					std::cin.ignore();
					std::getline(std::cin, tempName);

					std::cout << "How many vehicles can '" << tempName << "' hold?: ";

					//While loop that will determine wheter or not an input was invalid and will also set the size of the specific salesyard array
					while(std::getline(std::cin, inputBuffer)) {   //Input buffer which will filter out the newline (\n) character
						std::stringstream linestream(inputBuffer);
						if(!(linestream >> tempCapacity) ||linestream >> errorTest) {
							std::cout << "That was an invalid input. Enter how many vehicles '" << tempName << "' can hold: " << std::endl;
							continue;
						}
						break;
					}
					//Setters that will set variables specific to new salesyard to temp variables from the above inputs
					yards[numSalesyards].setName(tempName);
					yards[numSalesyards].setCapacity(tempCapacity);
					yards[numSalesyards].resetYard();
					numSalesyards++;
				} else { //Prints if the maximum ammount of salesyards has been reached and the user tries to add more
					std::cout << "Sorry you have already have " << numSalesyards << " salesyards, the max amount of salesyards allowed" << std::endl;
				}	
				break;
			case '2': //Case for selecting salesyards
				returnToMenu=false;
				if (numSalesyards==0) {
					std::cout << "You have not yet created any salesyards" << std::endl; //Output when user tried to select a yard without having created at least one
				} else {
					std::cout << "You currently have the following salesyards" << std::endl;
					for (i=0; i<numSalesyards; i++) {
						std::cout << i << " - " << yards[i].getName() << std::endl; //For loop which will list the salesyards in the salesyard array initialised previously
					}
					while (returnToMenu==false) {
						std::cin >> currentSalesyard;

						if (currentSalesyard < numSalesyards && currentSalesyard >= 0) {

							salesyardSelected=true;
							std::cin.get();
							
							//Second level of the progroam, based primarily around managing salesyard content, adding staff and deleting salesyards.
							while (salesyardSelected==true) {
								std::cout << "\n~~~~~~'" << yards[currentSalesyard].getName() << "' Menu~~~~~~\n0 - Return to Menu\n1 - View Vehicles\n2 - Add Vehicle\n3 - Sell Vehicle\n4 - View Staff\n5 - Hire Staff\n6 - Fire Staff\n7 - Delete Salesyard" << std::endl;
								while(std::getline(std::cin, inputBuffer)) {
									std::stringstream linestream(inputBuffer);
									userInput='~';
									if(!(linestream >> userInput)) {
										continue;
									}
									break;
								}

								switch (userInput) {
									case '0': //Case for returning to the top level of the program, sets returnToMenu to true
										salesyardSelected=false;
										returnToMenu=true;
										break;
									case '1': //Case for viewing vehicles that have previously been added.
										returnToSalesyardMenu=false;
										if (yards[currentSalesyard].getNumVehicles()>0) { //Calls the getNumVehicles function and lists the current vehicles within the yard
											std::cout << "Select the vehicle you would like to view" << std::endl;
											std::cout << "0 - Return to Salesyard Menu" << std::endl;
											for (i=0;i<yards[currentSalesyard].getNumVehicles();i++) {
												std::cout << i+1<< " - " << yards[currentSalesyard].getYard()[i]->getYear() << " " << yards[currentSalesyard].getYard()[i]->getMake() << " " << yards[currentSalesyard].getYard()[i]->getModel() << std::endl;
											}
											while (returnToSalesyardMenu==false) {
												while(std::getline(std::cin, inputBuffer)) {
													std::stringstream linestream(inputBuffer); //Another buffer which filters out invalid unput
													if(!(linestream >> currentVehicle)) {
														std::cout << "That was an invalid input" << std::endl;
														continue;
													}
													break;
												}
												currentVehicle--;
												if (currentVehicle == -1) {   //This loop will return the user to the salesyard menu once all of the vehicles within the salesyard have been listed
													returnToSalesyardMenu=true;
													break;
												} else if (currentVehicle < yards[currentSalesyard].getNumVehicles() && currentVehicle >= 0) {
													std::cout << "You have selected the '" << yards[currentSalesyard].getYard()[currentVehicle]->getYear() << " " << yards[currentSalesyard].getYard()[currentVehicle]->getMake() << " " << yards[currentSalesyard].getYard()[currentVehicle]->getModel() << "'" << std::endl << "What would you like to do?" << std::endl;
													vehicleSelected=true;  //This elseif statement will set vehicleSelected to true if the user inputs a valid number from the list of vehicles

													while (vehicleSelected==true) {
														std::cout << "0 - Return\n1 - View All Details\n2 - Change Registration\n"; //This while loop works when vehicleSelected == true
														while(std::getline(std::cin, inputBuffer)) {								//Lists further options available to the user after selecting the vehicle
															std::stringstream linestream(inputBuffer);
															if(!(linestream >> userInput)) {
																	std::cout << "That was an invalid input" << std::endl;
																continue;
															}
															break;
														}

														switch (userInput) {
															case '0': //Case for returning the user back to the salesyard menue after they have selected a vehicle
																vehicleSelected=false;
																returnToSalesyardMenu=true;
																
																break;
															case '1': //Case for selecting "View all details", will list all of the status data available for that specific vehicle
																std::cout << "Manufacturing Year: " << yards[currentSalesyard].getYard()[currentVehicle]->getYear() << std::endl;
																std::cout << "Purchase Price: " << yards[currentSalesyard].getYard()[currentVehicle]->getPrice() << std::endl;
																std::cout << "Registration: " << yards[currentSalesyard].getYard()[currentVehicle]->getRegistration() << std::endl; 
																std::cout << "Make: " << yards[currentSalesyard].getYard()[currentVehicle]->getMake() << std::endl;
																std::cout << "Model: " << yards[currentSalesyard].getYard()[currentVehicle]->getModel() << std::endl;
																std::cout << "Number of Wheels: " << yards[currentSalesyard].getYard()[currentVehicle]->getNumWheels() << std::endl;
																std::cout << "Number of Seats: " << yards[currentSalesyard].getYard()[currentVehicle]->getNumSeats() << std::endl;
																std::cout << "Body Type: " << yards[currentSalesyard].getYard()[currentVehicle]->getBody_type() << std::endl;
																
																//Series of if statements that will check if the selected vehicle matches one of the vehicle subclasses
																if (yards[currentSalesyard].getYard()[currentVehicle]->getBody_type()=="Truck") { 
																	std::cout << "~~~~~Truck Specific Details~~~~~" << std::endl;    //Lists details specific to the truck subclass
																	tempTruck = static_cast<truck *>(yards[currentSalesyard].getYard()[currentVehicle]);
																	std::cout << "Towing Capacity (kg): " << tempTruck->getTowingCap() << std::endl;

																} else if (yards[currentSalesyard].getYard()[currentVehicle]->getBody_type()=="Van") {
																	std::cout << "~~~~~Van specific Details~~~~~" << std::endl;    //Lists details specific to the van subclass
																	tempVan = static_cast<van *>(yards[currentSalesyard].getYard()[currentVehicle]);
																	std::cout << "Storing Capacity (cubic metres): " << tempVan->getStorageSpace() << std::endl;
	
																} else if (yards[currentSalesyard].getYard()[currentVehicle]->getBody_type()=="Bike") {
																	std::cout << "~~~~~Bike specific Details~~~~~" << std::endl;    //Lists details specific to the bike subclass
																	tempBike= static_cast<bike *>(yards[currentSalesyard].getYard()[currentVehicle]);
																	std::cout << "Helmet: " << std::endl;
																	if (tempBike->getHelmet()==true) {    //Checks if the bike includes a helmet or not and gives the respective output
																		std::cout << "Included" << std::endl;
																	} else {
																		std::cout << "Not Included" << std::endl;
																	}

																} else if (yards[currentSalesyard].getYard()[currentVehicle]->getBody_type()=="Coupe") {
																	std::cout << "~~~~~Coupe specific Details~~~~~" << std::endl;    //Lists details specific to the coupe subclass
																	tempCoupe = static_cast<coupe *>(yards[currentSalesyard].getYard()[currentVehicle]);
																	std::cout << "Performance (kWh): " << tempCoupe->getPerformance() << std::endl;	

																}
																
																break;
															case '2':  //Case for replacing the registration number of the selected vehicle
																std::cout << "Enter New Registration: " << std::endl;
																std::cin.get();
																std::getline(std::cin, tempRego);
																yards[currentSalesyard].getYard()[currentVehicle]->setRegistration(tempRego); //Calls the setRegistration funciton to replace the registration
																break;
															case '\n':
																break;
															default:   //Default case for invalid inputs
																std::cout << "That is an invalid input" << std::endl;
														}
													}
												} else {
													std::cout << "That is an invalid input" << std::endl;
												}
											}
										} else {
											std::cout << "Sorry this salesyard is empty" << std::endl; //Output if the user tries to view vehicles in a salesyard is empty
										}
										break;
									case '2': //Case for adding vehicles to selected salesyard
										std::cout << "Please enter the vehicle registration: " << std::endl; //Prompts user to enter registration into tempRego variable
										std::cin.ignore();
										while(std::getline(std::cin, inputBuffer)) {
											std::stringstream linestream(inputBuffer);
											if(!(linestream >> tempRego)) {
												std::cout << "That was an invalid input. Enter the vehicle's registration" << std::endl;
												continue;
											}
											break;
										}

										std:: cout << "Please enter the vehicle badge: " << std::endl; //Prompts user to enter vehicle badge into tempMake variable
										while(std::getline(std::cin, inputBuffer)) {
											std::stringstream linestream(inputBuffer);
											if(!(linestream >> tempMake)) {
												std::cout << "That was an invalid input. Enter the vehicle's badge" << std::endl;
												continue;
											}
											break;
										}
										
										std::cout << "Please enter the vehicle model: " << std::endl; //Prompts user to enter vehicle model into tempModel variable
										while(std::getline(std::cin, inputBuffer)) {
											std::stringstream linestream(inputBuffer);
											if(!(linestream >> tempModel)) {
												std::cout << "That was an invalid input. Enter the vehicle's model" << std::endl;
												continue;
											}
											break;
										}

										std::cout << "Please enter the year of manufacture: " << std::endl; //Prompts user to enter vehicle year of manufacture into tempYear variable
										while(std::getline(std::cin, inputBuffer)) {
											std::stringstream linestream(inputBuffer);
											if(!(linestream >> tempYear) || linestream >> errorTest) {
												std::cout << "That was an invalid input. Enter the vehicle's year of manufacture" << std::endl;
												continue;
											}
											break;
										}
										
										std::cout << "Please enter the purchase price of the vehicle: " << std::endl; //Prompts user to enter vehicle purchase price into tempPrice variable
										while(std::getline(std::cin, inputBuffer)) {
											std::stringstream linestream(inputBuffer);
											if(!(linestream >> tempPrice) ||linestream >> errorTest) {
												std::cout << "That was an invalid input. Enter the vehicle's purchase price" << std::endl;
												continue;
											}
											if(tempPrice<0) {
												std::cout << "Sorry, the price must be positive" << std::endl; //Output if the user tries to enter a negative price 
												continue;
											}
											break;
										}

										std::cout << "Please enter the vehicle body type (Truck, Van, Bike, Coupe, etc.):" << std::endl; //Prompts user to enter vehicle body type into tempBodyType
										while(std::getline(std::cin, inputBuffer)) {
											std::stringstream linestream(inputBuffer);
											if(!(linestream >> tempBodyType)) {
												std::cout << "That was an invalid input. Enter the vehicle's body type" << std::endl;
												continue;
											}
											break;
										}
										//This series of if conditionals will check to see if user input for body types will match a pre-defined vehicle subclass
										//The temp values that are storing data from user input will be input for specific vehicle subclass initalisers
										if (tempBodyType=="Truck" || tempBodyType=="truck") {  //If the input does match, program asks for input for a specific status variable input relating to that subclass
											std::cout << "Please enter the towing capacity of this truck in kg" << std::endl;  // Towing capacity is unique to truck class
											while(std::getline(std::cin, inputBuffer)) {
												std::stringstream linestream(inputBuffer);
												if(!(linestream >> tempTowing) || linestream >> errorTest) {
													std::cout << "That was an invalid input. Enter the vehicle's towing capcity" << std::endl;
													continue;
												}
												break;
											}	

											tempTruck=new truck(tempRego, tempMake, tempModel, tempYear, tempPrice, tempTowing); //Initialiser for the truck type subclass

											if (!yards[currentSalesyard].addVehicle(tempTruck)) {   //Uses a vehicle function to add the subclass into the superclass array
												std::cout << "Sorry the salesyard is full" << std::endl;
											} else {
												std::cout << "Truck added successfully" << std::endl;  //Adds truck if salesyard isnt full
											}

										} else if (tempBodyType=="Van" || tempBodyType=="van") {
											std::cout << "Please enter the storage capacity of this van in cubic metres" << std::endl; //Storage capacity is unique to van class
											while(std::getline(std::cin, inputBuffer)) {
												std::stringstream linestream(inputBuffer);
												if(!(linestream >> tempStorage) || linestream >> errorTest) {
													std::cout << "That was an invalid input. Enter the vehicle's storage capacity" << std::endl;
													continue;
												}
												break;
											}

											tempVan=new van(tempRego, tempMake, tempBodyType, tempYear, tempPrice, tempStorage); //Initialiser for van subclass

											if (!yards[currentSalesyard].addVehicle(tempVan)) { 
												std::cout << "Sorry the salesyard is full" << std::endl;
											} else {
												std::cout << "Van added successfully" << std::endl;  //Adds van if salesyard isnt full
											}
										} else if (tempBodyType=="Bike" || tempBodyType=="bike") {
											std::cout << "Is this bike sold with a helmet? (y/n): " << std::endl;  //If user input matches the bike subclass, prompts user for input regarding inclusion of helmet
											cont =true;
											while (cont) {
												std::cin.get(tempHelmet);
												if (tempHelmet=='y') {     //If user input is 'y', sets the includeHelmet boolean variabile in the bike initialiser to true
													tempBike=new bike(tempRego, tempMake, tempModel, tempYear, tempPrice, true);
													cont = false;
												} else if (tempHelmet=='n') { 		//If user input is 'n', sets the includeHelmet boolean variabile in the bike initialiser to false
													tempBike=new bike(tempRego, tempMake, tempModel, tempYear, tempPrice, false);
													cont = false;
												} else {
													cont = true;
													std::cout << "Invalid input. Is this bike sold with a helmet? (y/n): " << std::endl;
												}
											}
											if (!yards[currentSalesyard].addVehicle(tempBike)) {  
													std::cout << "Sorry the salesyard is full" << std::endl;
											} else {
													std::cout << "Bike added successfully" << std::endl;  //Adds bike if salesyard isnt full
											}
											std::cin.ignore();
										} else if (tempBodyType=="Coupe"||tempBodyType=="coupe") {
											std::cout << "Please enter the performance of this car in kW: " << std::endl;  //Performance is unique to coupe class
											while(std::getline(std::cin, inputBuffer)) {
												std::stringstream linestream(inputBuffer);
												if(!(linestream >> tempPerformance) || linestream >> errorTest) {
													std::cout << "That was an invalid input. Enter the vehicle's performance" << std::endl;
													continue;
												}
												break;
											}

											tempCoupe=new coupe(tempRego, tempMake, tempModel, tempYear, tempPrice, tempPerformance);  //Initialiser for coupe subclass 

											if (!yards[currentSalesyard].addVehicle(tempCoupe)) {
												std::cout << "Sorry the salesyard is full" << std::endl;
											} else {
												std::cout << "Coupe added successfully" << std::endl;  //Adds coupe if salesyard is empty
											}
											
										} else {
											tempVehicle=new vehicle(tempRego, tempMake, tempModel, tempBodyType, tempYear, tempPrice);  //Default vehicles initialiser, this is called if the user
																																		//input for body type does not match any of the subclasses
											if (!yards[currentSalesyard].addVehicle(tempVehicle)) {
												std::cout << "Sorry the salesyard is full" << std::endl;
											} else {
												std::cout << "Car added successfully" << std::endl;
											}
										}
										break;
									case '3':  //Case for selling a vehicle that is in the users selected salesyard
										if (yards[currentSalesyard].getNumVehicles()>0 && yards[currentSalesyard].getNumWorkers()>0) {
											std::cout << "Select the vehicle you would like to sell" << std::endl; //If conditional that checks if the salesyard contains at least one vehicle and one employee
											//For loop which will list all vehicles in the yard for the user to choose and sell
											for (i=0;i<yards[currentSalesyard].getNumVehicles();i++) {
												std::cout << i << " - " << yards[currentSalesyard].getYard()[i]->getYear() << " " << yards[currentSalesyard].getYard()[i]->getMake() << " " << yards[currentSalesyard].getYard()[i]->getModel() << std::endl;
											}
											while(std::getline(std::cin, inputBuffer)) {
												std::stringstream linestream(inputBuffer);
												if (linestream=="\n") {
													continue;
												} else if(!(linestream >> currentVehicle) || linestream >> errorTest || currentVehicle >= yards[currentSalesyard].getNumVehicles() || currentVehicle < 0) {
													std::cout << "That wa an invalid input" << std::endl;
													continue;
												}
												break;
											}
											//After selecting the vehicle, prompts user to select the salesman employee which is selling the vehicle
											std::cout << "Which Salesman is selling the '" << yards[currentSalesyard].getYard()[currentVehicle]->getYear() << " " << yards[currentSalesyard].getYard()[currentVehicle]->getMake() << " " << yards[currentSalesyard].getYard()[currentVehicle]->getModel() << "'" << std::endl;
											//For loop which lists the employees available to sell the previouslt selected vehicle.
											for (i=0;i<yards[currentSalesyard].getNumWorkers();i++) {
												std::cout << i << " - " << yards[currentSalesyard].getWorkers()[i]->getName() << std::endl;
											}
												
											while(std::getline(std::cin, inputBuffer)) {
												std::stringstream linestream(inputBuffer);
												if(!(linestream >> currentSalesman) || linestream >> errorTest || currentSalesman < 0 || currentSalesman >= yards[currentSalesyard].getNumWorkers()) {
													std::cout << "That was an invalid input" << std::endl;
													continue;
												}
												break;
											}
											//This for loop checks how much the selected vhicle was bought for and how much it is being sold for
											if (yards[currentSalesyard].getWorkers()[currentSalesman]->getJobTitle() == "Salesman") {  //If conditional which checks if the selected worker is of the 'salesman' subclass
												std::cout << "This car was bought for $" << yards[currentSalesyard].getYard()[currentVehicle]->getPrice() << " .How much was it sold for?" << std::endl;
												std::cin >> tempPrice;
												tempSalesman = static_cast<salesman *>(yards[currentSalesyard].getWorkers()[currentSalesman]);  //Gets a salesman from an array of pointers to staff, tells the 
												yards[currentSalesyard].sellVehicle(currentVehicle, tempSalesman, tempPrice);					//program/computer that salesman is not generic staff type 
												std::cout << "Car successfully sold" << std::endl;
											} else {
												std::cout << "Sorry, " << yards[currentSalesyard].getWorkers()[currentSalesman]->getName() << " can't sell cars" << std::endl; //If the staff member is not a salesman class, disallows car from being sold
											}

											
										} else {
											if (yards[currentSalesyard].getNumVehicles()>0) {
												std::cout << "Sorry, you don't have any staff available to sell cars" << std::endl; //Output if no staff employed at the selected salesyard
											} else if (yards[currentSalesyard].getNumWorkers()>0) {
												std::cout << "Sorry, you don't have any cars available to be sold" << std::endl; //Output if salesyard contains staff bu tno vehicles
											} else {
												std::cout << "Sorry, you don't have any cars or staff" << std::endl;  //Output for all other cases
											}
										}
										break;
									case '4':  //Case for viewing staff members in currently selected salesyard
										returnToSalesyardMenu=false;
										if (yards[currentSalesyard].getNumWorkers()>0) {
											std::cout << "Select the staff member you would like to view" << std::endl; //Prompts user to select a specific staff member
											std::cout << "0 - Return to Salesyard Menu" << std::endl;
											for (i=0;i<yards[currentSalesyard].getNumWorkers();i++) {
												std::cout << i+1<< " - " << yards[currentSalesyard].getWorkers()[i]->getName() << std::endl; //Lists all staff members available for selection
											}
											while (returnToSalesyardMenu==false) {
												std::cin >> currentSalesman;
												currentSalesman--;

												if (currentSalesman < yards[currentSalesyard].getNumWorkers() && currentSalesman >= 0) {
													std::cout << "Name: " << yards[currentSalesyard].getWorkers()[currentSalesman]->getName() << "\nSalary: $" << yards[currentSalesyard].getWorkers()[currentSalesman]->getSalary()  << "\nJob Title:"  << yards[currentSalesyard].getWorkers()[currentSalesman]->getJobTitle() << std::endl;
													if (yards[currentSalesyard].getWorkers()[currentSalesman]->getJobTitle()=="Salesman") {
														tempSalesman = static_cast<salesman *>(yards[currentSalesyard].getWorkers()[currentSalesman]);   //Similar type cast as previously seen but is implemented to see how many cars sold and profit made
														std::cout << "Cars Sold: " << tempSalesman->getNumCarsSold() << "\nProfit: $" << tempSalesman->getProfit() << std::endl;
													}
													returnToSalesyardMenu=true;  //Returns back to salesyard menu after listing workers
													std::cin.get();  
												} else if (currentSalesman==-1) {
													returnToSalesyardMenu=true;
													break;
												}
											}
										} else {
											std::cout << "Sorry this salesyard does not have any staff" << std::endl;
										}
										break;
									case '5':  //Case for adding staff members, this is done in the same manner as adding vehicles; storing input in temp values and then using temp values in staff member initialiser
										std::cout << "Please enter the Staff's salary: " << std::endl;
										std::cin >> tempSalary;
										std::cin.ignore();
										std::cout << "Please enter the Staff's name: " << std::endl;
										std::getline(std::cin, tempName);
										std::cout << "Please enter the Staff's job title (Salesman, etc.): " << std::endl;
										std::getline(std::cin, tempJobTitle);
										if (tempJobTitle == "Salesman") {     //Checks to see if the job title input matches the salesman subclass and assigns salesman-specific status variables to employee
											tempSalesman = new salesman(tempName, tempSalary);
											yards[currentSalesyard].addStaff(tempSalesman);    //Adds salesman to the current salesyard 
										} else {
											tempStaff = new staff(tempName, tempSalary, tempJobTitle); //Adds stuff member with unique job title that doesnt match salesman subclass to current salesyard
											yards[currentSalesyard].addStaff(tempStaff);
										}
										break;
									case '6':  //Case for firing staff members 
										if (yards[currentSalesyard].getNumWorkers()>0) {  //Checks if there are any staff members in the currently selected salesyard
											std::cout << "Select the staff member you would like to fire" << std::endl;
											for (i=0;i<yards[currentSalesyard].getNumWorkers();i++) {
												std::cout << i<< " - " << yards[currentSalesyard].getWorkers()[i]->getName() << std::endl; //Lists available staff members to fire
											}
											std::cin >> currentSalesman;  //Takes input to be array index of the selected stuff member
											if (currentSalesman < yards[currentSalesyard].getNumWorkers() && currentSalesman >= 0) {  //If conditional that ensure user is not trying to index beyond the yards array
												yards[currentSalesyard].removeStaff(currentSalesman);
											} else {
												std::cout << "That is not a valid selection" << std::endl;
											}
										} else {
											std::cout << "You don't have any staff to fire" << std::endl; //Output if there is no staff to fire
										}
										break;
									case '7':  //Case for deleting a salesyard
										yards[currentSalesyard]=yards[numSalesyards-1];  //Sets index of selected sales yard to that of the number of salesyards -1
										numSalesyards--; //Removes one from the number of salesyards
										salesyardSelected=false; //Deslects current salesyard
										returnToMenu=true;  //Breaks switch case
										break;
									case '\n': //Breaks switch statement incase of newline input
										break;
									default:
										std::cout << "That is an invalid input" << std::endl;  //Below are the default cases for all of the aboe switch statements pertaining to invalid unput
								}
							}
							break;

						} else {
							std::cout << "That is not a valid selection" << std::endl;
						}
					}
				}
				break;
			case '\n':
				break;
			default:
				std::cout << "That is an invalid input" << std::endl;
		}
	}	
}

