#
# PROGRAM:    assign6
# PROGRAMMER: Joe Meyer
# LOGON ID:   z1788150
# DATE DUE:   11/9/17
#

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assign6: assign6.o
	g++ $(CCFLAGS) -o assign6 Queue.o assign6.o

# Rules to compile source code file to object code
assign6.o: assign6.cpp Queue.h
	g++ $(CCFLAGS) -c assign6.cpp

# Rule to link object code files to create executable file
assign6: assign6.o
	g++ $(CCFLAGS) -o assign6 assign6.o

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign6
