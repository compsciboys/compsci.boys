main: main.cpp salesyard.cpp staff.cpp vehicle.cpp salesman.cpp
	g++ -Wall -g -o main staff.cpp vehicle.cpp salesman.cpp salesyard.cpp main.cpp 

#main: main.o salesyard.o staff.o vehicle.o manager.o salesman.o 
#	g++ -Wall -g -o main main.o salesyard.o staff.o vehicle.o manager.o salesman.o  

#main.o: main.cpp salesyard.cpp staff.cpp vehicle.cpp manager.cpp salesman.cpp
#	g++ -Wall -g -c main.cpp

#salesyard.o: salesyard
