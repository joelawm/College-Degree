#
# PROGRAM:    assign3
# PROGRAMMER: Joe Meyer
# LOGON ID:   z1788150
# DATE DUE:   10/10/17
#

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assign3: assign3.o Provider.o ProviderDB.o
	g++ $(CCFLAGS) -o assign3 assign3.o Provider.o ProviderDB.o

# Rules to compile source code file to object code
assign3.o: assign3.cpp ProviderDB.h
	g++ $(CCFLAGS) -c assign3.cpp

Provider.o: Provider.cpp Provider.h
	g++ $(CCFLAGS) -c Provider.cpp

ProviderDB.o: ProviderDB.cpp ProviderDB.h
	g++ $(CCFLAGS) -c ProviderDB.cpp

# Header file dependency
ProviderDB.h: Provider.h

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign3
