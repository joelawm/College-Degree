#
# PROGRAM:    assignment4
# PROGRAMMER: Joe Meyer
# LOGON ID:   z1788150
# DATE DUE:   2/22/18
#

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assignment4: assignment4.o
	g++ $(CCFLAGS) -o assignment4 assignment4.o

# Rules to compile source code file to object code
assignment4.o: assignment4.cpp assignment4.h
	g++ $(CCFLAGS) -c assignment4.cpp

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assignment4
