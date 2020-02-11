#
#Program:	Assign 1
#Programer: 	Joe Meyer
#

CC = g++
CCFLAGS= -Wall -std=c++11
assign1: assign1.o
	$(CC) $(CCFLAGS) -o assign1 assign1.o
assign1.o: assign1.cpp
	$(CC) $(CCFLAGS) -c assign1.cpp
clean:
	- rm *.o assign1
