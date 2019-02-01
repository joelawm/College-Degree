#
# PROGRAM:    assign2
# PROGRAMMER: Joe Meyer
# LOGON ID:   z1788150
# DATE DUE:   2/7/2018
#

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assign2: assign2.o
	g++ $(CCFLAGS) -o assign2 assign2.o

# Rules to compile source code file to object code
assign2.o: assign2.cpp
	g++ $(CCFLAGS) -c assign2.cpp

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign2
