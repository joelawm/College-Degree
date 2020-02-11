#
#Program:	Assign 2
#Programer: 	Joe Meyer
#

CC = g++
CCFLAGS= -Wall -std=c++11
assign2: assign2.o
	$(CC) $(CCFLAGS) -o assign2 assign2.o
assign2.o: assign2.cpp
	$(CC) $(CCFLAGS) -c assign2.cpp
clean:
	- rm *.o assign2
