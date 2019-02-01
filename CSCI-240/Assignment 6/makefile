#
# PROGRAM:    assign6
# PROGRAMMER: Joe Meyer
# LOGON ID:   z1788150
# DATE DUE:   11/9/17
#

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assign5: assign6.o Queue.o
	g++ $(CCFLAGS) -o assign6 assign6.o Queue.o

# Rules to compile source code file to object code
assign5.o: assign6.cpp Queue.h
	g++ $(CCFLAGS) -c assign6.cpp

Stack.o: Queue.cpp Queue.h
	g++ $(CCFLAGS) -c Queue.cpp

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign6
