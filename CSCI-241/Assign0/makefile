#
#Program:	Lab Trainning Exercise
#Programer: 	Joe Meyer
#

CC = g++
CCFLAGS= -Wall -std=c++11
labtrain: labtrain.o
	$(CC) $(CCFLAGS) -o labtrain labtrain.o
labtrain.o: labtrain.cpp
	$(CC) $(CCFLAGS) -c labtrain.cpp
clean:
	- rm *.o labtrain
