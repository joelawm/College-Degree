#ifndef PROVIDERDB_H
#define PROVIDERDB_H
#include "Provider.h"
//*****************************************************************
// FILE:      ProviderDB.h
// AUTHOR:    Joe Meyer
// LOGON ID:  z1788150
// DUE DATE:  10/10/17
// 
// PURPOSE:   Declaration for the ProviderDB class, which represents 
//            information about a health care provider.
//*****************************************************************

class ProviderDB
  {
  		// Data members and method prototypes for the Provider class go here
  		//Private Data Memebers for the assingment
  		Provider StoredObj[40];
  		int AmountStored = 0;
  		
  		public:
			//Method Prototypes for the assignment
			ProviderDB(const char*);
			ProviderDB();
			void print() const;
			void sortByProviderNumber();
			void sortBySpeciality();
			void sortByName();
			void processTransactions(const char*);
			int searchForProviderNumber(const char*);
  };
#endif
