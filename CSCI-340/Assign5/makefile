#
# PROGRAM:    assignment5
# PROGRAMMER: Joe Meyer
# LOGON ID:   z1788150
# DATE DUE:   3/9/18
#

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assignment5: assignment5.o
	g++ $(CCFLAGS) -o assignment5 assignment5.o

# Rules to compile source code file to object code
assignment5.o: assignment5.cpp assignment5.h
	g++ $(CCFLAGS) -c assignment5.cpp

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assignment5
