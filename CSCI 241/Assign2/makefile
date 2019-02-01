#
# PROGRAM:    assign2
# PROGRAMMER: Joe Meyer
# LOGON ID:   z1788150
# DATE DUE:   9/25/17
#

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assign2: assign2.o Provider.o ProviderDB.o
	g++ $(CCFLAGS) -o assign2 assign2.o Provider.o ProviderDB.o

# Rules to compile source code file to object code
assign2.o: assign2.cpp ProviderDB.h
	g++ $(CCFLAGS) -c assign2.cpp

Provider.o: Provider.cpp Provider.h
	g++ $(CCFLAGS) -c Provider.cpp

ProviderDB.o: ProviderDB.cpp ProviderDB.h
	g++ $(CCFLAGS) -c ProviderDB.cpp

# Header file dependency
ProviderDB.h: Provider.h

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign2
