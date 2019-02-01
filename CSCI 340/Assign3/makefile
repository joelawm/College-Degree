#
# PROGRAM:    assignement3
# PROGRAMMER: Joe Meyer
# LOGON ID:   z1788150
# DATE DUE:   2/13/18
#

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assignement3: assignement3.o
	g++ $(CCFLAGS) -o assignement3 assignement3.o

# Rules to compile source code file to object code
assignement3.o: assignement3.cpp
	g++ $(CCFLAGS) -c assignement3.cpp

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assignement3
